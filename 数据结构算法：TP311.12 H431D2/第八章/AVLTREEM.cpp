//ƽ������������������AVLTREEM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>
#include "AVLTREE.H"
TNode<char> *q;
void main()
{cout<<"AVLTREEM.cpp���н��:\n";
 int i;
 char test[50]="abxyMNcdefg";
 BSTree<char> t(q);
 //cout<<"input data:\n";
 //gets(test);
 for(i=0;test[i]!='\0';i++)
  t.BSTInsert(q,test[i]);
 cout<<"ƽ������������Ľ����="<<t.BSTSize()<<endl;
 cout<<"ƽ������������Ľ����="<<t.BSTreeCount(q)<<endl;
 cout<<"ƽ����������������="<<t.BSTreeDepth(q)<<endl;
 cout<<"ƽ�������������Ҷ�ӽ����="<<t.BSTreeLeafCount(q)<<endl;
 cout<<"�������ƽ�����������:\n";
 t.Inorder(q);
 getch();
 t.FreeBST(q);
}
