# This test file will write / read to a COM port on Windows but not on
# Ubuntu Linux against "/dev/tty2". Why? 


import serial

while True:

    try:
        ser = serial.Serial('/dev/tty2', 9600, timeout = 1)

        if ser:
            print("Connected to: ", ser.name)

    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        exit()

    try:
        ser.write(b"Test from Python\n")

        while True: 
            data = ser.readline()
            if data:
                print("Received: ", data.decode().strip())

    except Exception as e:
        print(f"Error during communication: {e}")
    finally:
        # Close the serial port
        if ser.is_open:
            ser.close()
            print("Serial port closed")