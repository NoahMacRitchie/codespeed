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
	emit onNewText();
	
	for (int i = text.length(); i > 0; i--) {
		textToType_.push(text[i-1]);
		
	}
}

void StyledTextZone::onUserTyped() {
	styledText_->setText(text_ + "\nUserTyped:" + tZone_->toPlainText());
	QString uText_ = tZone_->toPlainText();
	int uTextLen_ = uText_.length();
	QChar topItem_ = textToType_.top();
	if (!textToType_.isEmpty()) {
		if (uText_[uTextLen_-1] != textToType_.top()) {
			styledText_->setStyleSheet("QLabel { background-color : red; color : blue; }");
			badChars_.push(uText_[uTextLen_ - 1]);
		}
		else {
			styledText_->setStyleSheet("QLabel { }");
			textToType_.pop();
		}
	}
}
