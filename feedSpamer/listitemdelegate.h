#ifndef LISTITEMDELEGATE_H
#define LISTITEMDELEGATE_H

#include <QItemDelegate>
#include <QPainter>

#include "listitemwidget.h"
#include "listitem.h"

class ListItemDelegate : public QItemDelegate
{
public:
	ListItemDelegate();
	ListItemWidget *wdg;
	void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
	QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // LISTITEMDELEGATE_H