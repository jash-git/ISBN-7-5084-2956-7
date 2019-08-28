//˳�����ȼ����е�ʵ��SqPQueue.cpp
#include "SqPQueue.h"
// �ж϶ӿ�
int SqPqueue::PQueueEmpty() {
  return count==0;}
// �ж϶���
int SqPqueue::PQueuefull(){
  return count==MaxSize;}
//���ع�ϵ�����С��<
int operator <(datatype &b,datatype &c)
  {return b.priority<c.priority;}
//���еĲ���
void SqPqueue::InsertPQ(datatype x)
{if(PQueuefull())
   {cerr<<"������.\n";exit(1);}
  data[count]=x;
   count++;
 }
//���е�ɾ��
datatype SqPqueue::DeQueue()
 {if(PQueueEmpty())
   {cerr<<"���п�.\n";exit(1);}
  datatype min=data[0];
  int minindex=0;
  for(int i=0;i<count;i++)
   if(data[i]<min)
    {min=data[i];minindex=i;}
  data[minindex]=data[count-1];
  count--;
  return min;
 }
// ȡ���е�ͷԪ��
datatype SqPqueue::PQueuefront()
 {if(PQueueEmpty())
   {cerr<<"���п�.\n";exit(1);}
  datatype min=data[0];
  for(int i=1;i<count;i++)
   if(data[i]<min)
    min=data[i];
  return min;
 }
//����е�Ԫ�ظ���
int SqPqueue::PQueueSize()
{return count;}


