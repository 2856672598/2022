.PHONY:all
all:server clinet

server : server.c
	gcc -o $@ $^
clinet :clinet.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf server clinet
