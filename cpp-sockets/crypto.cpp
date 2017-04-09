#include "crypto.h"
#include <cstring>
#include <iostream>

using namespace std;

int key = 3;

char* encrypto(string msg) {
	string t = "";
		for(int i=0;i<msg.length(); i++) {
			t+= char(int(msg[i])^key);
	}

	char *a = new char[t.size()+1];
	a[t.size()]=0;
	memcpy(a,t.c_str(),t.size());

	return a;
}

char* decrypto(string msg) {
	string t = "";
		for(int i=0;i<msg.length(); i++) {
			t+= char(int(msg[i])^key);
	}

	char *a = new char[t.size()+1];
	a[t.size()]=0;
	memcpy(a,t.c_str(),t.size());

	return a;
}

