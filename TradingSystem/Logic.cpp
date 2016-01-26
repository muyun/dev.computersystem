#include "Logic.h"

Logic::Logic(QObject *parent) :
    QObject(parent)
{
    server=new S_Server;

    //写入一些预设的信息
    type* Music = new type("Music");
    Music->addNode(new EntriesData("1,MySoul,192.168.1.1"));
    Music->addNode(new EntriesData("2,AngelHeart,192.168.1.1"));
    Music->addNode(new EntriesData("3,ForeverAlone,192.168.1.1"));
    mTypeList.addNode(Music);
}

void Logic::decoder(int id,QString message)
{
    decoderLock.lock();
    emit this->toDisplay("receive from client "+QString::number(id));
    emit this->toDisplay(message);

    QStringList args=message.split(";");
    QString nameList = "";
    QString typeName;
    QString fileList = "";
    QString filename, url;
    QString msg;
    int index;
    int ID;
    type* newType;
    switch (args[0].toInt())
    {

//收到发送TYPE列表的请求
    case 1:

        for(int i=0; i<mTypeList.getSize(); i++) {
            nameList += mTypeList.getIndexOf(i)->getName();
            if(i != mTypeList.getSize()-1) nameList+=",";
        }
        msg = "1;" + QString::number(mTypeList.getSize()) + ";" + nameList;
        server->sendMessage(id,msg);
        break;

//收到发送FILENAME列表和对应的地址的请求
    case 2:
        typeName = args[1];
        index = -1;
        for(int i=0; i<mTypeList.getSize(); i++)
            if(mTypeList.getIndexOf(i)->getName() == typeName) {
                index = i;
                break;
            }
        for(int i=0; i<mTypeList.getIndexOf(index)->getSize(); i++)
            fileList += mTypeList.getIndexOf(index)->getIndexOf(i)->toString();
        msg = "2;"+QString::number(mTypeList.getIndexOf(index)->getSize())+fileList;
        server->sendMessage(id,msg);
        break;

//新添加一个文件
    case 3:
        typeName = args[1];
        index = -1;
        filename = args[2];
        url = getServer()->getIP(id);
        for(int i=0; i<mTypeList.getSize(); i++)
            if(mTypeList.getIndexOf(i)->getName() == typeName) {
                index = i;
                break;
            }
        emit toDisplay("ADD NEW typename="+typeName+" Type index="+QString::number(index)+" filename="+filename+" IP="+url);
        if(index == -1)//新的type
        {
            newType = new type(typeName);
            newType->addNode(new EntriesData("1," + filename + "," + url));
            mTypeList.addNode(newType);

            //新增type,进行广播
            for(int i=0; i<mTypeList.getSize(); i++) {
                nameList += mTypeList.getIndexOf(i)->getName();
                if(i != mTypeList.getSize()-1) nameList+=",";
            }
            msg = "1;" + QString::number(mTypeList.getSize()) + ";" + nameList;
            server->sendMessage(-1,msg);

        }
        else//已存在的type
        {
            ID = mTypeList.getIndexOf(index)->getSize();
            mTypeList.getIndexOf(index)->addNode(new EntriesData(QString::number(ID) + "," + filename + "," + url));
        }
        break;
    }
    decoderLock.unlock();
}

void Logic::deleteIP(QString ip)
{
    for(int i=0; i<mTypeList.getSize(); i++) {
        for(int j=0; j<mTypeList.getIndexOf(i)->getSize(); j++) {
            if(mTypeList.getIndexOf(i)->getIndexOf(j)->owner == ip) {
                mTypeList.getIndexOf(i)->deleteIndexOf(j);
                j--;
            }
        }
    }
}
