//ͼ���������Ĳ���graphM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph.cpp"
void main()
{cout<<"graphM.cpp���н��:\n";
 //����ͼ�ĵ�����������ʼ����ŵ�
 int n,k,i;
 //k1Ϊ0���������Ϊ����,k2Ϊ0����Ȩ����Ϊ��Ȩ
 int k1,k2;
 //����ѷ��ʹ��ĵ�
 bool *vis;
 //�����ڽӱ�
 adjlist AL;
 cout<<"����ͼ�ĵ���n=";cin>>n;
 AL=new edgenode*[n];
 vis=new bool[n];
 if(!vis) {cout<<"������ڴ�ʧ��!\n";exit(1);}
 for(i=0;i<n;i++)
  vis[i]=false;
 cout<<"����ѡ������(Ȩ)������(Ȩ)ͼ��ֵk1,k2:";
 cin>>k1>>k2;
 //�����ڽӾ���
 AdjMatrix A(n,k2);
 A.CreateMatrix(n,k1,k2);
 cout<<"������Vk�����=";cin>>k;
 cout<<"\n����ڽӾ�����Ӧͼ��ÿ������:\n";
 A.Creatgraph(n,k2);
 cout<<"��ǰ�Ķ�����Ϊ:"<<A.NumV()<<endl;
 cout<<"��ǰ�ı���Ϊ:"<<A.NumEdges()<<endl;

 cout<<"ͼ�������������˳��:\n";
 A.dfsMatrix(vis,k,n,k2);
 for(i=0;i<n;i++) vis[i]=false;
 cout<<"\nͼ�Ĺ����������˳��:\n";
 A.bfsMatrix(vis,k,n,k2);

 cout<<"\n����ڽӱ��ÿ���ڽӵ�:\n";
 for(i=0;i<n;i++) vis[i]=false;
 A.graphChange(AL,n,k2);
 delete []vis;

 A.DeleteEdge(0,2);
 A.DeleteEdge(2,0);

 cout<<"��ǰ�Ķ�����Ϊ:"<<A.NumV()<<endl;
 cout<<"��ǰ�ı���Ϊ:"<<A.NumEdges()<<endl;
 cout<<"ͼ�������������˳��:\n";
 A.dfsMatrix(n,k2);
 cout<<"\nͼ�Ĺ����������˳��:\n";
 A.bfsMatrix(n,k2);
 cin.get();cin.get();
}
