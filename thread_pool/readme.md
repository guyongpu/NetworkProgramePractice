# 简单的线程池模型

## 说明
&emsp;&emsp;这个是简单的线程池模型，运用任务队列；预先创建多个线程，然后每个线程都等待在条件变量上，任务队列是一个共享变量，所以需要使用互斥锁。  
&emsp;&emsp;当管理线程向队列中添加任务时，需要先获得锁，然后加入，再解锁；
&emsp;&emsp;当线程从任务队列中取任务时，同样要先获得锁；  
&emsp;&emsp;当要结束时，则broadcast唤醒所有线程，然后子线程执行pthrad_exit(NULL)退出.

## 运行
- 编译
~~~
g++ main.cpp thread_pool.h thread_pool.cpp  -o main -lpthread
./main
~~~
- 输出
~~~
yongpu@ubuntu:~/NetCode/thread_pool$ ./main
I will create 5 threads
tid 140663926880000 run
there are still 4 tasks need to handle
tid 140663943665408 run
tid 140663935272704 run
tid 140663952058112 run
tid 140663960450816 run
there are still 0 tasks need to handle
Now I will end all threads!!/ntid:140663926880000 idle
thread 140663926880000 will exit
tid:140663960450816 idle
thread 140663960450816 will exit
tid:140663935272704 idle
thread 140663935272704 will exit
tid:140663952058112 idle
thread 140663952058112 will exit
tid:140663943665408 idle
thread 140663943665408 will exit
there are still 0 tasks need to handle
Now I will exit from main
~~~
