#include "type.h"

#ifndef TYPELIST_H
#define TYPELIST_H

class typeList
{
public:
    typeList()
    {
    }

    void addNode(type* node)
    {
        dataList << node;
    }

    int getSize()
    {
        return dataList.size();
    }

    type* getIndexOf(int index)
    {
        return dataList.at(index);
    }

    void deleteIndexOf(int index)
    {
        dataList.takeAt(index);
    }

private:
    QList<type*> dataList;
};

#endif // TYPELIST_H
