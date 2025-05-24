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

    // TODO: This thread task should perhaps use a timer to call ReadUart()
    //       every 80ms.

    while(true)
    {
        
        SerialReader::ReadUart("/dev/tty2");
    }
}

void DataBroadcasterApp::_sendNetBcastTask()
{
    while(true)
    {
        // TODO: This thread task should perhaps watch a flag to react immediately
        //       When data is available to broadcast (instead of guesstimating if
        //       new data is available).
        if( _dataRcvd == true)
        {
            cout << "Sending network message" << endl;
            // TODO: Broadcast network packet on localhost

        }
    }
}

void _txNetworkPacket()
{
    // TODO: Transmit network message (UDP) containing data packet read from UART
}