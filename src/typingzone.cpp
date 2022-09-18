// Local Includes
#include "typingZone.h"

TypingZone::TypingZone(QWidget* parent) : QPlainTextEdit(parent)
{
	setUndoRedoEnabled(false);

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
	auto key = e->key();
	switch (key) {
		case(Qt::Key_Backspace):
			if (allowBackspace_) {
				deleteLastChar();
				emit removeBadChar();
				break;
			}
		case(Qt::Key_Up):
		case(Qt::Key_Down):
		case(Qt::Key_Left):
		case(Qt::Key_Right):
		case(Qt::CTRL):
		case(Qt::Key_Control):
			break;
		default:
			QPlainTextEdit::keyPressEvent(e);
	}
}

void TypingZone::mousePressEvent(QMouseEvent* e)
{} 
