import socket
import time

HOST = "localhost"
PORT = 6000
data = "Server test data"

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

while True:
    s.sendto(data.encode(), (HOST,PORT))
    print(data)
    time.sleep(1)
