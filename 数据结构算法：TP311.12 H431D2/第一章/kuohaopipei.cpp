//刮号匹配的检验kuohaopipei.cpp
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
 cout<<"kuohaopipei.cpp运行结果:\n";
 cout<<"输入括号字符序列:";
 p->InitStack(&p);
 for(n=1;n<m;n++)
 {cin>>ch;
  if(ch=='[') p->Push(ch);
  if(ch=='(') p->Push(ch);
  if(ch=='{') p->Push(ch);
  if(ch==']')
   {ca=p->Pop(&cd);
    if(ca=='[') cout<<ca<<"与"<<ch<<"是匹配的!\n";
    else
     {cout<<ca<<"与"<<ch<<"不是匹配的!\n";q++;}}
  if(ch==')')
   {ca=p->Pop(&cd);
    if(ca=='(') cout<<ca<<"与"<<ch<<"是匹配的!\n";
    else
     {cout<<ca<<"与"<<ch<<"不是匹配的!\n";q++;}}
  if(ch=='}')
   {ca=p->Pop(&cd);
    if(ca=='{') cout<<ca<<"与"<<ch<<"是匹配的!\n";
    else
     {cout<<ca<<"与"<<ch<<"不是匹配的!\n";q++;}}
  if(p->StackEmpty()) break;}
 if(q>=1) cout<<"刮号序列不匹配!\n";
 else cout<<"刮号序列匹配!\n";
 cin.get();cin.get();}








