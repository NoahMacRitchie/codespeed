#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qmainwindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    
private: 
    void setStyles();
};
#endif // MAINWINDOW_H