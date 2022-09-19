// Local Includes
#include "mainwindow.h"
#include "typingpage.h"
#include "startpage.h"
#include "actions.h"

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

    typingPage_ = new TypingPage(this);
    startPage_ = new StartPage(this);

    mainFrameStack_->addWidget(startPage_);
    mainFrameStack_->addWidget(typingPage_);
    
    setCentralWidget(mainFrameStack_);
}

void MainWindow::navToStart()
{
    mainFrameStack_->setCurrentWidget(startPage_);
}

void MainWindow::navToCode()
{
    mainFrameStack_->setCurrentWidget(typingPage_);
    typingPage_->reset();
}
 

void MainWindow::createToolBar() {
    auto* toolBar = new QToolBar;
    addToolBar(toolBar);

    auto navStartAction = new NavStartPageAction(*this, this);
    auto navCodeAction = new NavCodePageAction(*this, this);
    toolBar->addAction(navStartAction);
    toolBar->addAction(navCodeAction);
}

void MainWindow::setStyles() {
    QFont font("Consolas");
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);
    // color palette reference https://colorhunt.co/palette/2c3333395b64a5c9cae7f6f2
    setStyleSheet("MainWindow{background-color: #232828;}"
        "StyledTextZone, TypingZone{background-color: #1a1e1e; border: 1px solid #A5C9CA; border-radius: 5px;  margin-bottom: 0.75em; padding: 0.5em 0.75em;}"
        "*{color: #E7F6F2}"
        "Timer QLabel{color: #A5C9CA}"
        "pre{white-space: normal; font-family: Consolas;}"
        "QIcon{width: 100px; height: 100px; margin: 10px}"
    );
}