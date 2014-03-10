#ifndef LISTITEMWIDGET_H
#define LISTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class ListItemWidget : public QWidget
{
	Q_OBJECT
public:
	QLabel *name;
	QLabel *description;
	QVBoxLayout *layout;
	explicit ListItemWidget(QWidget *parent = 0);
	~ListItemWidget();
signals:

	public slots:

};

#endif // LISTITEMWIDGET_H
