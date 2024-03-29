//K路平衡归并K_WayBM.cpp
#include<iostream.h>
#include<iomanip.h>
//初始归并段个数
const int k=5;
const int m=4;//初始归并段中最多关键字个数
const int MAXKEY=999;//段结束标志
//二维数组b起磁盘文件作用
int b[k][m]={{3,5,13,MAXKEY},{4,6,MAXKEY},
 {2,8,MAXKEY},{1,11,MAXKEY},{9,12,MAXKEY}};
typedef int keyType;
typedef struct
{keyType key;}ExNode;
ExNode buff[k][m];//结构体二维数组
int ls[k],st[k];

void Merge(int k);
void Read_Buff(int i);
void CreateLoserTree(int ls[],int k);
void Adjust(int ls[],int j,int k);
//K路平衡归并实现算法
void Merge(int k)
{int q;
 for(int i=0;i<k;i++) Read_Buff(i);
 CreateLoserTree(ls,k);
 q=ls[0];
 while(buff[q][st[q]].key!=MAXKEY)
  {cout<<setw(3)<<buff[q][st[q]].key;
   ++st[q];
   int w=st[q];
   if(st[w]==m) Read_Buff(w);
   Adjust(ls,q,k);
   q=ls[0];
  }
}
//读取各归并段数据,并设置相关变量st[i]的算法实现
void Read_Buff(int i)
{for(int j=0;j<m;j++)
   buff[i][j].key=b[i][j];
 st[i]=0;
}
//重构败者树的算法实现
void Adjust(int ls[],int j,int k)
{int t=(j+k)/2;
 while(t>0)
  {if(ls[t]==-1) {ls[t]=j;return;}
   if(buff[j][st[j]].key>buff[ls[t]][st[ls[t]]].key)
    {int y=j;j=ls[t];ls[t]=y;}
   t=t/2;
  }
 ls[0]=j;
}
//创建败者树的算法实现
void CreateLoserTree(int ls[],int k)
{for(int i=0;i<k;i++) ls[i]=-1;
 for(i=k-1;i>=0;i--) Adjust(ls,i,k);
}
//K路平衡归并相关操作测试
void main()
{cout<<"K_WayBM.cpp运行结果:\n";
 Merge(5);
 cin.get();
}
 






