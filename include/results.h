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

struct ResultsData {
	QString language_;
	int finishTime_ = 0;
	QList <QChar> mistakeChars_;
};
// Will get called at end of game to store date, score, language, mistakes
class Results : public QWidget{
public:
	void displayResults();
	static bool saveResults(ResultsData);
	
};
#endif 