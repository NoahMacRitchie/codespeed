#ifndef TYPINGZONE_H
#define TYPINGZONE_H

#include <qplaintextedit.h>

class TypingZone : public QPlainTextEdit
{
    Q_OBJECT

public:
    TypingZone(QWidget* parent);
    void deleteLastChar();
signals:
    void removeBadChar();
protected:
    void keyPressEvent(QKeyEvent* e) override;

    // Disables all mouse clicks
    void mousePressEvent(QMouseEvent* e) override;
public slots:
    void onNewText();
    void onBadCharsChanged(bool badCharsExist);
    
private: 
    bool allowBackspace_ = false;
};
#endif 