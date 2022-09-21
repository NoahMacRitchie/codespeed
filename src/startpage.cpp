// Local Includes
#include "startpage.h"
#include "constants.h"

// Qt Includes
#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>

StartPage::StartPage(QWidget* parent) : QWidget(parent)
{
	auto centerTextLay = new QVBoxLayout(this);
	auto title = new QLabel("<span style=\"color:#f8fcff;font-size: 60px;font-weight: bold;\">Code<span style=\"color: #4FACF7;\">Speed</span></span>", this);
	auto subTitle = new QLabel("<span style=\"color:#f8fcff;font-size: 22px;font-weight: bold;\">How fast can <span style=\"color: "+COLOR_SECONDARY+";\">YOU</span> code?</span>", this);

	title->setAlignment(Qt::AlignCenter);
	subTitle->setAlignment(Qt::AlignCenter);
	centerTextLay->addWidget(title);
	centerTextLay->addWidget(subTitle);
	centerTextLay->setAlignment(Qt::AlignCenter);

	setLayout(centerTextLay);
}
