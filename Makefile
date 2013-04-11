all:proxy_epoll
proxy_epoll:proxy_epoll.h proxy_epoll.c
	g++ -o proxy_epoll proxy_epoll.h proxy_epoll.c
clean:
	rm proxy_epoll
