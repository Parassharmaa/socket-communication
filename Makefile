all: server client

server: server.cpp
	g++ server.cpp -o server -w

client: client.cpp
	g++ client.cpp -o client -w

clean:
	$(RM) client
	$(RM) server
