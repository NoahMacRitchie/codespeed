#include "actions.h"

NavStartPageAction::NavStartPageAction(MainWindow& mainWindow, QWidget* parent) : mainWindow_(&mainWindow)
{
	setText("Home");
	setIcon(QIcon("../res/img/home_icon.svg"));
	QObject::connect(this, &QAction::triggered, this, &NavStartPageAction::navToStart);
}

void NavStartPageAction::navToStart() {
	mainWindow_->navToStart();
}

NavCodePageAction::NavCodePageAction(MainWindow& mainWindow, QWidget* parent) : mainWindow_(&mainWindow)
{
	setText("Code");
	setIcon(QIcon("../res/img/code_icon.svg"));
	QObject::connect(this, &QAction::triggered, this, &NavCodePageAction::navToCode);
}

void NavCodePageAction::navToCode() {
	mainWindow_->navToCode();
}

NavStatsPageAction::NavStatsPageAction(MainWindow& mainWindow, QWidget* parent) : mainWindow_(&mainWindow)
{
	setText("Statistics");
	setIcon(QIcon("../res/img/stats_icon.svg"));
	QObject::connect(this, &QAction::triggered, this, &NavStatsPageAction::navToStats);
}

void NavStatsPageAction::navToStats() {

	mainWindow_->navToStats();
}