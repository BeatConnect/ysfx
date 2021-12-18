#include "bcConnection.h"
#include "processor.h"

BcConnection::BcConnection(YsfxProcessor& proc) : p(proc)
{
}

BcConnection::~BcConnection()
{
}

void BcConnection::Initialize()
{
}

void BcConnection::send(String message)
{
    String m = "send";
    messageBlock.reset();
    messageBlock.setSize(m.length());
    messageBlock.copyFrom(m.getCharPointer(), 0, m.length());
    sendMessage(messageBlock);
}

void BcConnection::connectionMade()
{
    bool test = false;
}

void BcConnection::connectionLost()
{
    bool test = false;
}

void BcConnection::messageReceived(const MemoryBlock& message)
{
    String msg = message.toString();

    p.actionBroadcaster.sendActionMessage(msg);
    disconnect();
}
