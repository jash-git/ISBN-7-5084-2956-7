//˫��ѭ�������ʵ��dcirlinkl.cpp
#include<iostream.h>
#include<stdlib.h>
#include"dcirlinkl.h"
//���캯��
DuLinkList::DuLinkList()
{head=new DuLNode;
 head->prior=head;
 head->next=head;
 curr=NULL;
 count=0;
}
//�������������Ĵ�ͷ����˫��ѭ������
DuLNode *DuLinkList::CreateCLinkL(int n,int m,int mark)
{ElemType x,a[LEN];
 srand(m);
 for(int i=0;i<n;i++) a[i]=rand()%100;
 for(i=0;i<n-1;i++)
  {int k=i;
   for(int j=i+1;j<n;j++)
    if(a[k]>a[j]) k=j;
   if(k!=i)
   {x=a[k];a[k]=a[i];a[i]=x;}}
 DuLNode *p;
 head=new DuLNode;
 head->prior=NULL;
 head->next=curr=p=new DuLNode;
 curr->prior=head;
 for(i=0;i<n;i++){
  if(mark==1) p->data=a[i];//����
  else
   if(mark==-1) p->data=a[n-1-i];//����
   else p->data=rand()%100;//����
  if(i<n-1){curr=curr->next=new DuLNode;
   curr->prior=p;p=curr;}
  count++;}
 head->prior=curr;
 curr->next=head;
 return head;
}
//���˫��ѭ������
void DuLinkList::ClearCList()
{DuLNode *cp,*np;
 cp=head->next;
 while(cp!=head)
 {np=cp->next;delete cp;cp=np;}
 head=NULL;
}
//��˫��ѭ��������
int DuLinkList::CListSize()
{DuLNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;p=p->next;}
 return i;
}
//���˫��ѭ�������Ƿ�Ϊ��
bool DuLinkList::CListEmpty()
{return head->next==head;}
//����ָ���pos������ָ��
DuLNode *DuLinkList::Index(int pos)
{if(pos<1)
  {cerr<<"pos is out range!"<<endl;exit(1);}
 DuLNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 if(p!=head) return p;
 else {cerr<<"pos is out range!"<<endl;
  return NULL;}
}
//����˫��ѭ��������ָ����ŵĽ��ֵ
ElemType DuLinkList::GetElem(int pos)
{if(pos<1)
 {cerr<<"pos is out range!"<<endl;exit(1);}
 DuLNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 if(p!=head) return p->data;
 else {cerr<<"pos is out range!"<<endl;
  return pos;}
}
//����˫��ѭ������
void DuLinkList::TraverseCList()
{DuLNode *p=head->next;
 while(p!=head)
  {cout<<setw(4)<<p->data;
   p=p->next;}
 cout<<endl;
}
//��ǰָ��currָ��pos��㲢����curr
DuLNode *DuLinkList::Reset(int pos)
{DuLNode* p=curr=head->next;
 int i=-1;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;curr=curr->next;}
 return curr;
}
//��ǰָ��currָ����һ��㲢����
DuLNode *DuLinkList::Next()
{curr=curr->next;
 return curr; 
}
//��ǰָ��currָ����һ��㲢����
DuLNode *DuLinkList::Prior()
{curr=curr->prior;
 return curr;
}
// ��˫��ѭ������ǰָ��curr==head ��
bool DuLinkList::EndOCList()
{return curr==head;}
//��˫��ѭ������ǰָ��curr->next�Ƿ񵽴��β
bool DuLinkList::EndCList()
{return curr->next==head;}
//��˫��ѭ������ǰָ��curr->prior�Ƿ񵽴��β
bool DuLinkList::PEndCList()
{return curr->prior==head;}
//ɾ��curr->next��ָ���,��������ɾ����data
ElemType DuLinkList::DeleteNt()
{DuLNode *p=curr->next;
 curr->next=p->next;
 curr->next->next->prior=p->prior;
 ElemType data=p->data;
 delete p;
 count--;
 return data;
}
//��˫��ѭ�������в���Ԫ��
bool DuLinkList::FindCList(ElemType& item)
{DuLNode* p=head->next;
 while(p!=head)
  if(p->data==item)
   {item=p->data;return true;}
  else p=p->next;
 return false;
}
//����˫��ѭ�������еĸ���Ԫ��
bool DuLinkList::UpdateCList(const ElemType &item,ElemType &e)
{DuLNode* p=head->next;
 while(p!=head)  //����Ԫ��
  if(p->data==item) break;
  else p=p->next;
 if(p==head) return false;
 else {  //����Ԫ��
  p->data=e;return true;}
}
//�������е�pos�����ǰ������ֵΪitem���½��
void DuLinkList::InsertCLfront(const ElemType& item,int pos)
{DuLNode *newP=new DuLNode;
 newP->data=item;
 DuLNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 newP->prior=p->prior;
 p->prior->next=newP;
 newP->next=p;
 p->prior=newP;
 count++;
}
//�������е�pos�����������ֵΪitem���½��
void DuLinkList::InsertCLafter(const ElemType& item,int pos)
{DuLNode *newP=new DuLNode;
 newP->data=item;
 DuLNode* p=head->next;
 int i=-1;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 newP->prior=p->prior;
 p->prior->next=newP;
 newP->next=p;
 p->prior=newP;
 count++;
}
//��������ɾ����pos����㲢���ر�ɾ����data
ElemType DuLinkList::DeleteCList(int pos)
{if(pos<1)
  {cerr<<"pos is out range!"<<endl;exit(1);}
 DuLNode *p=head->next;
 ElemType data;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 if(p!=head)
  {data=p->data;
   p->prior->next=p->next;
   p->next->prior=p->prior;
   delete []p;count--;return data;}
 else return pos;  
}


