//��������������ز����Ĳ���TBSTree2M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "TBSTree2.h"
#include "ITBSTree2.h"
void main()
{cout<<"TBSTree2M.cpp���н��:\n";
 THNode<char> *q,*p;
 q=MakeCharT(q,2);
 ITBSTree<char> t(q);
 t.CreatInThread();
 cout<<"�����������������������Ϊ:\n";
 t.First();
 cout<<"\n���������������������Ϊ:\n";
 t.Last();
 p=MakeCharT(p,1);
 ITBSTree<char> d(p);
 d.CreatInThread();
 cout<<"\n�����������������������Ϊ:\n";
 d.First();
 cout<<"\n���������������������Ϊ:\n";
 d.Last();
 cin.get();
}










