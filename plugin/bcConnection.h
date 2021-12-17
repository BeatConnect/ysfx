#pragma once

#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <memory>

using namespace juce;

class YsfxProcessor;

class BcConnection : public InterprocessConnection
{
public:
    BcConnection(YsfxProcessor& proc);
    virtual ~BcConnection();

    void Initialize();
    void send(String message);

    void connectionMade() override;
    void connectionLost() override;
    void messageReceived(const MemoryBlock& message) override;

    YsfxProcessor& p;
    MemoryBlock messageBlock;
    bool bcConnected = false;
};
