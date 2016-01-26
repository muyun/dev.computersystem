#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>
#include "S_Server.h"
#include "typeList.h"

class Logic : public QObject
{
    Q_OBJECT
public:
    explicit Logic(QObject *parent = 0);
    void deleteIP(QString ip);
    S_Server* getServer(){return server;}
signals:
    void toDisplay(QString msg);
public slots:
    void decoder(int id,QString msg);
private:
    S_Server* server;
    QMutex decoderLock;
    typeList mTypeList;

};
extern Logic*logic;
#endif // LOGIC_H
