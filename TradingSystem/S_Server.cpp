#include "S_Server.h"
#include "Logic.h"
S_Server::S_Server()
{
    listen(QHostAddress::Any,50000);
}

void S_Server::incomingConnection ( qintptr socketDescriptor )
{
    m_serverLock.lock();
    S_Socket* newSocket=new S_Socket;
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
    emit toDisplay("用户"+QString::number(availableID)+"登入,IP: "+newSocket->peerAddress().toString());
    m_serverLock.unlock();
}

//num=-1表示广播
void S_Server::sendMessage(int num, QString message)
{
    if(num != -1)
    {
        for(int i=0;i<clientSocketList.size();i++)
            if(clientSocketList[i]->id==num)
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

void S_Server::onDisconnectedSIG(S_Socket*brokenSocket)
{
    clientSocketList.removeOne(brokenSocket);
}
