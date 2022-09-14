#include "mainwindow.h"

#include "qlabel.h"
#include "styledtextzone.h"
#include <qstring.h>
#include "typingzone.h"
#include <QVBoxLayout>
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
}

void StyledTextZone::onUserTyped() {
	styledText_->setText(text_ + "\nUserTyped:" + tZone_->toPlainText());
}