#ifndef RESULTS_H
#define RESULTS_H

#include <qmainwindow.h>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QWidget>
#include "qfile.h"


class QJsonDocument;
class QJsonObject;

// Will get called at end of game to store date, score, language, mistakes
class Results : public QWidget{
public:
	Results(QWidget* parent);
	void displayResults();
	
private:
	int finishTime_ = 0;
	QString language_ = "C++";
	QJsonObject mainObject_;
	QJsonObject timeScore_;
	QJsonObject languageType_;
	QJsonDocument jsonDoc_;
public slots:
	void saveResults(int timeMs);
};
#endif 