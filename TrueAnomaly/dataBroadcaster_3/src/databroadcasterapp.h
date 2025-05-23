#pragma once

#include <string>
#include "serialreader.h"

using namespace std;

class DataBroadcasterApp
{
public:
    DataBroadcasterApp();

private:
    // static SerialReader reader;
    static bool _dataRcvd;
    static void _readUartTask();
    static void _sendNetBcastTask();
    static void _txNetworkPacket();
    void _readCfg(string cfgPathFile);
    string serialDev;

};