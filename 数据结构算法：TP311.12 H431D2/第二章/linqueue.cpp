//��ʽ���е�ʵ��linqueue.cpp
#include "linqueue.h"
// �ж϶ӿ�
int linkqueue::queueempty()
{return front==NULL&&rear==NULL;}
// �ж϶���
int linkqueue::queuefull()
{return count==QueueSize;}
// ���(���еĲ���)
void linkqueue::enqueue(datatype x)
//�ڶ����в���һԪ��eΪQ���¶�βԪ��
{queuenode *p;
 p=(queuenode *)malloc(sizeof(queuenode));
 p->data=x;
 p->next=NULL;
 if(!queueempty()){rear->next=p;rear=p;}
 else front=rear=p;
 count++;
}
// ����(���е�ɾ��)
datatype linkqueue::dequeue()
//�����в�����ɾ������ͷ��Ԫ�ز���e������ֵ
{datatype  x;
 queuenode *p;
 if(queueempty())
   {cerr<<"�����ѿ�\n";exit(1);}
 p=front;
 x=p->data;
 front=p->next;
 if(rear==p) rear=NULL;
 count--;
 delete p;
 return x;
}
// ȡ���е�ͷԪ��
datatype linkqueue::queuefront()
{if(queueempty())
   {cerr<<"���п�.\n";exit(1);}
 return front->data;
}
//����еĳ���(�����е�Ԫ�ظ���)
int linkqueue::QueueLength()
{return count;}

