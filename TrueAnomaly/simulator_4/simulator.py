import serial

print('Starting serial data transmission.') 

# Create some dummy data
data = "Hello from Simulator."

while True:

    try: 
        # Open and prep serial port
        tty = serial.Serial('/dev/tty1', 921600)
        tty.flushInput()
        tty.flushOutput()

        # Send data to UART (tty1)
        tty.write(data)
        
        # Log activity
        print('Data sent: {data}')

        tty.close()

    except serial.SerialException as expt:
        # Log exception
        print('Error: Unable to open serial port')

    except Exception as expt:
        # Log Exception
        print('An unexpected error has occurred.')


