#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <thread>

#include "databroadcasterapp.h"

using namespace std;

DataBroadcasterApp::DataBroadcasterApp()
{
    cout << "DataBroadcaster contructor" << endl;

    // Load cfg file
    // _readCfg("../../config.json");

    serialDev = "/dev/tty2";

    cout << "Monitoring UART on device: " << serialDev << endl;

    thread readThread(_readUartTask);
    thread bcastThread(_sendNetBcastTask);

    readThread.join();
    bcastThread.join();

}

void DataBroadcasterApp::_readUartTask()
{
    while(true)
    {
        // Will be moved later
        SerialReader::ReadUart();
    }
}

void DataBroadcasterApp::_sendNetBcastTask()
{
    while(true)
    {
        cout << "Sending network message" << endl;
    }
}