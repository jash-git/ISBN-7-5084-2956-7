//��������������ز����Ĳ���TBSTreeM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "TBSTree.h"
#include "ITBSTree.h"

void main()
{cout<<"TBSTreeM.cpp���н��:\n";
 THNode<char> *q,*p,*r;
 q=MakeCharT(q,3);
 ITBSTree<char> t(q);
 t.CreatInThread();
 cout<<"���������������������������Ϊ:\n";
 for(t.First();!t.EndOfNext();t.Next())
   cout<<t.Data()<<"  ";
 cout<<"\n�������������������������Ϊ:\n";
 for(t.Last();!t.EndOfPrior();t.Prior())
   cout<<t.Data()<<"  ";
 p=MakeCharT(p,2);
 ITBSTree<char> d(p);
 d.CreatInThread();
 cout<<"\n���������������������������Ϊ:\n";
 for(d.First();!d.EndOfNext();d.Next())
   cout<<d.Data()<<"  ";
 cout<<"\n�������������������������Ϊ:\n";
 for(d.Last();!d.EndOfPrior();d.Prior())
   cout<<d.Data()<<"  ";
 r=MakeCharT(r,1);
 ITBSTree<char> h(r);
 h.CreatInThread();
 cout<<"\n���������������������������Ϊ:\n";
 for(h.First();!h.EndOfNext();h.Next())
   cout<<h.Data()<<"  ";
 d.InsertR(p,r);
 cout<<"\n����������������������������������Ϊ:\n";
 for(d.First();!d.EndOfNext();d.Next())
   cout<<d.Data()<<"  ";
 cin.get();
}










