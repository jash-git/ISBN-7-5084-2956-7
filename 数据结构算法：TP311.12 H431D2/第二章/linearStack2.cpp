// ��ʽ��ջ��ʵ��linearStack2.cpp
#include "linearStack2.h"
#include<stdlib.h>
//���캯��
 LinStack::LinStack()
 {top=NULL;size=0;}
//��ʼ��ջ,����洢�ռ䲢�ÿ�
  void LinStack::InitStack(int L)
 {top=new StackNode[L];
  size=0;
 }
//�������������ջ
 void LinStack::CreateStack(int n,int m,int mark)
 {ElemType x,a[LEN/2];
  srand(n);
  for(int i=0;i<m;i++) a[i]=rand()%100;
  for(i=0;i<m-1;i++)
  {int k=i;
   for(int j=i+1;j<m;j++)
    if(a[k]>a[j]) k=j;
   if(k!=i)
   {x=a[k];a[k]=a[i];a[i]=x;}}
  for(i=0;i<m;i++)
  if(mark==1) Push(a[m-1-i]);//����
  else
   if(mark==-1) Push(a[i]);//����
   else Push(rand()%100);//����
 }
 int LinStack::StackSize()
 {return size;}
//���ջ
 void LinStack::ClearStack() {size=0;}
//ɾ��ջ
 void LinStack::DeleteStack()
 {delete top;}
//���ջ�Ƿ�Ϊ��
 bool LinStack::StackEmpty() {return size==0;}
//��ȡջ��Ԫ��
 ElemType LinStack::Peek()
 { return top->data;}
//��ջ�в���Ԫ��
 void LinStack::Push(const ElemType& item)
 {StackNode *newNode=new StackNode;
  newNode->data=item;newNode->next=top;
  top=newNode;
  size++;
 }
//��ջ��ɾ��Ԫ��
 ElemType LinStack::Pop()
 {if(size==0) {
   cerr<<"ջΪ��!"<<endl;exit(1);}
   StackNode *p=top->next;
   ElemType data=top->data;
   delete top;
   size--;
   top=p;
   return data;
 }
//���ջ�Ƿ�����
 bool LinStack::StackFull(ElemType m)
 {return size==m;}
//ջ�����
 void LinStack::StackPrint(ElemType m)
 {for(int i=0;i<m;i++)
   cout<<setw(3)<<Pop();
 }