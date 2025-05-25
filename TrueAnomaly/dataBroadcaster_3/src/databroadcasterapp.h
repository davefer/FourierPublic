#pragma once

#include <string>
#include "datapacket.h"
#include "serialreader.h"

using namespace std;

class DataBroadcasterApp
{
    friend SerialReader;
    
public:
    DataBroadcasterApp();

private:
    // static SerialReader reader;
    static bool _dataRcvd;
    static void _readUartTask();
    static void _sendNetBcastTask();
    static void _txNetworkPacket(DataPacket& dataPacket);
    void _readCfg(string cfgPathFile);
    string serialDev;
    static DataPacket dataPacket;

};