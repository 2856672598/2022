.PHONY:ALL
ALL:server client
	
server:server.cc
	g++ -o $@ $^ -std=c++11
client:client.cc 
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm server client fifo
