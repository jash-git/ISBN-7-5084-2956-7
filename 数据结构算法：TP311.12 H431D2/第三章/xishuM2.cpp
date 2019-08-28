//ʮ��������ඨ������ز���xishuM2.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
typedef int ElemType;
class CrossList;
class OLNode //ʮ������
{public:
  int ii,jj; //��0Ԫ���к����±�
  ElemType e;
  //�÷�0Ԫ���ڵ��б���б�ĺ������
  OLNode *right,*down;
  friend class CrossList;
};
typedef class OLNode *OLink;
class CrossList
{public:
  OLink *rHead,*cHead; //��ָ�����ָ��
  int mu,nu,tu; //ϡ�����������������ͷ�0Ԫ����
  //����ϡ�����,��ʮ������洢��ʾ
  void CreateOLSMatrix();
};
void CrossList::CreateOLSMatrix()
{int m,n,t,i,j,e,k,s;
 OLink p,q;
 cout<<"�������������������ͷ�0Ԫ����:";
 cin>>m>>n>>t;
 mu=m;nu=n;tu=t;
 s=m>n?m:n;
 rHead=new OLink[s];if(!rHead) exit(-1);
 cHead=new OLink[s];if(!cHead) exit(-1);
 for(k=0;k<s;k++)
  rHead[k]=cHead[k]=NULL; //��ʼ������ͷָ��ָ�������
 cout<<"�������������M���С��кͷ�0Ԫ:\n";
 for(cin>>i>>j>>e;i!=-1;cin>>i>>j>>e)
  {p=new OLNode;if(!p) exit(-1);
   p->ii=i;p->jj=j;p->e=e; //���ɽ��
   p->right=NULL;p->down=NULL;
   if(rHead[i]==NULL) rHead[i]=p;
   else{  //Ѱ�����б��еĲ���λ��
     for(q=rHead[i];(q->right)&&(q->right->jj<j);q=q->right)
       p->right=q->right;
     q->right=p; }//��ɲ���
   if(cHead[j]==NULL) cHead[j]=p;
   else{  //Ѱ�����б��еĲ���λ��
     for(q=cHead[j];(q->down)&&(q->down->ii<i);q=q->down)
       p->down=q->down;
     q->down=p;}//��ɲ���
  }
 cout<<"�����������Ԫ��:\n";
 cout<<"����="<<mu<<"  ����="<<nu<<endl;
 cout<<"  i  j  e\n";
 for(i=0,p=rHead[0];i<tu;p=rHead[++i])
 {q=p;
  while(!(q==NULL))
  {cout<<setw(3)<<q->ii;
   cout<<setw(3)<<q->jj;
   cout<<setw(3)<<q->e<<endl;
   q=q->right;
 }}
}
//ʮ��������ز����Ĳ���
void main()
{cout<<"xishuM2.cpp���н��:\n";
 CrossList dd;
 dd.CreateOLSMatrix();
 cin.get();cin.get();}
