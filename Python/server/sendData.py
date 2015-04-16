import socket
import time

HOST = "localhost"
PORT = 6000

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)


data = "Server over router test"
print(data)
s.sendto(data.encode(), (HOST,PORT))