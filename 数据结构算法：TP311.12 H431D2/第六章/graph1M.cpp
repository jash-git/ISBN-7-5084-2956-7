//ͼ���������Ĳ���graph1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph1.cpp"
void main()
{cout<<"graph1M.cpp���н��:\n";
 char a[]={'A','B','C','D','E','F','G'};
 RCW rcw[]={{0,1,1},{0,2,1},{1,3,1},{1,4,1},{2,5,1},
  {2,6,1},{1,0,1},{2,0,1},{3,1,1},{4,1,1},{5,2,1},{6,2,1}};
 //����ͼ�ĵ�����������ʼ����ŵ�
 int n,k,i;
 //k1Ϊ0���������Ϊ����,k2Ϊ0����Ȩ����Ϊ��Ȩ
 int k1,k2;
 //����ѷ��ʹ��ĵ�
 bool *vis;
 cout<<"����ͼ�ĵ���n=";cin>>n;
 vis=new bool[n];
 if(!vis) {cout<<"������ڴ�ʧ��!\n";exit(1);}
 for(i=0;i<n;i++) vis[i]=false;
 cout<<"����ѡ������(Ȩ)������(Ȩ)ͼ��ֵk1,k2:";
 cin>>k1>>k2;
 edgenode **gl=new edgenode*[n];
 AdjAdjoin B(gl,n);
 B.CreatGraph(a,n,rcw,12);
 cout<<"�����ڽӱ�:\n";
 B.CreateAdjoin(n,k1,k2,rcw);
 cout<<"������Vk�����=";cin>>k;
 cout<<"��ǰ�Ķ�����Ϊ:"<<B.NumV()<<endl;
 cout<<"��ǰ�ı���Ϊ:"<<B.NumEdges()<<endl;
 cout<<"��������������˳��:\n";
 B.dfsAdjoin(vis,k,n);cout<<endl;
 cout<<"��Ĺ����������˳��:\n";
 for(i=0;i<n;i++) vis[i]=false;
 B.bfsAdjoin(vis,k,n);cout<<endl;

 B.DeleteEdge(0,2);
 B.DeleteEdge(2,0);
 cout<<"��ǰ�Ķ�����Ϊ:"<<B.NumV()<<endl;
 cout<<"��ǰ�ı���Ϊ:"<<B.NumEdges()<<endl;
 cout<<"��������������˳��:\n";
 B.dfsAdjoin(n);cout<<endl;
 cout<<"��Ĺ����������˳��:\n";
 for(i=0;i<n;i++) vis[i]=false;
 B.bfsAdjoin(n);cout<<endl;
 B.DeleteAdjoin(n);
 cin.get();cin.get();
}
