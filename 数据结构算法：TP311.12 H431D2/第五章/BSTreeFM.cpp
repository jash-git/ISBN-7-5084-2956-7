//���������������ز����Ĳ���BSTreeFM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include "BSTreeF.h"
#include "BSTreeF.cpp"
void main()
{cout<<"BSTreeFM.cpp���н��:\n";
 ElemType b[10]={{"1001",72},{"1002",84},{"1009",83},{"1010",75},
 {"1012",87},{"1013",79},{"1019",91},{"1020",84}};
 ElemType m={"1014",89},m2={"1016",90};
 int n,m1=8;
 char f[20]=".\\file.txt";
 BSTree<ElemType> t,*B;
 t.InitBSTree(B);
 t.CreateBSTree(B,b,m1);
 n=t.BSTreeCount(B);
 cout<<"���������������н����="<<n<<endl;
 if(!t.BSTreeEmpty(B))
   cout<<"�����������ǿ�!\n";
 else
   cout<<"����������Ϊ��!\n";
 cout<<"�������:";t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"���������������="<<n<<endl;
 n=t.BSTreeLeafCount(B);
 cout<<"����������������Ҷ�ӽ����="<<n<<endl;
 cout<<"�������������Ĺ����:\n(";
 t.PrintBSTree(B);cout<<')'<<endl;
 t.Insert(B,m);
 cout<<"�������:";t.Inorder(B);cout<<endl;
 if(t.Find(B,m)) cout<<"���ҳɹ�!\n";
 else cout<<"���Ҳ��ɹ�!\n";
 m=b[6];
 if(t.Update(B,m,m2)) cout<<"���³ɹ�!\n";
 else cout<<"���²��ɹ�!\n";
 cout<<"�������:";t.Inorder(B);cout<<endl;
 n=t.BSTreeCount(B);
 cout<<"���������������н����="<<n<<endl;
 n=t.BSTreeDepth(B);
 cout<<"���������������="<<n<<endl;
 if(t.Delete(B,m)) cout<<"ɾ���ɹ�!\n";
 else cout<<"ɾ�����ɹ�!\n";
 cout<<"�������:";t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"���������������="<<n<<endl;
 n=t.BSTreeCount(B);
 cout<<"���������������н����="<<n<<endl;
 cout<<"������гɼ�:\n";
 t.WriteFile(f,B);t.ReadFile(f,B);
 cin.get();}



