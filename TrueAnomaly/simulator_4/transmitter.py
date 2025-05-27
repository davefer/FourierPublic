import serial

class SerialTransmitter:

    def txUart(data):

        try:
            ser = serial.Serial("/dev/tty2", 9600)
            print(f"Port {ser.name} open: {ser.is_open}")

            # TODO: Emergency test data - to be removed when problem fixed.
            # prelimData = b"\x54,\x45,x\53,\x54,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01"
            # data = bytearray(prelimData)

            data = bytearray(data.encode('utf-8'))
            bytes_written = ser.write(data)
            ser.flush()
            string_data = data.decode()
            print(f"Sent: {data}. {bytes_written} bytes written.\n")

        except serial.SerialException as e:
            print(f"Error: {e}")

        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()
                print(f"Port {ser.name} closed")


