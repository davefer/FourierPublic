/**
 * @file databroadcaster.h
 * @brief This is the main header file for the DataBroadcasterApp class.
 * 
 * @author David Ferreira
 * @date 2025-05-27
 */

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
    static void _txNetworkPacket(DataPacket& data);
    void _readCfg(string cfgPathFile);
    string serialDev;
    static DataPacket dataPacket;

};