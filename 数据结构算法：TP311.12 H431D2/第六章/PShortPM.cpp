//���·���㷨PshortPM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph0.cpp"
#include "PshortP.h"
//�ҿ�˹�����㷨����
void main()
{cout<<"PShortPM.cpp���н��:\n";
 int n=6,e=9,k2=1;
 RCW rcw[]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},
  {2,1,15},{2,5,7},{4,3,4},{5,3,10},{5,4,18}};
 AdjMatrix g(n,k2);
 g.Creatgraph(n,e,rcw);
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
 cin.get();}
 
