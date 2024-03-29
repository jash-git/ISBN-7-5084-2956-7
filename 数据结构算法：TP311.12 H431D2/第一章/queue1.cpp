//顺序循环队列的实现queue1.cpp
#include<stdio.h>
#include "queue1.h"
//构造函数
 cirqueue::cirqueue()
 {front=rear=count=0;}
// 判断队空
int cirqueue::queueempty() {
  return count==0;}
// 判断队满
int cirqueue::queuefull(){
  return count==QueueSize;}
// 入队(队列的插入)
void cirqueue::enqueue(datatype x)
//在队列中插入一元素e为Q的新队尾元素
 {if(queuefull()) printf("队列满.\n");
  count++;
  data[rear]=x;
  rear=(rear+1)%QueueSize;
  //rear指针后移
 }
// 出队(队列的删除)
datatype cirqueue::dequeue()
//若队列不空则删除队列头部元素并用e返回其值
 {datatype temp;
  if(queueempty())
   printf("队列空.\n");
  temp=data[front];
  count--;
  //front指针后移
  front=(front+1)%QueueSize;
  return temp;
 }
// 取队列的头元素
datatype cirqueue::queuefront()
 {if(queueempty())
    printf("队列空.\n");
  return data[front];}
//求队列的长度(即队列的元素个数)
int cirqueue::QueueLength()
{return count;}


