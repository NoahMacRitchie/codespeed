#include "mainwindow.h"
#include "qplaintextedit.h"


MainWindow::MainWindow()
{
    auto textEdit = new QPlainTextEdit;
    setCentralWidget(textEdit);
}
