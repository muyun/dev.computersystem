#include "S_Socket.h"
#include "Logic.h"

S_Socket::S_Socket()
{
    connect(this,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
    connect(this,SIGNAL(readyRead()),this,SLOT(readRawMessage()));
    connect(this,SIGNAL(getMessage(int,QString)),logic,SLOT(decoder(int,QString)));
}
void S_Socket::sendMessage(QString message)
{
    QByteArray block; //用于暂存我们要发送的数据

    QDataStream out(&block,QIODevice::WriteOnly);

    //使用数据流写入数据

    out.setVersion(QDataStream::Qt_5_0);

    //设置数据流的版本，客户端和服务器端使用的版本要相同

    out<<(quint16) 0;

    out<<message;

    out.device()->seek(0);
    out<<(quint16)(block.size() - sizeof(quint16));
    write(block);
}

void S_Socket::readRawMessage()
 {
    QDataStream in(this);
    quint16 nextBlockSize;
    QString message;
    in.setVersion(QDataStream::Qt_5_0);

    while(1)
    {
    if(bytesAvailable() < (int)sizeof(quint16)) return;
    in >> nextBlockSize;

    if(bytesAvailable() < nextBlockSize) return;

    //如果没有得到全部的数据，则返回，继续接收数据

    in >> message;

    emit getMessage(id,message);
    }
    //将接收到的数据存放到变量中

 }
