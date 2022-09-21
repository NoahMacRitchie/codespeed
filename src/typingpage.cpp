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
#include <QPushButton>

TypingPage::TypingPage(QWidget* parent) : QWidget(parent)
{
    ResultsData currentData;
    auto typingScreenLay = new QVBoxLayout(this);
    auto btnRowLay = new QHBoxLayout(this);
    auto btnRowWid = new QWidget(this);

    btnRowWid->setLayout(btnRowLay);

    auto mainContentLay = new QVBoxLayout(this);

    QWidget* mainContentWid = new QWidget(this);

    auto typingZone = new TypingZone(this);
    styledTextZone_ = new StyledTextZone(this, *typingZone);

    mainContentLay->addWidget(styledTextZone_);
    mainContentLay->addWidget(typingZone);
    mainContentWid->setLayout(mainContentLay);

    auto resetBtn = new QPushButton("RESET", this);
    auto newTextBtn = new QPushButton("NEW TEXT");
    timer_ = new Timer(this);
    auto score = new Results();

    QObject::connect(typingZone, &TypingZone::textChanged, styledTextZone_, &StyledTextZone::onUserTyped);
    QObject::connect(styledTextZone_, &StyledTextZone::onNewText, typingZone, &TypingZone::onNewText);
    QObject::connect(typingZone, &TypingZone::removeBadChar, styledTextZone_, &StyledTextZone::removeBadChar);
    QObject::connect(styledTextZone_, &StyledTextZone::badCharsChanged, typingZone, &TypingZone::onBadCharsChanged);
    QObject::connect(styledTextZone_, &StyledTextZone::finished, timer_, &Timer::stopTimer);
    QObject::connect(timer_, &Timer::timeStopped, this, &TypingPage::storeData);
    QObject::connect(typingZone, &TypingZone::textChanged, timer_, &Timer::startTimer);

    resetBtn->setMaximumWidth(100);
    newTextBtn->setMaximumWidth(100);

    btnRowLay->addWidget(timer_);
    btnRowLay->addWidget(resetBtn);
    btnRowLay->addWidget(newTextBtn);
    typingScreenLay->addWidget(btnRowWid);
    typingScreenLay->addWidget(mainContentWid);

    QString text("while(true){\n    useCodeSpeed();\n}");
    styledTextZone_->setNewText(text);
   
    setLayout(typingScreenLay);
}

void TypingPage::reset()
{
    QString text("while(true){\n    useCodeSpeed();\n}");
    styledTextZone_->setNewText(text);

    timer_->reset();
}

void TypingPage::storeData() {
    ResultsData rd;
   
    rd.finishTime_ = timer_->getTime();
    rd.language_ = "C++";
    rd.mistakeChars_ = styledTextZone_->getMistakeChars();

    Results::saveResults(rd);
}
