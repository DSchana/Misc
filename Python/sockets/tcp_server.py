import socket
import threading

bind_ip = "0.0.0.0"
bind_port = 9999

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# pass the IP and port we want the server to listen on
server.bind((bind_ip, bind_port))

# tell the server to listen with a maximum backlog of 5 connections
server.listen(5)

print("[*] Listening on %s:%d" % (bind_ip, bind_port))

# this is our client handling thread
def handle_client(client_socket):
	# print what the client sends
	request = client_socket.recv(1024).decode("UTF-8")

	print("[*] Recieved", request)

	# send back a packet
	client_socket.send(b"ACK!")

	client_socket.close()

while True:
	# wait for client to connect
	client,addr = server.accept()

	print("[*] Accepted connection from %s:%d" % (addr[0], addr[1]))

	# call client tread to handle incoming data
	client_handler = threading.Thread(target=handle_client, args=(client,))
	client_handler.start()
