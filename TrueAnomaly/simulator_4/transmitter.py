import serial

class SerialTransmitter:

    def txUart(data):

        try: 
            # Open and prep serial port
            tty = serial.Serial("/dev/tty2", 921600, timeout=1)
            tty.flushInput()
            tty.flushOutput()

            # Send data to UART (tty1)
            tty.write(data)
            
            # Log activity
            print(f"Data sent: {data}")

            tty.close()

        except serial.SerialException as expt:
            # Log serial-specific exception
            print(f"Error: Unable to open serial port")

        except Exception as expt:
            # Log Unknown Exception
            print(f"An unexpected error has occurred.")


