#ifndef PROXY_EPOLL
#define PROXY_EPOLL
// write by Daniel 
/*
* 功能：将普通进程改造成守护进程
* 参数：listenfd为服务器监听套接子 
*/
void daemonize(int listenfd);

/*
* 功能：设置描述符为非阻塞
* 参数：fd即为所要设置描述符
*/
int set_socket_noblock(int fd);

/*
* 功能：连接远程主机
* 参数：usersock是需要代理的用户socket,argv是main传进的参数
*/
int connect_isolate(int usersockfd, char *argv[]);

/*
* 功能：代理服务器主题部分，创建代理服务器，并且利用epoll模型进行相应的事件处理。
* 参数： proxy_port:代理服务端口 argv:main函数传进来关于
        远程主机地址及其服务端口信息
*/
void proxy(int proxy_port, char *argv[]);

/*
* 功能：重定向标准输入输出
* 原因：因为守护进程脱离控制终端，不能简单把出错信息写的标准输入输出，
* 此外可以调用syslogd守护进程,用户调用syslog().但有时syslog()系统调用
* 会不起作用，此时无法用syslog()记录出错信息。那么此时只能重定向标准输
* 入输出了。
* 参数：infile为重定向的标准输入文件名,outfile为重定向的标准输出文件名
* errfile为重定向的标准错误输出文件名。
*/
void redirect_stdIO(char *inFile, char *outFile, char *errFile);

/*
* 功能：输出错误信息，在文件/tmp/daemon.log
* 参数：msg为输出的错误信息
*/
void errout(char *msg);

#endif
