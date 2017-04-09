def check_exit(s):
	if "#" in s.decode():
		print("Disconnected....")
		exit()


key = 4

def encrypt(s):
	t = ""
	s = s.decode()
	for i in s:
		t+=chr(ord(i)^key)
	return str.encode(t)

def decrypt(s):
	t = ""
	s = s.decode()
	for i in s:
		t+=chr(ord(i)^key)
	return str.encode(t)