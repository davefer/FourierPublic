import serial

class SerialTransmitter:

    def txUart(data):

        # try: 
        #     # Open and prep serial port
        #     tty = serial.Serial("/dev/tty2", 921600, timeout=1)
        #     tty.flushInput()
        #     tty.flushOutput()

        #     # Send data to UART (tty1)
        #     tty.write(data)

        #     tty.close()

        #     # Log activity
        #     print(f"Data sent: {data}")

        # except serial.SerialException as expt:
        #     # Log serial-specific exception
        #     print(f"Error: Unable to open serial port")

        # except Exception as expt:
        #     # Log Unknown Exception
        #     print(f"An unexpected error has occurred.")

        try:
            ser = serial.Serial("/dev/tty2", 921600)
            print(f"Port {ser.name} open: {ser.is_open}")

            # TODO: Emergency test data - to be removed when problem fixed.
            prelimData = b"\x54,\x45,x\53,\x54,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01,\x00,\x00,\x00,\x01"
            data = bytearray(prelimData)

            ser.write(data)
            string_data = data.decode()
            print(f"Sent: {data}")

        except serial.SerialException as e:
            print(f"Error: {e}")

        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()
                print(f"Port {ser.name} closed")


