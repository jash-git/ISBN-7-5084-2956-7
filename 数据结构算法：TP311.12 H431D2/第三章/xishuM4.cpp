//ʮ��������ඨ������ز���xishuM4.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
typedef int ElemType;

class OLNode//ʮ������
{public:
  int ii,jj; //��0Ԫ���к����±�
  OLNode *right,*down;
  union {
   ElemType e;
   OLNode *next;}tag;
  OLNode *CreateOLSMat();
  void prmat(OLNode *hh);
};
//����ʮ������
OLNode *OLNode::CreateOLSMat()
{int m,n,t,s,r,i,c,v;
 OLNode *h[100],*p,*q;
 cout<<"�������������������ͷ�0Ԫ����:";
 cin>>m>>n>>t;
 p=new OLNode;if(!p) exit(-1);
 h[0]=p;
 p->ii=m;
 p->jj=n;
 s=m>n?m:n;
 for(i=1;i<=s;i++)
 {p=new OLNode;if(!p) exit(-1);
  h[i]=p;
  h[i-1]->tag.next=p;
  p->ii=p->jj=0;
  p->down=p->right=p;
 }
 h[s]->tag.next=h[0];
 cout<<"��������������к�r,�к�c�ͷ�0Ԫv:\n";
 for(i=1;i<=t;i++)
 {cin>>r>>c>>v;
  p=new OLNode;if(!p) exit(-1);
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
void OLNode::prmat(OLNode *hh)
{OLNode *p,*q;
 cout<<"�����������Ԫ��:\n";
 cout<<"����="<<hh->ii<<"  ����="<<hh->jj<<endl;
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
}}
//ʮ��������ز����Ĳ���
void main()
{cout<<"xishuM4.cpp���н��:\n";
 OLNode *dd=NULL,*tt;
 tt=dd->CreateOLSMat();
 dd->prmat(tt);
 cin.get();cin.get();}
