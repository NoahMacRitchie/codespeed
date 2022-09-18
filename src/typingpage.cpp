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
    auto styledTextZone = new StyledTextZone(this, *typingZone);

    mainContentLay->addWidget(styledTextZone);
    mainContentLay->addWidget(typingZone);
    mainContentWid->setLayout(mainContentLay);
    Timer* timer = new Timer(this);
    auto score = new Results(this);

    QObject::connect(typingZone, &TypingZone::textChanged, styledTextZone, &StyledTextZone::onUserTyped);
    QObject::connect(styledTextZone, &StyledTextZone::onNewText, typingZone, &TypingZone::onNewText);
    QObject::connect(typingZone, &TypingZone::removeBadChar, styledTextZone, &StyledTextZone::removeBadChar);
    QObject::connect(styledTextZone, &StyledTextZone::badCharsChanged, typingZone, &TypingZone::onBadCharsChanged);
    QObject::connect(styledTextZone, &StyledTextZone::finished, timer, &Timer::stopTimer);
    QObject::connect(timer, &Timer::timeStopped, score, &Results::saveResults);
    QObject::connect(typingZone, &TypingZone::textChanged, timer, &Timer::startTimer);
    typingScreenLay->addWidget(timer);
    typingScreenLay->addWidget(mainContentWid);

    QString text("while(true){\n    useCodeSpeed()\n}");
    styledTextZone->setNewText(text);
    

    setLayout(typingScreenLay);
}

void TypingPage::reset()
{
}
