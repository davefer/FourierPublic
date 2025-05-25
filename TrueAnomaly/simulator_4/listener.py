
import socket

class Listener:

    def listen():
        print("Listening")

        UDP_IP = "127.0.0.1"  # Localhost
        UDP_PORT = 5005

        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # UDP
        sock.bind((UDP_IP, UDP_PORT))

        print(f"Listening on {UDP_IP}:{UDP_PORT}")

        # while True:
        data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
        print(f"Received message: {data} from {addr}")
