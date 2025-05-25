Overview:

The idea of this solution is that the Python script called 
simulator_4/simulator.py will be run and then the executable 
dataBroadcaster_3/DataBroadcaster will be run.

The simulator.py will send a byte array over the serial port /dev/tty2 where
it will be read by the DataBroadcaster app and retransmitted on localhost
using UDP protocol back to the simulator.py script which will validate the
data.

UNFORTUNATELY, the step where DataBroadcaster app reads the data from /dev/tty2
is not working at this time. I suspect this has to do with some nuance of
permissions on the /dev/tty2 device on Ubuntu Linux. I continue to investigate
the cause of the problem.

Specific assessment requirements:

Req 1)
The code that parses the incoming packet can be found in the files 
datapacket.h and datapacket.cpp in the dataBroadcaster_3 project.

Req 2) 
In the event that the host were to communicate the data packet above
big-endian system, function calls such as htonl() would be added to the above
class to serialize the 4 float fields of the packet data such that their bytes
were swapped to a big-endian format.

In a production setting, these 4 float values:
    Packet_Count
    X_Rate_rdps
    Y_Rate_rdps
    Z_Rate_rdps
would always be byte-swapped to big-endian during the outgoing serialization
for network broadcast.

Req 3)
The included project, dataBroadcaster_3 answers the third requirement
for a multi-threaded solution that respondes to incoming UART (serial)
data and broadcasts the data back on the localhost network every 80ms.

The thread tasks 
    DataBroadcasterApp::_readUartTask() and
    DataBroadcasterApp::_tx_sendNetBcastTask()
manage the duties of reading incoming messages on the UART and transmitting
data via UDP protocol on localhost, respectively.

Req 4)
The Python scripts in the simulator_4 project handle sending data (byte array)
over the UART and receiving the same data in response over localhost. This
part of the project is still in progress.