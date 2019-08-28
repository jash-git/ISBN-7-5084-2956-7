//ʮ������Ķ�������ز���xishuM3.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
typedef int ElemType;
//ʮ������
typedef struct OLNode
{int ii,jj; //��0Ԫ���к����±�
 ElemType e;
 //�÷�0Ԫ���ڵ��б���б�ĺ������
 struct OLNode *right,*down;
}*OLink;
typedef struct
{OLink *rHead,*cHead; //��ָ�����ָ��
 int mu,nu,tu; //ϡ�����������������ͷ�0Ԫ����
}CrossList;
//����ϡ�����M.��ʮ������洢��ʾ
void CreateOLSMatrix(CrossList &M)
{int m,n,t,i,j,e,k,s;
 OLink p,q;
 cout<<"�������������������ͷ�0Ԫ����:";
 cin>>m>>n>>t;
 M.mu=m;M.nu=n;M.tu=t;
 s=m>n?m:n;
 M.rHead=new OLink[s];if(!M.rHead) exit(-1);
 M.cHead=new OLink[s];if(!M.cHead) exit(-1);
 for(k=0;k<s;k++)
  M.rHead[k]=M.cHead[k]=NULL; //��ʼ������ͷָ��ָ�������
 cout<<"�������������M���С��кͷ�0Ԫ:\n";
 for(cin>>i>>j>>e;i!=-1;cin>>i>>j>>e)
  {p=new OLNode;if(!p) exit(-1);
   p->ii=i;p->jj=j;p->e=e; //���ɽ��
   p->right=NULL;p->down=NULL;
   if(M.rHead[i]==NULL) M.rHead[i]=p;
   else{  //Ѱ�����б��еĲ���λ��
     for(q=M.rHead[i];(q->right)&&(q->right->jj<j);q=q->right)
       p->right=q->right;
     q->right=p; }//��ɲ���
   if(M.cHead[j]==NULL) M.cHead[j]=p;
   else{  //Ѱ�����б��еĲ���λ��
     for(q=M.cHead[j];(q->down)&&(q->down->ii<i);q=q->down)
       p->down=q->down;
     q->down=p;}//��ɲ���
  }
 cout<<"�����������Ԫ��:\n";
 cout<<"����="<<M.mu<<"  ����="<<M.nu<<endl;
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
{cout<<"xishuM3.cpp���н��:\n";
 CrossList dd;
 CreateOLSMatrix(dd);
 cin.get();cin.get();}
