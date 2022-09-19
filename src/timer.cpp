#include "timer.h"
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>

static const int TIMER_MS_UPDATE_INTERVAL(1);

Timer::Timer(QWidget* parent) : QWidget(parent)
{
	timer_ = new QTimer(this);
	timerLabel_ = new QLabel("Time Elapsed", this);
	connect(timer_, &QTimer::timeout, this, &Timer::updateLabel);

	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->addWidget(timerLabel_);

	setLayout(lay);
}

void Timer::startTimer() {
	if (!timerIsRunning_) {
		timer_->start(TIMER_MS_UPDATE_INTERVAL);
		timerIsRunning_ = true;
	}
}

void Timer::stopTimer() {
	timer_->stop();
	emit timeStopped(msPassed_);
}

void Timer::updateLabel() {
	msPassed_ += TIMER_MS_UPDATE_INTERVAL;
	float timeSec = msPassed_ < 10 ? 0 : static_cast<float>(msPassed_) / 1000;
	timerLabel_->setText("Time Elapsed (s): " + QString::number(timeSec));
}

void Timer::reset() {
	timerIsRunning_ = false;
	timer_->stop();
	msPassed_ = 0;
	updateLabel();
}



 