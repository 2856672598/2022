.PHONY:all 
all: Server Client
Server:Server.cc
	g++ $^ -o $@ -std=c++11
Client: Client.cc 
	g++ $^ -o $@

.PHONY: clean
clean:
	rm -rf Server Client
