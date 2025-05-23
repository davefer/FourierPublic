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
    static void _readUartTask();
    static void _sendNetBcastTask();
    void _readCfg(string cfgPathFile);
    string serialDev;

};