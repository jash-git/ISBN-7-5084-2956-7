// 链式队列的测试linqueuem.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "linqueue.cpp"
void main()
{cout<<"linqueuem.cpp运行结果:\n";
 linkqueue MyQueue;
 int i,m,x,a[3];
 cout<<"输入产生随机数的种子数m:";cin>>m;
 srand(m);
 cout<<"生成链式队列MyQueue:\n";
 for(i=0;i<QueueSize;)
  {x=rand()%1000;
   if(100<=x&&x<=999)
    {MyQueue.enqueue(x);i++;}}
 cout<<"求链式队列MyQueue的长度:";
 cout<<MyQueue.QueueLength()<<endl;
 cout<<"输出链式队列MyQueue:\n";
 cout<<"同时求任一个三位数是否为回文数.\n";
 while(!MyQueue.queueempty())
  {x=MyQueue.dequeue();
   cout<<setw(4)<<x;
   a[0]=x%10;
   x=x/10;a[1]=x%10;
   x=x/10;a[2]=x;
   if(a[0]!=a[2]) cout<<"不是回文数!\n";
   if(a[0]==a[2]) cout<<"是回文数!\n";}
 cin.get();cin.get();}

