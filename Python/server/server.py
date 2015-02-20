from socket import *

HOST = "localhost"
PORT = 5000
s = socket(AF_INET, SOCK_STREAM)
s.bind((HOST, PORT))
s.listen(1)
conn, addr = s.accept()
print("Connected by", addr)
while True:
    data = conn.recv(1024)
    print("Recived:", repr(data))
    reply = input("Relpy: ")
    conn.sendall(reply)

conn.close()
