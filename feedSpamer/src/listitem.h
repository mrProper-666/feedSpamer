#ifndef LISTITEM_H
#define LISTITEM_H
 
#include <QtCore>
 
class ListItem
{
public:
    QString name; 
    QString description;
    ListItem();
	~ListItem();
};

Q_DECLARE_METATYPE(ListItem *)
#endif // LISTITEM_H