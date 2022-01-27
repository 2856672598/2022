.PHONY:all 
all: Server Client
Server:Server.cc
	g++ $^ -o $@
Client: Client.cc 
	g++ $^ -o $@

.PHONY: clean
clean:
	rm -rf Server Client
