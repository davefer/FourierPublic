#pragma once

#include "serialreader.h"

class DataBroadcasterApp
{
public:
    DataBroadcasterApp();

private:
    // static SerialReader reader;
    static void _readUartTask();
    static void _sendNetBcastTask();

};