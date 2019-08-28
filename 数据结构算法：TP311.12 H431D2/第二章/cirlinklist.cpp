//��ѭ�������ʵ��cirlinklist.cpp
#include<iostream.h>
#include<stdlib.h>
#include"cirlinklist.h"
//���캯��
cirlinklist::cirlinklist()
{head=new LNode;
 curr=NULL;
 head->next=head;
 count=0;
}
//�������������Ĵ�ͷ���ĵ�ѭ������
LNode *cirlinklist::CreateCLinkL(int n,int m,int mark)
{ElemType x,a[LEN];
 srand(m);
 for(int i=0;i<n;i++) a[i]=rand()%100;
 for(i=0;i<n-1;i++)
  {int k=i;
   for(int j=i+1;j<n;j++)
    if(a[k]>a[j]) k=j;
   if(k!=i)
   {x=a[k];a[k]=a[i];a[i]=x;}}
 head=new LNode;
 head->next=curr=new LNode;
 for(i=0;i<n;i++){
  if(mark==1) curr->data=a[i];//����
  else
   if(mark==-1) curr->data=a[n-1-i];//����
   else curr->data=rand()%100;//����
  if(i<n-1){curr->next=new LNode;
   curr=curr->next;}
  count++;}
 curr->next=head;
 return head;
}
//��յ�ѭ������
void cirlinklist::ClearCList()
{LNode *cp,*np;
 cp=head->next;
 while(cp!=head)
 {np=cp->next;delete cp;cp=np;}
 head=NULL;
}
//��ѭ��������
int cirlinklist::CListSize()
{LNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;p=p->next;}
 return i;
}
//��鵥ѭ�������Ƿ�Ϊ��
bool cirlinklist::CListEmpty()
{return head->next==head;}
//����ָ���pos������ָ��
LNode *cirlinklist::Index(int pos)
{if(pos<1)
  {cerr<<"pos is out range!"<<endl;exit(1);}
 LNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 if(p!=head) return p;
 else {cerr<<"pos is out range!"<<endl;
  return NULL;}
}
//���ص�ѭ��������ָ����ŵĽ��ֵ
ElemType cirlinklist::GetElem(int pos)
{if(pos<1)
 {cerr<<"pos is out range!"<<endl;exit(1);}
 LNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 if(p!=head) return p->data;
 else {cerr<<"pos is out range!"<<endl;
  return pos;}
}
//������ѭ������
LNode *cirlinklist::TraverseCList()
{LNode *p=head->next;
 while(p!=head)
  {cout<<setw(4)<<p->data;
   p=p->next;}
 cout<<endl;
 return head;
}
//��ǰָ��currָ��pos��㲢����curr
LNode *cirlinklist::Reset(int pos)
{LNode* p=curr=head->next;
 int i=-1;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;curr=curr->next;}
 return curr;
}
//��ǰָ��currָ����һ��㲢����
LNode *cirlinklist::Next()
{curr=curr->next;
 return curr; 
}
// �е�ѭ������ǰָ��curr==head ��
bool cirlinklist::EndOCList()
{return curr==head;}
//�е�ѭ������ǰָ��curr->next�Ƿ񵽴��β
bool cirlinklist::EndCList()
{return curr->next==head;}
//ɾ����ѭ������ǰָ��curr->next��ָ��㲢������ֵ
ElemType cirlinklist::DeleteNext()
{LNode *p=curr->next;
 curr->next=p->next;
 ElemType data=p->data;
 delete p;
 count--;
 return data;
}
//�ӵ�ѭ�������в���Ԫ��
bool cirlinklist::FindCList(ElemType& item)
{LNode* p=head->next;
 while(p!=head)
  if(p->data==item)
   {item=p->data;return true;}
  else p=p->next;
 return false;
}
//���µ�ѭ�������еĸ���Ԫ��
bool cirlinklist::UpdateCList(const ElemType &item,ElemType &e)
{LNode* p=head->next;
 while(p!=head)  //����Ԫ��
  if(p->data==item) break;
  else p=p->next;
 if(p==head) return false;
 else {  //����Ԫ��
  p->data=e;return true;}
}
//�������е�pos�����������ֵΪitem���½��
void cirlinklist::InsertCList(const ElemType& item,int pos)
{LNode *newP=new LNode;
 newP->data=item;
 LNode* p=head->next;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;}
 newP->next=p->next;
 p->next=newP;count++;
}
//��������ɾ����pos����㲢���ر�ɾ����data
ElemType cirlinklist::DeleteCList(int pos)
{if(pos<1)
  {cerr<<"pos is out range!"<<endl;exit(1);}
 LNode *p=head->next;
 curr=head;
 ElemType data;
 int i=0;
 while(p!=head)
  {i++;
   if(i==pos) break;
   p=p->next;curr=curr->next;}
 if(p!=head)
  {data=p->data;curr->next=p->next;
   delete []p;count--;return data;}
 else return pos;  
}


