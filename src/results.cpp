#include "results.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QWidget>
#include "qfile.h"
#include "timer.h"
#include <QVBoxLayout>
#include "qlabel.h"
Results::Results(QWidget* parent) : QWidget(parent){
	
}

void Results::displayResults() {

}
void Results::saveResults(int timeMs) {

	QFile file;
	finishTime_ = timeMs;
	file.setFileName("C:/Users/dunca/score.json");
	file.open(QIODevice::ReadWrite | QIODevice::Text);
	timeScore_.insert("Time", finishTime_);
	languageType_.insert("Language", language_);
	mainObject_.insert("Time Scores", timeScore_);
	mainObject_.insert("Language", languageType_);
	jsonDoc_.setObject(mainObject_);
	file.write(jsonDoc_.toJson());
	file.close();
	
}
	