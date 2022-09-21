// Local Includes
#include "mainwindow.h"
#include "typingzone.h"
#include "styledtextzone.h"

// Qt Includes
#include <QVBoxLayout>
#include <QLabel>
#include <QElapsedTimer>

StyledTextZone::StyledTextZone(QWidget* parent, TypingZone& tZone) : QLabel(parent), tZone_(&tZone)
{
};

QString StyledTextZone::getText() const{
	return masterText_;
}

void StyledTextZone::setNewText(QString& text) {
	masterText_ = text;
	QLabel::setText(text);
	textToType_.clear();
	badChars_.clear();
	mistakeChars_.clear();
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
		if ((uText.at(uTextLen-1) != textToType_.top()) || !badChars_.isEmpty()) {
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
	auto c = badChars_.pop();
	if (badChars_.isEmpty())
		mistakeChars_.append(c);
	updateStyle();

	emit badCharsChanged(!badChars_.isEmpty());
}

void StyledTextZone::updateStyle() {

    setStyleSheet("QLabel b { background-color : green; }");

	const int numCorrectChars = masterText_.length() - textToType_.size();
	const int numBadChars = badChars_.size();
	const int numChars = masterText_.length();

	QString correctText = masterText_.first(numCorrectChars);
	QString badText = (masterText_.first(numBadChars + numCorrectChars)).last(numBadChars);
	QString normalText = masterText_.last(numChars - (numCorrectChars + numBadChars));

	// This white - space: pre styling is magic and makes sure everything looks right
	QString coloredText = "<span style=\"white-space: pre;\"><span style=\"background-color: rgba(76,175,80,0.5);\" line-height=\"300\">" + correctText + "</span>" + "<span style=\"background-color:rgba(255,82,82, 0.5);\">" + badText + "</span>" + normalText + "</span>";

	setText(coloredText);
}


