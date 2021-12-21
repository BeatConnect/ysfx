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
    Logger::writeToLog("Connection made!");
}

void BcConnection::connectionLost()
{
    Logger::writeToLog("Connection lost boooooo");
}

void BcConnection::messageReceived(const MemoryBlock& message)
{
    String msg = message.toString();
    Logger::writeToLog("Message received: " + msg);

    File file(msg);
    p.loadJsfxFile(file.getFullPathName(), nullptr, true);
    
    disconnect();
}
