//���·��(�ҿ�˹�����㷨)PshortP1.cpp
//��һ�����㵽�������������·��
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph.cpp"
//��G���±�v0�������������̾���dist�����·���±�path
void PShortPath(AdjMatrix &G,int v0,int dist[],int path[])
{int n=G.NumV();
 int *s=new int[n];
 int mindis,i,j,u;
 for(i=0;i<n;i++)
 {dist[i]=G.GetWeight(v0,i);
  s[i]=0;
  if(i!=v0&&dist[i]<MaxValue) path[i]=v0;
  else path[i]=-1;
 }
 s[v0]=1;//��Ƕ���v0�ѴӼ���T���뵽����S��
 //�ڵ�ǰ��δ�ҵ����·���Ķ��㼯��ѡȡ������̾���Ķ���u
 for(i=1;i<n;i++)
 {mindis=MaxValue;
  for(j=0;j<n;j++)
   if(s[j]==0&&dist[j]<mindis)
    {u=j;
     mindis=dist[j];
    }
  //���Ѳ��ٴ���·��ʱ�㷨����;�����Է���ͨͼ�Ǳ����
  if(mindis==MaxValue) return;
  s[u]=1;//��Ƕ���u�ѴӼ���T���뵽����S��
  //�޸Ĵ�v0�������������̾�������·��
  for(j=0;j<n;j++)
   if(s[j]==0&&G.GetWeight(u,j)<MaxValue&&
    dist[u]+G.GetWeight(u,j)<dist[j])
   {//����v0������u�������������̾�������·��
    dist[j]=dist[u]+G.GetWeight(u,j);
    path[j]=u;
   }
 }
}
//�㷨����
void main()
{cout<<"PShortP1.cpp���н��:\n";
 int n=6,k1=1,k2=1;
 AdjMatrix g(n,k2);
 g.CreateMatrix(n,k1,k2);
 cout<<"\n����ڽӾ�����Ӧͼ��ÿ������:\n";
 g.Creatgraph(n,k2);
 int m=g.NumV();
 int *dist=new int[m];
 int *path=new int[m];
 int v0=0;
 PShortPath(g,v0,dist,path);
 cout<<"�Ӷ���"<<g.GetValue(v0)
     <<"���������������̾���Ϊ:\n";
 for(int i=0;i<m;i++)
  cout<<"������"<<g.GetValue(i)
      <<"����̾���Ϊ:"<<dist[i]<<endl;
 cout<<"�Ӷ���"<<g.GetValue(v0)
     <<"����������������·����ǰһ����Ϊ:\n";
 for(i=0;i<m;i++)
  if(path[i]!=-1)
   cout<<"������"<<g.GetValue(i)<<"��ǰһ����Ϊ:"
       <<g.GetValue(path[i])<<endl;
 cin.get();cin.get();}
