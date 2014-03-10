#include "listitemdelegate.h"
 
ListItemDelegate::ListItemDelegate()
{
    wdg = new ListItemWidget;
}
 
void ListItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    ListItem *my_item = index.data().value<ListItem *>();
    wdg->name->setText(my_item->name);
    wdg->description->setText(my_item->description);
 
    QPalette pal;

    if ((option.state & QStyle::State_Selected) == QStyle::State_Selected){
		pal.setBrush(QPalette::Window, pal.color(QPalette::Highlight));
	}else{
		pal.setBrush(QPalette::Window, QBrush(QColor(Qt::transparent)));
    }
    wdg->setPalette(pal);
    wdg->resize(option.rect.size());

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->translate(option.rect.topLeft());
    wdg->render(painter);
    painter->restore();
}
 
QSize ListItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int width = 100;
    int height = 65;
    return QSize(width, height);
}