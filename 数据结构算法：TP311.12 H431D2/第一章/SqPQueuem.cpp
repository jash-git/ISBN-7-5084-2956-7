// ˳�����ȼ����е�Ӧ��SqPQueuem.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include "SqPQueue.cpp"
void main()
{cout<<"SqPQueuem.cpp���н��:\n";
 SqPqueue MyQueue;
 datatype task;
 int i,m;
 cout<<"��������������������m:";cin>>m;
 srand(m);
 cout<<"����˳�����ȼ�����MyQueue:\n";
 for(i=0;i<MaxSize;i++)
 {task.taskNo=i+1;
  task.priority=rand()%10;
  MyQueue.InsertPQ(task);}
 cout<<"��˳�����ȼ�����MyQueue�ĳ���:";
 cout<<MyQueue.PQueueSize()<<endl;
 cout<<"���˳�����ȼ�����MyQueue:\n";
 cout<<"��� ����� ���ȼ�\n";
 i=1;
 while(!MyQueue.PQueueEmpty())
  {cout<<setw(2)<<i;
   task=MyQueue.DeQueue();
   cout<<setw(6)<<task.taskNo;
   cout<<setw(7)<<task.priority<<endl;
   i++;}
 cin.get();cin.get();}

