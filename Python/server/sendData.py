import socket
import time

HOST = "localhost"
PORT = 6000

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

while True:
    data = input()
    s.sendto(data.encode(), (HOST,PORT))