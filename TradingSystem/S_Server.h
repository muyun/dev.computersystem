#ifndef S_SERVER_H
#define S_SERVER_H

#include <QtNetwork>
#include <QTcpSocket>
#include "S_Socket.h"
class S_Server : public QTcpServer
{
    Q_OBJECT
public:
    S_Server();
    QString getIP(int id)
    {
        foreach(S_Socket*ptr,clientSocketList)
        {
            if(ptr->id==id)
                return ptr->peerAddress().toString();
        }
        return NULL;
    }

signals:
    void toDisplay(QString);
public slots:
    //发送各模块的通讯信息
    void sendMessage(int num,QString message);
    void onDisconnectedSIG(S_Socket* brokenSocket);
protected:
    //读取数据
    void incomingConnection ( qintptr socketDescriptor );
private:
    QList<S_Socket*> clientSocketList;
    QMutex m_serverLock;
};
#endif // S_SERVER_H
