from transmitter import SerialTransmitter
from listener import Listener
from imupacket import ImuPacket

from reader import Reader

# Create some dummy data
# txData = b"Hello from Simulator."
rxData = b"undefined"

tx = SerialTransmitter
rx = Listener
imuPacket = ImuPacket

reader = Reader

while True:
    # tx.txUart(imuPacket.Data)
    tx.txUart(f"Test\n")
    #reader.read()
    # tx.txUart("TEST")
    #rxData = rx.listen()

    # if rxData == imuPacket.Data:
    #     print("Success")

    # else:
    #     print("Failure")




