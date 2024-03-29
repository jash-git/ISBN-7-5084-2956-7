//十字链表的定义与相关操作xishuM3.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
typedef int ElemType;
//十字链表
typedef struct OLNode
{int ii,jj; //非0元的行和列下标
 ElemType e;
 //该非0元所在的行表和列表的后继链域
 struct OLNode *right,*down;
}*OLink;
typedef struct
{OLink *rHead,*cHead; //行指针和列指针
 int mu,nu,tu; //稀疏矩阵的行数、列数和非0元个数
}CrossList;
//创建稀疏矩阵M.用十字链表存储表示
void CreateOLSMatrix(CrossList &M)
{int m,n,t,i,j,e,k,s;
 OLink p,q;
 cout<<"输入矩阵的行数、列数和非0元个数:";
 cin>>m>>n>>t;
 M.mu=m;M.nu=n;M.tu=t;
 s=m>n?m:n;
 M.rHead=new OLink[s];if(!M.rHead) exit(-1);
 M.cHead=new OLink[s];if(!M.cHead) exit(-1);
 for(k=0;k<s;k++)
  M.rHead[k]=M.cHead[k]=NULL; //初始化行列头指针指向空链表
 cout<<"按任意次序输入M的行、列和非0元:\n";
 for(cin>>i>>j>>e;i!=-1;cin>>i>>j>>e)
  {p=new OLNode;if(!p) exit(-1);
   p->ii=i;p->jj=j;p->e=e; //生成结点
   p->right=NULL;p->down=NULL;
   if(M.rHead[i]==NULL) M.rHead[i]=p;
   else{  //寻找在行表中的插入位置
     for(q=M.rHead[i];(q->right)&&(q->right->jj<j);q=q->right)
       p->right=q->right;
     q->right=p; }//完成插入
   if(M.cHead[j]==NULL) M.cHead[j]=p;
   else{  //寻找在列表中的插入位置
     for(q=M.cHead[j];(q->down)&&(q->down->ii<i);q=q->down)
       p->down=q->down;
     q->down=p;}//完成插入
  }
 cout<<"按行输出矩阵元素:\n";
 cout<<"行数="<<M.mu<<"  列数="<<M.nu<<endl;
 cout<<"  i  j  e\n";
 for(i=0,p=M.rHead[0];i<M.tu;p=M.rHead[++i])
 {q=p;
  while(!(q==NULL))
  {cout<<setw(3)<<q->ii;
   cout<<setw(3)<<q->jj;
   cout<<setw(3)<<q->e<<endl;
   q=q->right;
  } 
 }
}
void main()
{cout<<"xishuM3.cpp运行结果:\n";
 CrossList dd;
 CreateOLSMatrix(dd);
 cin.get();cin.get();}
