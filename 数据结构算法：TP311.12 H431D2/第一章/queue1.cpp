//˳��ѭ�����е�ʵ��queue1.cpp
#include<stdio.h>
#include "queue1.h"
//���캯��
 cirqueue::cirqueue()
 {front=rear=count=0;}
// �ж϶ӿ�
int cirqueue::queueempty() {
  return count==0;}
// �ж϶���
int cirqueue::queuefull(){
  return count==QueueSize;}
// ���(���еĲ���)
void cirqueue::enqueue(datatype x)
//�ڶ����в���һԪ��eΪQ���¶�βԪ��
 {if(queuefull()) printf("������.\n");
  count++;
  data[rear]=x;
  rear=(rear+1)%QueueSize;
  //rearָ�����
 }
// ����(���е�ɾ��)
datatype cirqueue::dequeue()
//�����в�����ɾ������ͷ��Ԫ�ز���e������ֵ
 {datatype temp;
  if(queueempty())
   printf("���п�.\n");
  temp=data[front];
  count--;
  //frontָ�����
  front=(front+1)%QueueSize;
  return temp;
 }
// ȡ���е�ͷԪ��
datatype cirqueue::queuefront()
 {if(queueempty())
    printf("���п�.\n");
  return data[front];}
//����еĳ���(�����е�Ԫ�ظ���)
int cirqueue::QueueLength()
{return count;}


