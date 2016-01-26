#include "EntriesModel.h"

EntriesModel::EntriesModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    columnSize=3;
    connect(logic,SIGNAL(dataChanged()),this,SIGNAL(layoutChanged()));
}
int EntriesModel::rowCount(const QModelIndex & /*parent*/) const
{
   return logic->getEntries().size();
}

int EntriesModel::columnCount(const QModelIndex & /*parent*/) const
{
    return columnSize;
}

QVariant EntriesModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::DisplayRole)
    {
        switch(col)
        {
        case 0:
            return logic->getEntries().at(row)->id;
        case 1:
            return logic->getEntries().at(row)->filename;
        case 2:
            return logic->getEntries().at(row)->owner;
        }
    }
    return QVariant();
}

QVariant EntriesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Filename");
            case 2:
                return QString("Owner");
            }
        }
    }
    return QVariant();
}
