// ��ʽ��ջ�Ĳ���linearStack2m.cpp
#include<iostream.h>
#include<iomanip.h>
typedef int ElemType;
#include "linearStack2.cpp"
void main()
{cout<<"linearStack2m.cpp���н��:\n";
 int m,n;
 LinStack q,p,w;
 cout<<"��������������������n:";cin>>n;
 cout<<"����������ջq�ĳ���m:";cin>>m;
 cout<<"����ջq(����):\n";
 q.CreateStack(n,m,1);
 cout<<"qջ�Ľ�����="<<q.StackSize()<<endl;
 cout<<"���qջԪ��:\n";
 q.StackPrint(m);cout<<endl;
 cout<<"qջ:";
 if(q.StackFull(m)==1)
  cout<<"����!\n";
 else cout<<"δ��!\n";
 cout<<"����ջp(����):\n";
 p.CreateStack(n+10,m,-1);
 cout<<"pջ:";
 if(p.StackFull(m)==1)
  cout<<"����!\n";
 else cout<<"δ��!\n";
 cout<<"ɾ��Ԫ��Ϊ:"<<p.Pop()<<endl;
 cout<<"pջ:";
 if(p.StackEmpty()==1)
  cout<<"Ϊ��!\n";
 else cout<<"Ϊ�ǿ�!\n";
 cout<<"���pջԪ��:\n";
 p.StackPrint(m-1);cout<<endl;
 cout<<"����ջw(����):\n";
 w.CreateStack(2*n,m);
 cout<<"���wջԪ��:\n";
 w.StackPrint(m);cout<<endl;
 p.ClearStack();
 p.DeleteStack();
 cin.get();cin.get();}

