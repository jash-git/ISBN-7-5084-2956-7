//��������������ز����Ĳ���TBSTree1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "TBSTree1.h"

void main()
{cout<<"TBSTree1M.cpp���н��:\n";
 THNode<char> *q,*p;
 TBSTree<char> t;
 q=t.MakeCharT(q,2);
 cout<<"���������������������������Ϊ:\n";
 t.InThread(q);
 t.ThInorder(q);
 TBSTree<char> d;
 p=d.MakeCharT(p,1);
 cout<<"\n���������������������������Ϊ:\n";
 d.InThread(p);
 d.ThInorder(p);
 cin.get();
}










