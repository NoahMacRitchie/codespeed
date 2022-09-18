#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qmainwindow.h>

class TypingPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    
private: 
    TypingPage* typingPage_ = nullptr;
    void setStyles();
};
#endif // MAINWINDOW_H