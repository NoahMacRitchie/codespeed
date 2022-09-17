#include "mainwindow.h"
#include "qplaintextedit.h"
#include "QToolBar.h"
#include <QVBoxLayout>
#include "qlabel.h"
#include "typingzone.h"
#include "styledtextzone.h"
#include "results.h"
#include <QElapsedTimer>
#include "timer.h"
#include <QFont>
#include <QApplication>

void MainWindow::setStyles() {
    QFont font("Consolas");
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);
    // color palette reference https://colorhunt.co/palette/2c3333395b64a5c9cae7f6f2
    setStyleSheet("MainWindow{background-color: #232828;}"
        "StyledTextZone, TypingZone{background-color: #1a1e1e; border: 1px solid #A5C9CA; border-radius: 5px;  margin-bottom: 0.75em; padding: 0.5em 0.75em;}"
        "*{color: #E7F6F2}"
        "Timer QLabel{color: #A5C9CA}"
        "pre{white-space: normal; font-family: Consolas;}");
}

MainWindow::MainWindow()
{
    setStyles();
    auto* ToolBar = new QToolBar;
    addToolBar(ToolBar);

    auto typingScreenLay = new QVBoxLayout(this);

    auto mainContentLay = new QVBoxLayout(this);

    QWidget* typingScreenWid = new QWidget(this);
    QWidget* mainContentWid = new QWidget(typingScreenWid);

    auto typingZone = new TypingZone(typingScreenWid);
    auto styledTextZone = new StyledTextZone(typingScreenWid, *typingZone);

    mainContentLay->addWidget(styledTextZone);
    mainContentLay->addWidget(typingZone);
    mainContentWid->setLayout(mainContentLay);
    Timer* timer = new Timer(this);
    auto score = new Results(typingScreenWid);

    QObject::connect(typingZone, &TypingZone::textChanged, styledTextZone, &StyledTextZone::onUserTyped);
    QObject::connect(styledTextZone, &StyledTextZone::onNewText, typingZone, &TypingZone::onNewText);
    QObject::connect(typingZone, &TypingZone::removeBadChar, styledTextZone, &StyledTextZone::removeBadChar);
    QObject::connect(styledTextZone, &StyledTextZone::badCharsChanged, typingZone, &TypingZone::onBadCharsChanged);
    QObject::connect(styledTextZone, &StyledTextZone::finished, timer, &Timer::stopTimer);
    QObject::connect(timer, &Timer::timeStopped, score, &Results::saveResults);

    typingScreenLay->addWidget(timer);
    typingScreenLay->addWidget(mainContentWid);
    typingScreenWid->setLayout(typingScreenLay);
    QString text("while(true){\n    useCodeSpeed()\n}");
    styledTextZone->setNewText(text);
    QObject::connect(typingZone, &TypingZone::textChanged, timer, &Timer::startTimer);

    setCentralWidget(typingScreenWid);
}
 