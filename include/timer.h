#ifndef TIMER_H
#define TIMER_H

#include <QWidget>

class QLabel;
class QTimer;

class Timer : public QWidget
{
    Q_OBJECT

public:
    Timer(QWidget* parent);
public slots:
    void startTimer();
    void stopTimer();
    void updateLabel();
signals:
    void timeStopped(int timeScore);
private:
    QTimer* timer_ = nullptr;
    QLabel* timerLabel_ = nullptr;
    int msPassed_ = 0;
    bool timerIsRunning_ = false;
};
#endif 