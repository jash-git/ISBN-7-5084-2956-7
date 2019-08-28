//顺序堆栈的实现linearStack1.cpp
#include<stdlib.h>
#include "linearStack1.h"
//创建有序或无序栈
 void Stack::CreateStack(int n,int m,int mark)
 {ElemType x,a[LEN/2];
  int i,j;
  for(i=0;i<m;i++) a[i]=rand()%100;
  for(i=0;i<m-1;i++)
  {int k=i;
   for(j=i+1;j<m;j++)
    if(a[k]>a[j]) k=j;
   if(k!=i)
   {x=a[k];a[k]=a[i];a[i]=x;}}
  for(i=0;i<m;i++)
  if(mark==1) Push(a[m-1-i]);//升序
  else
   if(mark==-1) Push(a[i]);//降序
   else Push(rand()%100);//无序
 } 
//清空栈
 void Stack::ClearStack() {top=0;}
//检查栈是否为空
 bool Stack::StackEmpty() {return top==0;}
//读取栈顶元素
 ElemType Stack::Peek()
 {if(top==0) {cerr<<"栈为空!"<<endl;
      exit(1);}
   return stack[top];
 }
//向栈中插入元素
 void Stack::Push(const ElemType& item,int m)
 {if(top==m) {
   cerr<<"栈已满!"<<endl;exit(1);}
  top++;
  stack[top]=item;
 }
//从栈中删除元素
 ElemType Stack::Pop()
 {if(top==0) {
   cerr<<"栈为空!"<<endl;exit(1);}
   top--;
   return stack[top+1];
 }
//检查栈是否已满
 bool Stack::StackFull(int m)
 {return top==m;}
//栈的输出
 void Stack::StackPrint(int m)
 {for(int i=0;i<m;i++)
   cout<<setw(3)<<Pop();
 }