//十字链表的定义与相关操作xishuM1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
typedef int ElemType;
//十字链表
struct OLNode
{int ii,jj; //非0元的行和列下标
 struct OLNode *right,*down;
 union {
  ElemType e;
  struct OLNode *next;}tag;
};
//创建十字链表
struct OLNode *CreateOLSMat()
{int m,n,t,s,r,i,c,v;
 struct OLNode *h[100],*p,*q;
 cout<<"输入矩阵的行数、列数和非0元个数:";
 cin>>m>>n>>t;
 p=new struct OLNode;if(!p) exit(-1);
 h[0]=p;
 p->ii=m;
 p->jj=n;
 s=m>n?m:n;
 for(i=1;i<=s;i++)
 {p=new struct OLNode;if(!p) exit(-1);
  h[i]=p;
  h[i-1]->tag.next=p;
  p->ii=p->jj=0;
  p->down=p->right=p;
 }
 h[s]->tag.next=h[0];
 cout<<"按任意次序输入行号r,列号c和非0元v:\n";
 for(i=1;i<=t;i++)
 {cin>>r>>c>>v;
  p=new struct OLNode;if(!p) exit(-1);
  p->ii=r;
  p->jj=c;
  p->tag.e=v;
  q=h[r];
  while(q->right!=h[r]&&q->right->jj<c)
   q=q->right;
  p->right=q->right;
  q->right=p;
  q=h[c];
  while(q->down!=h[c]&&q->down->ii<r)
   q=q->down;
  p->down=q->down;
  q->down=p;
 }
 return h[0];
}
void prmat(struct OLNode *hh)
{struct OLNode *p,*q;
 cout<<"按行输出矩阵元素:\n";
 cout<<"行数="<<hh->ii<<"  列数="<<hh->jj<<endl;
 cout<<"  r  c  v\n";
 p=hh->tag.next;
 while(p!=hh)
 {q=p->right;
  while(p!=q)
  {cout<<setw(3)<<q->ii;
   cout<<setw(3)<<q->jj;
   cout<<setw(3)<<q->tag.e<<endl;
   q=q->right;
  }
  p=p->tag.next;
 }
}
void main()
{cout<<"xishuM1.cpp运行结果:\n";
 struct OLNode *dd;
 dd=CreateOLSMat();
 prmat(dd);
 cin.get();cin.get();}
