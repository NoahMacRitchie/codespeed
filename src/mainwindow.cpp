// Local Includes
#include "mainwindow.h"
#include "typingpage.h"

// QT Inlcudes
#include <QToolBar>
#include <QApplication>
#include <QFont>


MainWindow::MainWindow()
{
    setStyles();
    auto* ToolBar = new QToolBar;
    addToolBar(ToolBar);
    
    typingPage_ = new TypingPage(this);

    setCentralWidget(typingPage_);
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
        "pre{white-space: normal; font-family: Consolas;}");
}