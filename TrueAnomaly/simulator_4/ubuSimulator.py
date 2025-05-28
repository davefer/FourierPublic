import os
import io

try:
    tty_fd = os.open("/dev/tty1", os.O_RDWR | os.O_NOCTTY)
    tty = io.TextIOWrapper(io.FileIO(tty_fd, "r+"))

    tty.write("Hello from Python on tty1!\n")
    tty.flush() # Ensure the message is sent

    # Optional: Read input from tty1
    # line = tty.readline()
    # print("Received:", line.strip())
except OSError as e:
    print(f"Error accessing tty1: {e}")
finally:
    if 'tty_fd' in locals():
        os.close(tty_fd)