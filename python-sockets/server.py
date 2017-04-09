import socket
from util import check_exit, encrypt, decrypt
import sys


if len(sys.argv)!=2:
	print("No options passed.")
	exit()

HOST = ""
PORT = int(sys.argv[1])
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen(1)
    print("Enter # to disconnect.")
    print("Waiting for connection....")
    conn, addr = s.accept()
    with conn:
        print('Connection established at ip:{}, port:{}'.format(addr[0], PORT))
        print("--"*5)
        print("Waiting for client response...")
        while True:
            data = decrypt(conn.recv(1024))
            print("Client:", data.decode())
            check_exit(data)
            print("Server:", end="")
            d = str.encode(input())
            conn.sendall(encrypt(d))
            check_exit(d)