//FloydP1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph.cpp"
#include "FloydP.h"
//���������㷨����
void main()
{cout<<"FloydP1.cpp���н��:\n";
 int n=6,k1=1,k2=1,i,j;
 AdjMatrix g(n,k2);
 g.CreateMatrix(n,k1,k2);
 cout<<"����ڽӾ�����Ӧͼ�Ķ���:\n";
 g.Creatgraph(n,k2);
 
 int m=g.NumV();
 int dist[6][6],path[6][6];
 Floyd(g,dist,path);
 for(i=0;i<m;i++)
 {cout<<"�Ӷ���"<<g.GetValue(i)
      <<"���������������̾���Ϊ:\n";
  for(j=0;j<m;j++)
   cout<<"������"<<g.GetValue(j)
       <<"����̾���Ϊ:"<<dist[i][j]<<endl;
   cout<<"�Ӷ���"<<g.GetValue(i)
       <<"����������������·����ǰһ����Ϊ:\n";
   for(j=0;j<m;j++)
    if(path[i][j]!=-1)
     cout<<"������"<<g.GetValue(j)<<"��ǰһ����Ϊ:"
         <<g.GetValue(path[i][j])<<endl;
 }
 cin.get();cin.get();}
