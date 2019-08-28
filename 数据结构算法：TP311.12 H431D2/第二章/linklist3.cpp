//linklist3.cpp
#include "linklist3.h"
LinkList::LinkList()//�����βι��캯��
{head=new LNode;
 head->next=NULL;
}
LinkList:: LinkList(int d1)//��һ���βι��캯��
{head=new LNode;
 head->next = new LNode;
 head->next->data = d1;
 head->next ->next=NULL;
}
//�������βι��캯��
LinkList::LinkList(int n,int m,int mark)
{int i,j;
 ElemType a[LEN+1];
 for(i=1;i<=n;i++)
   a[i]=(m+rand())%100;
 for(i=1;i<n;i++)
 for(j=1;j<=n-i;j++)
  {int t;
   if( mark>0&&a[j]>a[j+1]||mark<0&&a[j]<a[j+1])
    {t=a[j+1];
     a[j+1]=a[j];
     a[j]=t;
    }
  }
 head=new LNode;
 LNode *p=head,*q;
 for(i=1;i<=n;i++)
  {q= new LNode;
   q->data =a[i];
   p->next =q;
   p=p->next;
  }
 p->next =NULL;
}
LinkList::LinkList(LinkList& HL)//���ƹ��캯��
{head=new LNode;
 head->next=NULL;
 LNode *p2=HL.head->next  ,*p1=head,*q;
 while( p2)
  {q= new LNode;
   q->data=p2->data ;
   p1->next =q;
   p1=q;
   p2=p2->next ;
  }
 p1->next =NULL;
}
LinkList::~LinkList()//��������
{LNode *p=head->next ,*q;
 while(p)
  {q=p->next ;
   free(p);
   p=q;
  }
}
void LinkList::ClearList()//��յ�����
{LNode*p=head->next ,*q;
 while(p)
  {q=p->next;
   free(p);
   p=q;
  }
 head->next =NULL;
}
int LinkList::ListSize()//��������
{LNode*p=head->next ;
 int i=0;
 while(p)
  {i++;
   p=p->next ;}
 return i;
}
bool LinkList::ListEmpty()//��鵥�����Ƿ�Ϊ��
{return ListSize()==0;}
//���ص�������ָ����ŵĽ��ֵ
ElemType LinkList::GetElem(int pos)
{LNode*p=head->next ;
 int i=1;
 while(p)
  {if(i++==pos)return p->data ;
   p=p->next ;
  }
 return head->data ;
}
void LinkList::TraverseList(void f(ElemType &))//����������
{LNode*p=head->next ;
 while(p)
  {f(p->data );
   p=p->next ;}
}
bool LinkList::FindList(ElemType& item)//�ӵ������в���Ԫ��
{LNode*p=head->next ;
 while(p)
  {if(p->data==item)return 1;
   p=p->next ;}
 return 0;
}
//���µ������еĸ���Ԫ��
bool LinkList::UpdateList(const ElemType &item,ElemType e)
{LNode*p=head->next ;
 bool flag=0;
 while(p)
  {if(p->data==item)
    {p->data=e;
     flag=1;}
   p=p->next ;}
 return flag;
}
//���������Ԫ��
void LinkList::InsertList(ElemType item,int mark)
{LNode *q= new LNode;
 q->data = item;
 if(mark==0)
  {q->next = head->next ;
   head->next=q;
   return;}
 LNode *p=head;
 while(p->next)
  {p=p->next ;}
 q->next =NULL;
 p->next =q;
}
//�ӵ�������ɾ��Ԫ��
bool LinkList::DeleteList(ElemType& item,int mark)
{if(ListEmpty()||mark<1||mark>ListSize())return 0;
 LNode *p=head,*q;
 for(int i=0;i<mark-1;i++)
   p=p->next;
 item=p->next->data;
 q=p->next->next ;
 free(p->next );
 p->next=q;
 return 1;
}
//�Ե����������������mark>0����,������
void LinkList::pailie(int mark)
{ElemType a[LEN+1];
 LNode *p=head->next;
 int k ;
 for(k=1;p!=NULL;k++,p=p->next )
   a[k]=p->data;
 k--;
 for(int i=1;i<k;i++)
  for(int j=1;j<=k-i;j++)
   {int t;
    if( mark>0&&a[j]>a[j+1]||mark<0&&a[j]<a[j+1])
     {t=a[j+1];
      a[j+1]=a[j];
      a[j]=t;}}
 p=head->next;
 for(int j=1;j<=k;j++,p=p->next )
  p->data=a[j];
}
//������la ��lb ��Ԫ�ذ�ֵ�ǵݼ�����,����������
//�ϲ��������Ҳ��һ�������
void LinkList::MergeList_L(LinkList &la,LinkList &lb)
{LNode *pa=la.head->next ,*pb=lb.head->next ,*p=head;
 while(pa&&pb)
  {LNode *q=new LNode;
   if(pa->data <pb->data )
    {q->data =pa->data;
     pa=pa->next ;
     p->next =q;
     p=q;}
   else
    {q->data =pb->data;
     pb=pb->next ;
     p->next =q;
     p=q;}
  }
 while(pa)
  {LNode *q=new LNode;
   q->data =pa->data;
   pa=pa->next ;
   p->next =q;
   p=q;}
 while(pb)
  {LNode *q=new LNode;
   q->data =pb->data;
   pb=pb->next ;
   p->next =q;
   p=q;}
 p->next =NULL;
}
//�Ե���������������
void LinkList::OrderOutputList(int mark)
{ElemType a[LEN+1];
 LNode *p=head->next;
 int k ;
 for( k=1;p!=NULL;k++,p=p->next )
   a[k]=p->data;
 k--;
 for(int i=1;i<k;i++)
  for(int j=1;j<=k-i;j++)
   {int t;
    if( mark>0&&a[j]>a[j+1]||mark<0&&a[j]<a[j+1])
     {t=a[j+1];
      a[j+1]=a[j];
      a[j]=t;}}
 for(int j=1;j<=k;j++)
  cout<<a[j]<<"  ";
}
