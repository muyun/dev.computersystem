#ifndef S_SOCKET_H
#define S_SOCKET_H
#include <QTcpSocket>
#include <QtNetwork>
class S_Socket : public QTcpSocket
{
    Q_OBJECT
    friend class S_Server;
public:
    S_Socket();
    int getID(){return id;}
    void sendMessage(QString message);
signals:
    void getMessage(int id,QString message);
    void disconnectedSIN(S_Socket*);

public slots:
    void readRawMessage();
    void onDisconnected(){emit disconnectedSIN(this);}
private:
    int id;
};
#endif // S_SOCKET_H

