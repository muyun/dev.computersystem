#include <QList>
#include <QString>
#include "EntriesData.h"

#ifndef TYPE_H
#define TYPE_H

class type
{
public:
    type(QString name)
    {
        typeName = name;
    }

    void addNode(EntriesData* node)
    {
        dataList << node;
    }

    int getSize()
    {
        return dataList.size();
    }

    QString getName()
    {
        return typeName;
    }

    EntriesData* getIndexOf(int index)
    {
        return dataList.at(index);
    }

    void deleteIndexOf(int index)
    {
        dataList.takeAt(index);
    }

private:
    QString typeName;
    QList<EntriesData*> dataList;
};

#endif // TYPE_H
