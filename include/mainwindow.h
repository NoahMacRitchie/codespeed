#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qmainwindow.h>

class TypingPage;
class StartPage;
class QStackedWidget;
class NavStartPageAction;
class NavCodePageAction;
class NavStatsPageAction;
class StatisticsPage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    void navToStart();
    void navToCode();
    void navToStats();
private: 
    TypingPage* typingPage_ = nullptr;
    StartPage* startPage_ = nullptr;
    StatisticsPage* statsPage_ = nullptr;
    QStackedWidget* mainFrameStack_ = nullptr;
    NavStartPageAction* navStartAction_ = nullptr;
    NavCodePageAction* navCodeAction_ = nullptr;
    NavStatsPageAction* navStatsAction_ = nullptr;
    void setStyles();
    void createToolBar();
};
#endif // MAINWINDOW_H