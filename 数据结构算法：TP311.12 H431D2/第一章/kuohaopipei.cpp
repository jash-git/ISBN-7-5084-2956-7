//�κ�ƥ��ļ���kuohaopipei.cpp
#include<iostream.h>
#include<malloc.h>
#include<iomanip.h>
#include<stdlib.h>
typedef char Status;
typedef char SElemType;
#include "stack.cpp"
void main()
{SqStack *p;
 int n,m=32,q=0;
 char ch,ca,cd;
 cout<<"kuohaopipei.cpp���н��:\n";
 cout<<"���������ַ�����:";
 p->InitStack(&p);
 for(n=1;n<m;n++)
 {cin>>ch;
  if(ch=='[') p->Push(ch);
  if(ch=='(') p->Push(ch);
  if(ch=='{') p->Push(ch);
  if(ch==']')
   {ca=p->Pop(&cd);
    if(ca=='[') cout<<ca<<"��"<<ch<<"��ƥ���!\n";
    else
     {cout<<ca<<"��"<<ch<<"����ƥ���!\n";q++;}}
  if(ch==')')
   {ca=p->Pop(&cd);
    if(ca=='(') cout<<ca<<"��"<<ch<<"��ƥ���!\n";
    else
     {cout<<ca<<"��"<<ch<<"����ƥ���!\n";q++;}}
  if(ch=='}')
   {ca=p->Pop(&cd);
    if(ca=='{') cout<<ca<<"��"<<ch<<"��ƥ���!\n";
    else
     {cout<<ca<<"��"<<ch<<"����ƥ���!\n";q++;}}
  if(p->StackEmpty()) break;}
 if(q>=1) cout<<"�κ����в�ƥ��!\n";
 else cout<<"�κ�����ƥ��!\n";
 cin.get();cin.get();}








