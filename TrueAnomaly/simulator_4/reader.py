import time
import serial

class Reader:

    def read():
        ser = serial.Serial("/dev/tty2", 9600, timeout = 5)

        data = ""

        if ser.in_waiting > 0:
            data = ser.read(ser.in_waiting)
            print("Received:", data.decode('utf-8'))
        else:
            print("No data available")
            time.sleep(1)

        ser.close()

        print(f"Read: {data}")

        return data