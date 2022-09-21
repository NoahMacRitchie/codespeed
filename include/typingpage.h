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
    void storeData();

signals:
private:
    Timer* timer_ = nullptr;
    StyledTextZone* styledTextZone_ = nullptr;
};
#endif 