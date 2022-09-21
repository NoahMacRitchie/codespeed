// Local Includes
#include "statisticspage.h"
#include "constants.h"

// Qt Includes
#include <QVBoxLayout>
#include <QLabel>


StatisticsPage::StatisticsPage(QWidget* parent) : QWidget(parent)
{
	auto centerTextLay = new QVBoxLayout(this);

	auto comingSoon = new QLabel("<span style=\"color:#f8fcff;font-size: 22px;font-weight: bold;\">Statistics and Analysis <span style=\"color: "+COLOR_SECONDARY+";\">COMING SOON</span></span>", this);

	comingSoon->setAlignment(Qt::AlignCenter);

	centerTextLay->addWidget(comingSoon);
	centerTextLay->setAlignment(Qt::AlignCenter);

	setLayout(centerTextLay);
}
