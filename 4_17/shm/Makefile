.PHONY:ALL
ALL: client server

client:client.cc 
	g++ -o $@ $^ -std=c++11

server:server.cc
	g++ -o $@ $^ -std=c++11
.PHONY:clean 
clean:
	rm server client
