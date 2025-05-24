#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <thread>

#include "databroadcasterapp.h"
#include "sighandler.h"

using namespace std;

bool DataBroadcasterApp::_dataRcvd = false;

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
        // sleep for 80 ms before checking to see if new data has arrived
        this_thread::sleep_for(chrono::milliseconds(80));

        if(_dataRcvd == true)
        {
            cout << "Sending network message" << endl;
            // TODO: Broadcast network packet on localhost
            _txNetworkPacket();
            _dataRcvd = false;
        }

        // TODO:  Remove this line that sets _dataRcvd = true
        _dataRcvd = true;
    }
}

void DataBroadcasterApp::_txNetworkPacket()
{
    cout << "Inside _txNetworkPacket method." << endl;

    // TODO: Transmit network message (UDP) containing data packet read from UART    int socket_fd;
    // struct sockaddr_in broadcast_address;
    // const char* message = "Hello, Broadcast!";
    // int broadcast_permission = 1;

    // // Create socket
    // socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    // if (socket_fd < 0) {
    //     std::cerr << "Socket creation failed" << std::endl;
    //     return -1;
    // }

    // // Set socket options to allow broadcasting
    // if (setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast_permission, sizeof(broadcast_permission)) < 0) {
    //     std::cerr << "setsockopt failed" << std::endl;
    //     close(socket_fd);
    //     return -1;
    // }

    // // Configure broadcast address
    // memset(&broadcast_address, 0, sizeof(broadcast_address));
    // broadcast_address.sin_family = AF_INET;
    // broadcast_address.sin_addr.s_addr = inet_addr("127.255.255.255");
    // broadcast_address.sin_port = htons(12345); // Choose a port

    // // Send the broadcast message
    // if (sendto(socket_fd, message, strlen(message), 0, (struct sockaddr*)&broadcast_address, sizeof(broadcast_address)) < 0) {
    //     std::cerr << "sendto failed" << std::endl;
    //     close(socket_fd);
    //     return -1;

    return;
}