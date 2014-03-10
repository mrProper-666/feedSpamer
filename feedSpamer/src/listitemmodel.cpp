#include "listitemmodel.h"
 
ListItemModel::ListItemModel(QObject *parent) :
    QAbstractListModel(parent)
{
	list.clear();
}
 
int ListItemModel::rowCount(const QModelIndex &parent) const
{
    return list.size();
}
 
QVariant ListItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= list.size())
        return QVariant();
    if (role == Qt::DisplayRole){

        return QVariant::fromValue(list.at(index.row()));
    }else{
        return QVariant();
    }
}
 
Qt::ItemFlags ListItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractItemModel::flags(index) | Qt::ItemIsEnabled ;
}