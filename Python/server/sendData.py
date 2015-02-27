import socket
import time

HOST = "0.0.0.0"
PORT = 6000

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

while True:
    data = "Server over router test"
    print(data)
    s.sendto(data.encode(), (HOST,PORT))
