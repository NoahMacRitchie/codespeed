// Local Includes
#include "typingpage.h"

#include "styledtextzone.h"
#include "typingzone.h"
#include "results.h"
#include "timer.h"

// Qt Includes
#include <QVBoxLayout>
#include <QElapsedTimer>
#include <QPlainTextEdit>
#include <QLabel>

TypingPage::TypingPage(QWidget* parent) : QWidget(parent)
{
    auto typingScreenLay = new QVBoxLayout(this);

    auto mainContentLay = new QVBoxLayout(this);

    QWidget* mainContentWid = new QWidget(this);

    auto typingZone = new TypingZone(this);
    styledTextZone_ = new StyledTextZone(this, *typingZone);

    mainContentLay->addWidget(styledTextZone_);
    mainContentLay->addWidget(typingZone);
    mainContentWid->setLayout(mainContentLay);
    timer_ = new Timer(this);
    auto score = new Results(this);

    QObject::connect(typingZone, &TypingZone::textChanged, styledTextZone_, &StyledTextZone::onUserTyped);
    QObject::connect(styledTextZone_, &StyledTextZone::onNewText, typingZone, &TypingZone::onNewText);
    QObject::connect(typingZone, &TypingZone::removeBadChar, styledTextZone_, &StyledTextZone::removeBadChar);
    QObject::connect(styledTextZone_, &StyledTextZone::badCharsChanged, typingZone, &TypingZone::onBadCharsChanged);
    QObject::connect(styledTextZone_, &StyledTextZone::finished, timer_, &Timer::stopTimer);
    QObject::connect(timer_, &Timer::timeStopped, score, &Results::saveResults);
    QObject::connect(typingZone, &TypingZone::textChanged, timer_, &Timer::startTimer);
    typingScreenLay->addWidget(timer_);
    typingScreenLay->addWidget(mainContentWid);

    QString text("while(true){\n    useCodeSpeed()\n}");
    styledTextZone_->setNewText(text);
    

    setLayout(typingScreenLay);
}

void TypingPage::reset()
{
    QString text("while(true){\n    useCodeSpeed()\n}");
    timer_->reset();
    styledTextZone_->setNewText(text);
    
}
