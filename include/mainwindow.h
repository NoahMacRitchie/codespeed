#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qmainwindow.h>

class TypingPage;
class StartPage;
class QStackedWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void navToStart();
    void navToCode();
private: 
    TypingPage* typingPage_ = nullptr;
    StartPage* startPage_ = nullptr;
    QStackedWidget* mainFrameStack_ = nullptr;

    void setStyles();
    void createToolBar();
};
#endif // MAINWINDOW_H