#include "mainwindow.h"
#include "qplaintextedit.h"
#include "QToolBar.h"


MainWindow::MainWindow()
{

    auto *ToolBar = new QToolBar;
    addToolBar(ToolBar);

    auto textEdit = new QPlainTextEdit;
    setCentralWidget(textEdit);
}
 