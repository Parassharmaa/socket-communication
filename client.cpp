#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
//encryption header file
#include "crypto.h"



bool check_exit(const char *s) {
	for (int i = 0; i < strlen(s); ++i) {
		if (s[i] == '#') 
			return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	if (argc!=3) {
		cout<<"Please pass ip and port as args!"<<endl;
		return 0;
	}
	int client;
	int portnum = stoi(argv[2]);
	int bufsize = 1024;
	char buffer[bufsize];
	char * ip = argv[1];

	struct sockaddr_in serv_addr;

	client = socket(AF_INET, SOCK_STREAM, 0);
	if (client < 0) {
		cout << "ERROR establishing socket\n" << endl;
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portnum);
	inet_pton(AF_INET, ip, &serv_addr.sin_addr);

	cout << "\n--> Socket client created...\n";


	if (connect(client, (const struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0) {
		cout << "--> Connection to the server " << inet_ntoa(serv_addr.sin_addr) 
			 << " with port number: " 
			 << portnum << endl;		 
	}


	cout << "--> Waiting for server to confirm...\n";
	recv(client, buffer, bufsize, 0);
	cout << "--> Connection confirmed..\n";
	cout << "Enter # to end this connection: \n\n";

	string temp;
	while (true) {
		cout << "Client: ";
		cin.getline(buffer, bufsize);
		send(client, buffer, bufsize, 0);
		if (check_exit(buffer)) 
			break;

		cout << "Server: ";
		recv(client, buffer, bufsize, 0);
		cout << buffer;
		if (check_exit(buffer)) 
			break;
		cout << endl;	
	}

	close(client);
	cout << "\nDisconnected..." << endl;
	return 0;
}
