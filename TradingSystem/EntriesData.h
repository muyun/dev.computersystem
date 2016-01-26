#ifndef ENTRIESDATA_H
#define ENTRIESDATA_H
#include <QString>
class EntriesModel;
class Logic;
class EntriesData
{
    friend class EntriesModel;
    friend class Logic;
    friend class type;
    friend class typeList;
public:
    EntriesData(QString info)
    {
        QStringList args = info.split(",");
        id = args[0].toInt();
        filename = args[1];
        owner = args[2];
    }

    QString toString()
    {
        QString msg=";"+QString::number(id)+";"+filename+";"+owner;
        return msg;
    }

private:
    int id;
    QString filename;
    QString owner;
};

#endif // ENTRIESDATA_H
