//˳��ջ�Ĳ���stack1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>

typedef struct STU{
  char name[10];
  char stuno[10];
  int age;
  int score;
}DataType;

#include "stack1.h"
#include"stack1.cpp"

void StackPrintElem(DataType *e)
{cout<<"����   ѧ��  ���� �ɼ�\n";
 cout<<e->name<<setw(8)<<e->stuno;
 cout<<setw(4)<<e->age;
 cout<<setw(5)<<e->score<<endl;
}
void main()
{ DataType e;
  Stack Sa;//clrscr();
  int N=8;
  cout<<"stack1M.cpp���н��:\n";
  cout<<"���ȵ��ô�����ջ����!\n";
  Sa.SetStack(N);
  strcpy(e.name,"stu1");
  strcpy(e.stuno,"100001");
  e.age=20;
  e.score=87;
  Sa.Push(e);
  cout<<"ѹջ������ջ����һ��Ԫ��!\n";
  StackPrintElem(&Sa.Peek());
  if(Sa.StackEmpty()) cout<<"ջSa��!\n";
  else cout<<"ջSa�ǿ�!\n";
  strcpy(e.name,"stu3");
  strcpy(e.stuno,"100002");
  e.age=21;
  e.score=90;
  Sa.Push(e);
  cout<<"����ջ���ж���Ԫ��!\n";
  StackPrintElem(&Sa.Peek());
  cout<<"ջSa�ĳ���:"<<Sa.StackSize()<<endl;
  cout<<"���ڽ�Ԫ��e����ջ!\n";
  Sa.Pop(e);
  StackPrintElem(&e);
  cout<<"ջ��ʣ��Ԫ��:\n";
  Sa.StackTraverse(StackPrintElem);
  if(Sa.StackEmpty()) cout<<"ջSaΪ��ջ!\n";
  else cout<<"ջSaΪ�ǿ�ջ!\n";
  cin.get();
}

