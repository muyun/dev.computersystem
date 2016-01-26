#include "C_Socket.h"
#include "Logic.h"
#include <QMessageBox>
C_Socket::C_Socket(int num, bool flag)
{
    id=num;
    filesize=0;
    bytesReceived=0;
    waitForFile=flag;
    if(!waitForFile){
        connect(this,SIGNAL(readyRead()),this,SLOT(readRawMessage()));
        connect(this,SIGNAL(getMessage(int,QString)),logic,SLOT(decoder(int,QString)));
    }
    else
        connect(this,SIGNAL(readyRead()),this,SLOT(writeFile()));

    connect(this,SIGNAL(disconnected()),this,SLOT(onDisconnected()));
    connect(this,SIGNAL(disconnected()),this,SLOT(deleteLater()));
}

void C_Socket::onDisconnected()
{
    QMessageBox*prop;
    //连server的socket断了
    if(id==0){
        prop=new QMessageBox(QMessageBox::Critical,"Warning","你已断线，请退出后重新登录");
        prop->exec();
    }
    else
        emit disconnectedSIN(this);
    if(waitForFile)
        {
            prop=new QMessageBox(QMessageBox::Information,"Warning","下载完成！");
            prop->exec();
        }

}

void C_Socket::readRawMessage()
{
    QDataStream in(this);
    quint16 nextBlockSize;
    QString message;
    in.setVersion(QDataStream::Qt_5_0);
    while(1){
    if(bytesAvailable() < (int)sizeof(quint16)) return;
    in >> nextBlockSize;
    if(bytesAvailable() < nextBlockSize) return;
    //如果没有得到全部的数据，则返回，继续接收数据
    in >> message;
    //将接收到的数据存放到变量中
    emit getMessage(id,message);
    }
}

void C_Socket::sendMessage(QString message)
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

void C_Socket::sendFile(QString path)
{
    QFile inputFile(path);
    QByteArray read;
    inputFile.open(QIODevice::ReadOnly);
    while(1)
    {
        read.clear();
        read = inputFile.read(32768*8);
        read.size();
        if(read.size()==0)
            break;

        write(read);
        waitForBytesWritten();
        read.clear();
    }
    inputFile.close();
    disconnectFromHost();
}

void C_Socket::writeFile()
{
    QFile file(filename);
    if(!(file.open(QIODevice::Append)))
    {
        qDebug("File cannot be opened.");
        exit(0);
    }
    QByteArray read = this->read(bytesAvailable());
    bytesReceived += read.size();
    file.write(read);
    file.close();
}
