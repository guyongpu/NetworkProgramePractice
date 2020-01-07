#include "thread_pool.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
class CMyTask: public CTask
{
public:
    CMyTask(){}
 
    inline int Run()
    {
//      printf("%s\n", (char*)this->m_ptrData);
        sleep(10);
        return 0;
    }
};
 
int main()
{
    CMyTask taskObj;
 
    char szTmp[] = "this is the first thread running";
    taskObj.SetData((void*)szTmp);
    CThreadPool threadPool(5);
 
    for(int i = 0; i < 5; i++)
    {
        threadPool.AddTask(&taskObj);
    }
    while(1)
    {
        printf("there are still %d tasks need to handle\n", threadPool.getTaskSize());
        if (threadPool.getTaskSize() == 0)
        {
           if (threadPool.StopAll() == -1)
           {
               printf("Now I will exit from main\n");
               break;
           }
        }
        sleep(2);
    }
 
    return 0;
}