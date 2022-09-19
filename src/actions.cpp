#include "actions.h"

NavStartPageAction::NavStartPageAction(MainWindow& mainWindow, QWidget* parent) : mainWindow_(&mainWindow)
{
	setText("Home");
	setIcon(QIcon("../res/img/home_icon.svg"));
	//setShortcuts(QKeySequence::Open);
	//setStatusTip(tr("Open an existing file"));
	QObject::connect(this, &QAction::triggered, this, &NavStartPageAction::navToStart);
}

void NavStartPageAction::navToStart() {
	mainWindow_->navToStart();
}

NavCodePageAction::NavCodePageAction(MainWindow& mainWindow, QWidget* parent) : mainWindow_(&mainWindow)
{
	setText("Code");
	setIcon(QIcon("../res/img/code_icon.svg"));
	//setShortcuts(QKeySequence::Open);
	//setStatusTip(tr("Open an existing file"));
	QObject::connect(this, &QAction::triggered, this, &NavCodePageAction::navToCode);
}

void NavCodePageAction::navToCode() {
	mainWindow_->navToCode();
}