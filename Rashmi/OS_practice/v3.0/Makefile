all: client-arm server

client-arm: 
	arm-linux-gnueabihf-gcc client.c -o client-arm -lpthread
server: 
	gcc server.c -o server -lpthread
clean:
	rm -f client-arm server


