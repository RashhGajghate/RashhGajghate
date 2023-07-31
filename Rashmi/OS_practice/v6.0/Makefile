all: client-arm server-arm

client-arm: 
	arm-linux-gnueabihf-gcc client.c -o client-arm -lpthread
server-arm: 
	arm-linux-gnueabihf-gcc server.c -o server-arm -lpthread
clean:
	rm -f client-arm server-arm


