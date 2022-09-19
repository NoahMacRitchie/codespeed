#ifndef TYPINGPAGE_H
#define TYPINGPAGE_H

#include <QWidget>
class Timer;
class StyledTextZone;
class TypingPage : public QWidget
{
    Q_OBJECT

public:
    TypingPage(QWidget* parent);

    void reset();
public slots:
signals:
private:
    Timer* timer_ = nullptr;
    StyledTextZone* styledTextZone_ = nullptr;
};
#endif 