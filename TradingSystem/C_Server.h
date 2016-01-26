#ifndef C_SERVER_H
#define C_SERVER_H

#include <QtNetwork>
#include <QTcpSocket>
#include "C_Socket.h"
#include "Logic.h"
class C_Server : public QTcpServer
{
    Q_OBJECT
public:
    C_Server();
    //发送各模块的通讯信息
    void sendMessage(int id,QString message);
    void sendFile(int id,QString filename);
signals:
    void toDisplay(QString);

public slots:    
    void onDisconnectedSIG(C_Socket*brokenSocket);
protected:
    //读取数据
    void incomingConnection ( qintptr socketDescriptor );
private:
    QList<C_Socket*> clientSocketList;
    QMutex m_serverLock;

};

#endif // C_SERVER_H
