#include "C_Server.h"

C_Server::C_Server()
{
    listen(QHostAddress::Any,50001);
}

void C_Server::incomingConnection ( qintptr socketDescriptor )
{
    m_serverLock.lock();
    C_Socket* newSocket=new C_Socket;
    newSocket->setSocketDescriptor(socketDescriptor);

    int availableID;
    bool found;
    for(availableID=1;;availableID++)
    {
        found=true;
        for(int i=0;i<clientSocketList.count();i++)
            if(clientSocketList[i]->id==availableID)
            {
                found=false;
                break;
            }
        if(found)
            break;
    }
    newSocket->id=availableID;
    clientSocketList.append(newSocket);
    connect(newSocket,SIGNAL(disconnectedSIN(S_Socket*)),this,SLOT(onDisconnectedSIG(S_Socket*)));
    emit toDisplay("用户"+QString::number(availableID)+"登入");
    m_serverLock.unlock();
}

//num=-1表示广播
void C_Server::sendMessage(int id, QString message)
{
    if(id != -1)
    {
        for(int i=0;i<clientSocketList.size();i++)
            if(clientSocketList[i]->id==id)
            {
                clientSocketList[i]->sendMessage(message);
                break;
            }
    }
    else
        for(int i = 0;i < this->clientSocketList.size();i++)
            clientSocketList[i]->sendMessage(message);
    emit this->toDisplay("send:");
    emit this->toDisplay(message);
}

void C_Server::sendFile(int id, QString filename)
{
    for(int i=0;i<clientSocketList.size();i++)
        if(clientSocketList[i]->id==id)
        {
            clientSocketList[i]->sendFile(filename);
            break;
        }
}

void C_Server::onDisconnectedSIG(C_Socket*brokenSocket)
{
    clientSocketList.removeOne(brokenSocket);
}

