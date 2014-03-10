#include "listitemwidget.h"

ListItemWidget::ListItemWidget(QWidget *parent)
	: QWidget(parent)
{
	name = new QLabel;
	description = new QLabel;
	layout = new QVBoxLayout;
	layout->addWidget(name);
	layout->addWidget(description);
	QFont font;
	font.setBold(true);
	name->setFont(font);
	this->setLayout(layout);
}

ListItemWidget::~ListItemWidget()
{
	delete name;
	delete description;
	delete layout;
}
