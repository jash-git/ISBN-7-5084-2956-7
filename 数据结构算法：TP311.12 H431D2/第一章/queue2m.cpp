// ˳��ѭ�����е�Ӧ��queue2m.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include "queue2.cpp"
void main()
{cout<<"queue2m.cpp���н��:\n";
 cirqueue MyQueue;
 int i,m,x,a[3];
 cout<<"��������������������m:";cin>>m;
 srand(m);
 cout<<"����˳��ѭ������MyQueue:\n";
 for(i=0;i<QueueSize;)
  {x=rand()%1000;
   if(100<=x&&x<=999)
    {MyQueue.enqueue(x);i++;}}
 cout<<"��˳��ѭ������MyQueue�ĳ���:";
 cout<<MyQueue.QueueLength()<<endl;
 cout<<"���˳��ѭ������MyQueue:\n";
 cout<<"ͬʱ����һ����λ���Ƿ�Ϊ������.\n";
 while(!MyQueue.queueempty())
  {x=MyQueue.dequeue();
   cout<<setw(4)<<x;
   a[0]=x%10;
   x=x/10;a[1]=x%10;
   x=x/10;a[2]=x;
   if(a[0]!=a[2]) cout<<"���ǻ�����!\n";
   if(a[0]==a[2]) cout<<"�ǻ�����!\n";
  }
 cin.get();cin.get();}

