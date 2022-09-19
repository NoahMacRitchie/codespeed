#include "results.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>

Results::Results(QWidget* parent) : QWidget(parent){
	//TODO : Make this a singleton class
}

void Results::displayResults() {

}
void Results::saveResults(int timeMs) {
	QFile file;
	finishTime_ = timeMs;
	file.setFileName("./results/score.json");
	file.open(QIODevice::ReadWrite | QIODevice::Text);
	timeScore_.insert("Time", finishTime_);
	languageType_.insert("Language", language_);
	mainObject_.insert("Time Scores", timeScore_);
	mainObject_.insert("Language", languageType_);
	jsonDoc_.setObject(mainObject_);
	file.write(jsonDoc_.toJson());
	file.close();
}
	