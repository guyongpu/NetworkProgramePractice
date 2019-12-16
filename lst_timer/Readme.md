# 程序说明
## 程序功能
- main.cpp  
服务器使用epoll模型，采用双向升序定时器链表，超时时间设置为5秒，意思是每隔5秒程序发出SIGALRM信号，当信号出现时，将超时标志timeout置为true，但并不立即处理超时函数，而是优先处理其他连接，最后进入timer_handler函数，然后在tick()中依次遍历链表中的节点，与当前时间进行对比，如果超时则进行超时处理函数cb_func,在cb_func中，将超时节点的客户端从epoll监听树上删除，并关闭该客户端连接。然后继续遍历节点，当遇到第一个未超时的节点时，说明后面的节点都未超时，则结束遍历，本轮超时处理结束。
返回epoll_wait继续阻塞等待。

- main2.cpp  
大致思路相同，改为使用epoll_wait自带的超时参数定期处理超时的定时器。
## 文件说明
github地址：[https://github.com/guyongpu/NetworkProgramePractice/tree/master/lst_timer](https://github.com/guyongpu/NetworkProgramePractice/tree/master/lst_timer)

|文件名|文件内容|
|---|:---|
|util_timer.h/cpp|  单个定时器的类实现，可以视为定时器链表的节点|
|sort_timer_lst.h/cpp|  双向升序定时器链表的类实现，包含对节点的增删改及超时处理函数等操作|
|main.cpp|测试主函数,使用alarm()函数生成SIGALRM定时信号|
|main2.cpp|测试主函数,使用epoll_wait自带的超时参数定期处理超时的定时器|

## 使用说明
~~~
- 第一种类型
# 编译main.cpp生成main
make
# 服务器端main运行
make run

- 第二种类型
# 编译main2.cpp生成main2
make main2
# 服务器端main2运行
make run2

# 客户端telnet连接测试
make connect
~~~

## 程序运行结果
- 客户端运行结果
~~~
yongpu@ubuntu:~/NetCode/lst_timer$ make connect 
telnet 127.0.0.1 8888
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
Connection closed by foreign host.
makefile:9: recipe for target 'connect' failed
make: *** [connect] Error 1

~~~
- 服务器端main运行结果
~~~
yongpu@ubuntu:~/NetCode/lst_timer$ make run 
./main 127.0.0.1 8888
Sever start run....

sockfd = new client


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 
timer tick


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 
timer tick


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 
timer tick


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 
timer tick
0th timer, expire = 1576464264
cb_func : close fd 7


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 


sockfd = pipefd[0]
signals[i] = 14 
Entry the timer_handler() 
^Cmake: *** wait: 没有子进程。 停止。
make: *** 正在等待未完成的任务....
make: *** wait: 没有子进程。 停止。
yongpu@ubuntu:~/NetCode/lst_timer$ 

~~~
- 服务器端main2运行结果
~~~
yongpu@ubuntu:~/NetCode/lst_timer$ make run2
./main2 127.0.0.1 8888
Sever start run....

the timeout is now 5000 mil-seconds

sockfd = new client

the timeout is now 5000 mil-seconds
number = 0. 
Entry the timer_handler() 
timer tick

the timeout is now 5000 mil-seconds
number = 0. 
Entry the timer_handler() 
timer tick

the timeout is now 5000 mil-seconds
number = 0. 
Entry the timer_handler() 
timer tick
0th timer, expire = 1576476196
cb_func : close fd 5

the timeout is now 5000 mil-seconds
^Cmakefile:11: recipe for target 'run2' failed
make: *** [run2] 中断

yongpu@ubuntu:~/NetCode/lst_timer$
~~~