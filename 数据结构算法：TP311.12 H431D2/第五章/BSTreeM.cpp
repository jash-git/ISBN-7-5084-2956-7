//������������ز����Ĳ���BSTreeM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "BSTree.h"
#include "BSTree.cpp"
void main()
{cout<<"BSTreeM.cpp���н��:\n";
 char b[50]="abxycdMNefgzkl";
 BSTree<char> t,*B;
 int n,m=14;
 t.InitBSTree(B);
 t.CreateBSTree(B,b,m);
 n=t.BSTreeCount(B);
 cout<<"���������������н����="<<n<<endl;
 if(!t.BSTreeEmpty(B))
   cout<<"�����������ǿ�!\n";
 else
   cout<<"����������Ϊ��!\n";
 cout<<"�����������������:\n";
 t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"���������������="<<n<<endl;
 n=t.BSTreeLeafCount(B);
 cout<<"����������������Ҷ�ӽ����="<<n<<endl;
 cout<<"�������������Ĺ�����������������:\n(";
 t.PrintBSTree(B);cout<<')'<<endl;
 if(t.Find(B,'d')) cout<<"���ҳɹ�!\n";
 else cout<<"���Ҳ��ɹ�!\n";
 if(t.Update(B,'d','D')) cout<<"���³ɹ�!\n";
 else cout<<"���²��ɹ�!\n";
 cout<<"�����������������:\n";
 t.Inorder(B);cout<<endl;
 t.Insert(B,'m');
 cout<<"�����������������:\n";
 t.Inorder(B);cout<<endl;
 t.Insert(B,'n');
 cout<<"�����������������:\n";
 t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"���������������="<<n<<endl;
 if(t.Delete(B,'e')) cout<<"ɾ���ɹ�!\n";
 else cout<<"ɾ�����ɹ�!\n";
 cout<<"�����������������:\n";
 t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"���������������="<<n<<endl;
 cin.get();}



