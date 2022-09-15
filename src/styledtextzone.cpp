#include "mainwindow.h"
#include "qlabel.h"
#include "styledtextzone.h"
#include <qstring.h>
#include "typingzone.h"
#include <QVBoxLayout>
#include <QElapsedTimer>

StyledTextZone::StyledTextZone(QWidget* parent, TypingZone& tZone) : QWidget(parent), tZone_(&tZone), styledText_(new QLabel(this))
{
	auto lay = new QVBoxLayout(this);
	lay->addWidget(styledText_);

	setLayout(lay);
};

QString StyledTextZone::getText() const{
	return text_;
}

void StyledTextZone::setText(QString& text) {
	text_ = text;
	styledText_->setText(text);
	
	QString reversedText = text;
	std::reverse(reversedText.begin(), reversedText.end());
	for (const QChar& c: reversedText) {
		textToType_.push(c);
	}

	emit onNewText();
}

void StyledTextZone::onUserTyped() {
	QString uText = tZone_->toPlainText();
	if (uText.isEmpty()) return;

	int uTextLen = uText.length();
	if (!textToType_.isEmpty()) {
		if (uText.at(uTextLen-1) != textToType_.top()) {
			badChars_.push(uText.at(uTextLen-1));
			emit badCharsChanged(!badChars_.isEmpty());
			updateStyle();
		}
		else {
			textToType_.pop();
			updateStyle();
			if (textToType_.isEmpty()) {
				emit finished();
			}
		}
	}
}

void StyledTextZone::removeBadChar() {
	if (badChars_.isEmpty()) return;
	badChars_.pop();

	updateStyle();

	emit badCharsChanged(!badChars_.isEmpty());
}

void StyledTextZone::updateStyle() {

    styledText_->setStyleSheet("QLabel b { background-color : green; }");

	const int numCorrectChars = text_.length() - textToType_.size();
	const int numBadChars = badChars_.size();
	const int numChars = text_.length();

	QString correctText = text_.first(numCorrectChars);
	QString badText = (text_.first(numBadChars + numCorrectChars)).last(numBadChars);
	QString normalText = text_.last(numChars - (numCorrectChars + numBadChars));
	QString coloredText = "<span style=\"background-color:green;\">" + correctText + "</span>" + "<span style=\"background-color:red;\">" + badText + "</span>" + normalText;

	styledText_->setText(coloredText);
}
