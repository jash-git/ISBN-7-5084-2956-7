//˳��ջ�Ĳ���stackmain.cpp
#include<iostream.h>
#include<iomanip.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef int Status ;
typedef struct STU{
  char name[10];
  char stuno[10];
  int age;
  int score;
}SElemType;
void StackPrintElem(SElemType *e)
{cout<<"����   ѧ��  ���� �ɼ�\n";
 cout<<e->name<<setw(8)<<e->stuno;
 cout<<setw(4)<<e->age;
 cout<<setw(5)<<e->score<<endl;
}
#include"stack.cpp"
void main()
{ SElemType e;
  SqStack *Sa;
  cin.clear();
  cout<<"stackmain.cpp���н��:\n";
  Sa->InitStack(&Sa);
  strcpy(e.name,"stu1");
  strcpy(e.stuno,"100001");
  e.age=20;
  e.score=87;
  cout<<"����ջ�ǿ�ջ!\n";
  cout<<"���ڵ���ѹջ����!\n";
  Sa->Push(e);
  cout<<"����ջ��һ��Ԫ��!\n";
  StackPrintElem(&Sa->GetTop());
  if(Sa->StackEmpty()) cout<<"ջSa��!\n";
  else cout<<"ջSa�ǿ�!\n";
  strcpy(e.name,"stu3");
  strcpy(e.stuno,"100002");
  e.age=21;
  e.score=90;
  Sa->Push(e);
  cout<<"����ջ�ж���Ԫ��!\n";
  StackPrintElem(&e);
  cout<<"ջSa�ĳ���:"<<Sa->StackLength()<<endl;
  cout<<"���ڽ�Ԫ��e����ջ!\n";
  Sa->Pop(&e);
  StackPrintElem(&e);
  cout<<"ջ��ʣ��Ԫ��:\n";
  Sa->StackTraverse(StackPrintElem);
  if(Sa->StackEmpty()) cout<<"ջSa��!\n";
  else cout<<"ջSa�ǿ�!\n";
  cin.get();
}

