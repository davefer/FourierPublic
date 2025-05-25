#include <fstream>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <unistd.h>
#include <cstring>

#include "databroadcasterapp.h"
#include "datapacket.h"
#include "sighandler.h"

using namespace std;

bool DataBroadcasterApp::_dataRcvd = false;
DataPacket DataBroadcasterApp::dataPacket;

DataBroadcasterApp::DataBroadcasterApp()
{
    cout << "DataBroadcaster contructor" << endl;

    // Load cfg file
    // _readCfg("../../config.json");

    serialDev = "/dev/tty2";

    cout << "Monitoring UART on device: " << serialDev << endl;

    thread readThread(_readUartTask); // TODO: Turn this back on. 
    thread bcastThread(_sendNetBcastTask);

    readThread.join(); // TODO: Turn this back on too.
    bcastThread.join();

}

void DataBroadcasterApp::_readUartTask()
{
    string dev("/dev/tty2");

    while(true)
    {
        // sleep for 80 ms before checking to see if new data has arrived
        this_thread::sleep_for(chrono::milliseconds(80));

        SerialReader::ReadUart("/dev/tty2", dataPacket);
    }
}

void DataBroadcasterApp::_sendNetBcastTask()
{
    while(true)
    {
        if(_dataRcvd == true)
        {
            cout << "Sending network message" << endl;

            // TODO: Broadcast network packet on localhost
            _txNetworkPacket(dataPacket);
            _dataRcvd = false;
        }

        // TODO:  Remove this line that sets _dataRcvd = true
        _dataRcvd = true;
    }
}

void DataBroadcasterApp::_txNetworkPacket(DataPacket& data)
{
    cout << "Inside _txNetworkPacket method." << endl;

    // TODO: Transmit network message (UDP) containing data packet read from UART    
    int socket_fd;
    struct sockaddr_in broadcast_address;

    // TODO: Change the object being sent to a byte array from DataPacket
    // string message = "Hello, Broadcast!";
    array<byte, 20> dataBuffer; // = {byte{0x54},byte{0x45},byte{0x53},byte{0x54}};
    data.toByteArray(dataBuffer);
    
    // TODO: Remove these lines that were only for testing
    // byte charBuffer[256];
    // memcpy(charBuffer, &dataBuffer, 20);
    cout << "Testing send with: " << &dataBuffer << endl;

    int broadcast_permission = 1;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd < 0) 
    {
        std::cerr << "Socket creation failed" << std::endl;
        return;
    }

    // Set socket options to allow broadcasting
    if (setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast_permission, sizeof(broadcast_permission)) < 0)
    {
        std::cerr << "setsockopt failed" << std::endl;
        close(socket_fd);
        return;
    }

    // Configure broadcast address
    memset(&broadcast_address, 0, sizeof(broadcast_address));
    broadcast_address.sin_family = AF_INET;
    broadcast_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    broadcast_address.sin_port = htons(5005); // Choose a port

    // Send the broadcast message
    if (sendto(socket_fd, &dataBuffer, 20, 0, (struct sockaddr*)&broadcast_address, sizeof(broadcast_address)) < 0) 
    {
        std::cerr << "sendto failed" << std::endl;
        close(socket_fd);
        return;
    }

    cout << "Message successfully broadcast." << endl;

    return;
}