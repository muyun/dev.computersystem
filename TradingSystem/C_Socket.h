#ifndef C_SOCKET_H
#define C_SOCKET_H
#include <QTcpSocket>
class C_Socket : public QTcpSocket
{
    Q_OBJECT
    friend class C_Server;
public:
    C_Socket(int id=0,bool waitForFile=false);
    int getID(){return id;}
    void sendMessage(QString message);
    void sendFile(QString path);
    void setFilename(QString name){filename=name;}
signals:
    void getMessage(int id,QString message);
    void disconnectedSIN(C_Socket*);

public slots:
    void readRawMessage();
    void writeFile();
    void onDisconnected();
private:
    int id;
    int filesize;
    int bytesReceived;
    bool waitForFile;
    QString filename;
};
#endif // C_SOCKET_H
