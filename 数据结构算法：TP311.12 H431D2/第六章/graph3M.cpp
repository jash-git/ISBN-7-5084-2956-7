//ͼ���������Ĳ���graph3M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph3.cpp"
void main()
{cout<<"graph3M.cpp���н��:\n";
 int n,k;//����ͼ�ĵ�����������
 RCW rcw[20]={{0,1,50},{1,0,50},{0,2,60},{2,0,60},
  {1,3,65},{3,1,65},{1,4,40},{4,1,40},{2,3,52},
  {3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50},
  {3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};
 static RCW AE[30],BE[30];//����߼�����
 cout<<"����ͼ�ĵ���n=";cin>>n;
 cout<<"����ͼ�ı���k=";cin>>k;
 adjMList B(AE,n,k);
 B.CreateMatrix(n,k,rcw);
 //��ͼ���ڽӾ�������ͼ�ı߼�����
 B.ChangeEdgeSet(AE,n,k);
 cout<<"����ڽӾ�������ͼ�ı߼�����:\n";
 B.OutputEdgeSet(AE,k);
 cout<<"�����С�������ı߼�����:\n";
 B.Kruskal(AE,BE,n,k);
 B.OutputEdgeSet(BE,k);
 cin.get();cin.get();}
