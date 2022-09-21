#ifndef ACTIONS_H
#define ACTIONS_H
#include "mainwindow.h"

#include <QAction>

class NavStartPageAction : public QAction
{
    Q_OBJECT
public:
    NavStartPageAction(MainWindow& mainWindow, QWidget* parent);
private:
    MainWindow* mainWindow_;
private slots:
    void navToStart();
};

class NavCodePageAction : public QAction
{
    Q_OBJECT
public:
    NavCodePageAction(MainWindow& mainWindow, QWidget* parent);
public slots:
private:
    MainWindow* mainWindow_;
private slots:
    void navToCode();
};
class NavStatsPageAction : public QAction
{
    Q_OBJECT
public:
    NavStatsPageAction(MainWindow& mainWindow, QWidget* parent);
public slots:
private:
    MainWindow* mainWindow_;
private slots:
    void navToStats();
};
#endif 