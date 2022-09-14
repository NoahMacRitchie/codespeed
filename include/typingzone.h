#ifndef TYPINGZONE_H
#define TYPINGZONE_H

#include <qplaintextedit.h>

class TypingZone : public QPlainTextEdit
{
    Q_OBJECT

public:
    TypingZone(QWidget* parent);
public slots:
    void onNewText();
};
#endif 