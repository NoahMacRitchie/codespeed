#include "typingZone.h"

TypingZone::TypingZone(QWidget* parent) : QPlainTextEdit(parent)
{


}
void TypingZone::onBadCharsChanged(bool badCharsExist)
{
	allowBackspace_ = badCharsExist;
}
void TypingZone::onNewText() {
	// Clear Text Box
	setPlainText("");
}
 
void TypingZone::deleteLastChar() {
	blockSignals(true);
	textCursor().deletePreviousChar();
	blockSignals(false);
}
void TypingZone::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Backspace) {
		
		if (allowBackspace_) {
			deleteLastChar();
			emit removeBadChar();
		}
	}
	else {
		QPlainTextEdit::keyPressEvent(e);
	}
}