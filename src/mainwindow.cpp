// Local Includes
#include "mainwindow.h"
#include "typingpage.h"
#include "startpage.h"
#include "actions.h"
#include "constants.h"
#include "statisticspage.h"
// QT Inlcudes
#include <QToolBar>
#include <QApplication>
#include <QFont>
#include <QStackedWidget>

MainWindow::MainWindow()
{
    setStyles();
    createToolBar();

    mainFrameStack_ = new QStackedWidget(this);

    startPage_ = new StartPage(this);
    typingPage_ = new TypingPage(this);
    statsPage_ = new StatisticsPage(this);

    mainFrameStack_->addWidget(startPage_);
    mainFrameStack_->addWidget(typingPage_);
    mainFrameStack_->addWidget(statsPage_);

    QSize minWIndowSize(900, 600);
    setMinimumSize(minWIndowSize);
    
    setCentralWidget(mainFrameStack_);
}

void MainWindow::navToStart()
{
    mainFrameStack_->setCurrentWidget(startPage_);
    navCodeAction_->setEnabled(true);
    navStartAction_->setEnabled(false);
    navStatsAction_->setEnabled(true);
}

void MainWindow::navToCode()
{
    mainFrameStack_->setCurrentWidget(typingPage_);
    typingPage_->reset();
    navStartAction_->setEnabled(true);
    navCodeAction_->setEnabled(false);
    navStatsAction_->setEnabled(true);
}

void MainWindow::navToStats() {
    mainFrameStack_->setCurrentWidget(statsPage_);
    navStartAction_->setEnabled(true);
    navCodeAction_->setEnabled(true);
    navStatsAction_->setEnabled(false);
}

void MainWindow::createToolBar() {
    auto* toolBar = new QToolBar;
    addToolBar(Qt::LeftToolBarArea,toolBar);
    toolBar->setFloatable(false);
    toolBar->setIconSize(QSize(32, 32));

    navStartAction_ = new NavStartPageAction(*this, this);
    navCodeAction_ = new NavCodePageAction(*this, this);
    navStatsAction_ = new NavStatsPageAction(*this, this);

    navStartAction_->setEnabled(false);

    toolBar->addAction(navStartAction_);
    toolBar->addAction(navCodeAction_);
    toolBar->addAction(navStatsAction_);
}

void MainWindow::setStyles() {
    QFont font("Consolas");
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);
    // color palette reference https://colorhunt.co/palette/2c3333395b64a5c9cae7f6f2
    setStyleSheet(
       "MainWindow{background-color: " + COLOR_BACKGROUND + ";}"
       "StyledTextZone, TypingZone{background-color: "+ COLOR_BACKGROUND_LIGHTER_TRANSPARENT +"; border: 1px solid " + COLOR_DARK_BORDER + "; border-radius: 5px;  margin-bottom: 0.75em; padding: 0.5em 0.75em;}"
       "*{color: " + COLOR_TEXT + "}"
       "Timer QLabel{color: " + COLOR_SECONDARY + "}"
       "pre{white-space: normal; font-family: Consolas;}"
       "QToolButton {margin: 8px}"
       "QToolBar{border-bottom: 1px solid "+ COLOR_DARK_BORDER +"; background-color:" + COLOR_BACKGROUND_LIGHTER + ";}"
        "TypingPage QPushButton{background-color: " +COLOR_BACKGROUND +"; font-weight: bold;}"
        "MainWindow {border-image: url(\"../res/img/dope_blob.svg\") 0 0 0 0 stretch stretch;}" // this border-image thing is magic :) https://forum.qt.io/topic/40151/solved-scaled-background-image-using-stylesheet/3
    );
}
