// Local Includes
#include "startpage.h"


// Qt Includes
#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>

StartPage::StartPage(QWidget* parent) : QWidget(parent)
{
	auto startPageLay = new QGridLayout(this);

	auto startPageText = new QLabel("CodeSpeed", this);
	startPageText->setAlignment(Qt::AlignCenter);

	startPageLay->addWidget(startPageText, 0, 0);
	

	setLayout(startPageLay);
}
