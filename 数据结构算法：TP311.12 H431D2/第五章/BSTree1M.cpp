//���������������Ͳ���BSTree1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "BSTree1.h"
TNode<char> *q;
void main()
{cout<<"BSTree1M.cpp���н��:\n";
 int i;
 char test[50]="abxycdMNefgzkl";
 BSTree<char> t(q);
 //cout<<"input data:\n";
 //gets(test);
 for(i=0;test[i]!='\0';i++)
  t.BSTInsert(q,test[i]);
 cout<<"�����������������:\n";
 t.Inorder(q);
 cout<<"\n�����������Ľ����="<<t.BSTSize()<<endl;
 cout<<"�����������Ľ����="<<t.BSTreeCount(q)<<endl;
 cout<<"���������������="<<t.BSTreeDepth(q)<<endl;
 cout<<"������������Ҷ�ӽ����="<<t.BSTreeLeafCount(q)<<endl;
 cout<<"Press any key and delete 'd'\n";
 getch();
 t.BSTDelete(q,'d');
 cout<<"�����������������:\n";
 t.Inorder(q);
 cout<<"\n�����������Ľ����="<<t.BSTSize()<<endl;
 cout<<"�����������Ľ����="<<t.BSTreeCount(q)<<endl;
 cout<<"���������������="<<t.BSTreeDepth(q)<<endl;
 cout<<"������������Ҷ�ӽ����="<<t.BSTreeLeafCount(q)<<endl;
 getch();
 t.FreeBST(q);
}

