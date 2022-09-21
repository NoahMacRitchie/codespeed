#include "results.h"

#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
void Results::displayResults() {

}

bool Results::saveResults(ResultsData rd) {
	QFile file;
	QDate date;

	date = date.currentDate();
	file.setFileName("./score.json");

	QJsonDocument jsonDoc;
	QJsonObject mainObject;
	QJsonObject timeScore;
	QJsonObject languageType;
	QJsonObject resultDate;
	QJsonObject mistakes;
	QJsonArray array;

	timeScore.insert("Time", rd.finishTime_);
	languageType.insert("Language", rd.language_);
	resultDate.insert("Date", date.toString("dd.MM.yyyy"));
	mistakes.insert("Mistake", array);
	mainObject.insert("Mistakes", mistakes);
	mainObject.insert("resultDate", resultDate);
	mainObject.insert("Time Scores", timeScore);
	mainObject.insert("Language", languageType);
	jsonDoc.setObject(mainObject);

	for (int i = 0; i < (rd.mistakeChars_.length()-1);i++) {
		array.append(rd.mistakeChars_[i].toLatin1());
	}

	if (!file.open(QIODevice::ReadOnly)){return false;}

	QJsonDocument data = QJsonDocument::fromJson(file.readAll());
	file.close();

	QJsonArray arrLog = data.array();
	arrLog.push_back(mainObject);
	QJsonDocument doc(arrLog);
	
	if (!file.open(QIODevice::WriteOnly)) {return false;}

	file.write(doc.toJson());
	file.close();
}
