#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <thread>

#include "databroadcasterapp.h"
#include "sighandler.h"

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
    string dev("/dev/tty2");

    while(true)
    {
        
        SerialReader::ReadUart("/dev/tty2");
    }
}

void DataBroadcasterApp::_sendNetBcastTask()
{
    while(true)
    {
        cout << "Sending network message" << endl;
    }
}