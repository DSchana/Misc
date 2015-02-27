import socket

HOST = "0.0.0.0"
PORT = 6000

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind((HOST,PORT))
while True:
    print("Received:", s.recv(50))
