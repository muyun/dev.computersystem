#ifndef ENTRIESMODEL_H
#define ENTRIESMODEL_H
#include <QAbstractTableModel>
#include <QTableView>
#include "Logic.h"
class EntriesModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    EntriesModel(QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    int columnSize;

};

#endif // ENTRIESMODEL_H
