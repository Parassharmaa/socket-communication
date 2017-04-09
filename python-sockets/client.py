import socket
from util import check_exit, encrypt, decrypt
import sys


if len(sys.argv)!=3:
	print("No options passed.")
	exit()
HOST = sys.argv[1]
PORT = int(sys.argv[2])


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    print("Socket Connected.")
    print("Enter # to disconnect....")
    while (1):
	    print("Client:", end="")
	    d = str.encode(input())
	    s.sendall(encrypt(d))
	    check_exit(d)
	    data = decrypt(s.recv(1024))
	    print("Server:", data.decode())
	    check_exit(data)
