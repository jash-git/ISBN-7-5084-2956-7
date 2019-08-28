//���·��SShortP.cpp
//���ж���֮������·��
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "graph0.cpp"
#include "PShortP.h"
template<class T>
void Make2DArray(int **&a,int row,int col)
//�����ά��̬����a,������Ϊrow,����Ϊcol
{a=new T*[row];//aΪָ������,����Ϊrow
 for(int i=0;i<row;i++)
  a[i]=new T[col];//ÿ��ָ��ָ��һ��һά����,����Ϊcol
}
void SShortPath(AdjMatrix &G,int **dist,int **path)
{int n=G.NumV();
 for(int i=0;i<n;i++)
  PShortPath(G,i,dist[i],path[i]);
}
//�㷨����
void main()
{cout<<"SShortP.cpp���н��:\n";
 int n=6,e=9,k2=1,i,j;
 RCW rcw[]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},
  {2,1,15},{2,5,7},{4,3,4},{5,3,10},{5,4,18}};
 AdjMatrix g(n,k2);
 g.Creatgraph(n,e,rcw);
 
 int m=g.NumV();
 int **dist,**path;
 Make2DArray<int>(dist,m,m);
 Make2DArray<int>(path,m,m);
 SShortPath(g,dist,path);
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
 cin.get();}
