.PHONY:ALL
ALL:TcpServer TcpClient

TcpClient: TcpClient.cc 
	g++ $^ -o $@ -std=c++11
TcpServer: TcpServer.cc 
	g++ $^ -o $@ -std=c++11
.PHONY:clean
clean:
	rm -rf TcpClient TcpServer

