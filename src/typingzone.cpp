#include "typingZone.h"

TypingZone::TypingZone(QWidget* parent) : QPlainTextEdit(parent)
{


}
void TypingZone::onNewText() {
	// Clear Text Box
	setPlainText("");
}
 