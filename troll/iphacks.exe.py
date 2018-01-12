from urllib2 import urlopen
import os
import socket
import smtplib

HOST = "localhost"
PORT = 3000

print("Hacking in progress")

my_ip = urlopen('http://ip.42.pl/raw').read()

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))
s.sendall(str(my_ip))
data = s.recv(1024)
s.close()

print("Congrats, you've just been hacked")
