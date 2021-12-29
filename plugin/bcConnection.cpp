#include "bcConnection.h"
#include "processor.h"

BcConnection::BcConnection(YsfxProcessor& proc) : p(proc)
{
}

BcConnection::~BcConnection()
{
    disconnect();
}

void BcConnection::Initialize()
{
}

void BcConnection::send(String message)
{
    messageBlock.reset();
    messageBlock.setSize(message.length());
    messageBlock.copyFrom(message.getCharPointer(), 0, message.length());
    sendMessage(messageBlock);
}

void BcConnection::connectionMade()
{
}

void BcConnection::connectionLost()
{
}

void BcConnection::messageReceived(const MemoryBlock& message)
{
    File file(message.toString());
    p.loadJsfxFile(file.getFullPathName(), nullptr, true);
    
    disconnect();
}
