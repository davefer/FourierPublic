#include <array>
#include <iostream>
#include <fcntl.h>   
#include <termios.h>
#include <iostream>  
#include <string> 
#include <cstring>   
#include <errno.h>
#include <unistd.h>

#include "databroadcasterapp.h"
#include "serialreader.h"

using namespace std;

int SerialReader::ReadUart(const char* serialDev, DataPacket& data)
{
    cout << "SerialReader::ReadUart() called." << endl;
    
    int serial_port = open(serialDev, O_RDWR); 
    if (serial_port < 0) {
        std::cerr << "Error opening serial port: " << strerror(errno) << std::endl;
        return -1;
    }

    char read_buf[256];
            
    // TODO: Remove dummy data below.
    array<byte, 20> packetBuffer = {byte{0x54},byte{0x45},byte{0x53},byte{0x54},byte{0x01},
                                    byte{0x02},byte{0x03},byte{0x04},byte{0x01},byte{0x02},
                                    byte{0x03},byte{0x04},byte{0x01},byte{0x02},byte{0x03},
                                    byte{0x04},byte{0x01},byte{0x02},byte{0x03},byte{0x04}};
    data.fromByteArray(packetBuffer);
    DataBroadcasterApp::_dataRcvd = true;
    // TODO: End dummy data

    memset(&read_buf, '\0', sizeof(read_buf));
    int num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
    if (num_bytes < 0) {
        std::cerr << "Error reading: " << strerror(errno) << std::endl;
    } else if (num_bytes > 0) {
        cout << "Read " << num_bytes << " bytes. Received message: " << read_buf << std::endl;
    } else {
        cout << "No data available" << std::endl;
    }

    close(serial_port);

    return num_bytes;
}

// void _cfgSerial(char* serialDev)
// {
//     struct termios tty;
//     if (tcgetattr(serial_port, &tty) != 0) {
//         std::cerr << "Error getting termios attributes: " << strerror(errno) << std::endl;
//         close(serial_port);
//         return -1;
//     }

//     tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity
//     tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in transmission
//     tty.c_cflag &= ~CSIZE;  // Clear all bits that set the data size 
//     tty.c_cflag |= CS8;     // 8 bits per byte
//     tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
//     tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    
//     tty.c_lflag &= ~ICANON; // Disable canonical mode
//     tty.c_lflag &= ~ECHO;   // Disable echo
//     tty.c_lflag &= ~ECHOE;  // Disable erasure
//     tty.c_lflag &= ~ECHONL; // Disable new-line echo
//     tty.c_lflag &= ~ISIG;   // Disable interpretation of INTR, QUIT and SUSP
    
//     tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off software flow control
//     tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

//     tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
//     tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
    
//     tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
//     tty.c_cc[VMIN]  = 0;

//     cfsetispeed(&tty, B115200); // Set input baud rate to 115200
//     cfsetospeed(&tty, B115200); // Set output baud rate to 115200

//     if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
//         std::cerr << "Error setting termios attributes: " << strerror(errno) << std::endl;
//         close(serial_port);
//         return -1;
//     }
