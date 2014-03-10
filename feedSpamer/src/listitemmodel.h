#ifndef LISTITEMMODEL_H
#define LISTITEMMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "listitem.h"

class ListItemModel : public QAbstractListModel
{
	Q_OBJECT
public:
	explicit ListItemModel(QObject *parent = 0);
	QList<ListItem *> list;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index) const;
signals:

	public slots:

};

#endif // LISTITEMMODEL_H