//����������BinSortT.cpp
#include <iostream.h>
#include <iomanip.h>
#include<stdlib.h>
//����������ʽ�洢�ṹ��ʾ
typedef struct BinaryTree
{ int data;
  struct BinaryTree *l;
  struct BinaryTree *r;
}*BiTree,BiNode;
//���������ඨ��
class BiSearchT
{private:
  BiTree root;
 public:
  //���캯��
  BiSearchT():root(NULL) {}
  //������������ʾ�Ķ�����T
  int CreateSubTree(BiTree &t,int *all,int i);
  //�������������T
  int PreOrderTraverse(BiTree t,int (*Visit)(int e));
  //�������������T
  int InOrderTraverse(BiTree t,int (*Visit)(int e));
  //�����㷨
  int InsertBST(BiTree *t,int e);
  //�ڶ�����������ɾ��һ���ڵ�
  void Delete(BiTree *p);
  //������������ɾ��
  bool DeleteBST(BiTree *t,int key);
  //�����������ϵĲ��ҵݹ��㷨
  bool SearchBST(BiTree t,int key,BiTree f,BiTree *p);
};
//��������������ʵ��
//������������ʾ�Ķ�����T
int BiSearchT::CreateSubTree(BiTree &t,int *all,int i)
{if((all[i]==0)||i>16)
  {t=NULL;
   return 1;}
 t=(BiNode *)malloc(sizeof(BiNode));
 if(t==NULL) return 0;
 t->data=all[i];
 CreateSubTree(t->l,all,2*i);
 CreateSubTree(t->r,all,2*i+1);
}
//�������������T
int BiSearchT::PreOrderTraverse(BiTree t,int (*Visit)(int d))
{
  if(t){
    if(Visit(t->data))
      if(PreOrderTraverse(t->l,Visit))
	if(PreOrderTraverse(t->r,Visit)) return 1;
    return 0;
  } else  return 1;
}
//�������������T
int BiSearchT::InOrderTraverse(BiTree t,int (*Visit)(int d))
{
  if(t){
    if(InOrderTraverse(t->l,Visit))
      if(Visit(t->data))
        if(InOrderTraverse(t->r,Visit)) return 1;
    return 0;
  }else return 1;
}
//�����������ϵĲ��ҵݹ��㷨
bool BiSearchT::SearchBST(BiTree t,int key,BiTree f,BiTree *p)
{if(!t) {*p=f;return false;}//�ݹ���ս�����
 else if(key==t->data){ *p=t;return true;}
 else if(key<t->data) SearchBST(t->l,key,t,p);
 else SearchBST(t->r,key,t,p);//�������������в���
}
//�����㷨
int BiSearchT::InsertBST(BiTree *t,int e){
  BiTree p;
  BiTree s;
  if(!SearchBST(*t,e,NULL,&p)){
    s=(BiTree)malloc(sizeof(BiNode));
    s->data=e;s->l=s->r=NULL;
    if(!p) *t=s;
    else if(e<p->data) p->l=s;
    else p->r=s;
    return true;
  }
  else return false;
}
//�ڶ�����������ɾ��һ���ڵ�
void BiSearchT::Delete(BiTree *p){
 BiTree q,s;
  if(!(*p)->r)//��������ɾ��
   {q=(*p);
    (*p)=(*p)->l;
    free(q);}
  else if(!(*p)->l)//��������ɾ��
   {q=(*p);
    (*p)=(*p)->r;
    free(q);}
  else
   {q=s=(*p)->l;
    while(s->r) s=s->r;
    s->r=(*p)->r;
    free(*p);
    (*p)=q;}
}
//������������ɾ��
bool BiSearchT::DeleteBST(BiTree *t,int key)
{if(*t!=NULL)
 {if (key==(*t)->data) Delete(t);
  else
   if(key<(*t)->data) DeleteBST(&((*t)->l),key);
  else DeleteBST(&((*t)->r),key);
  return true;}
 else return false;
}
//���������������������ֵ
int printelem(int d)
{cout<<setw(4)<<d;
 return 1;
}
//������������Ĳ���
void main()
{cout<<"BinSortT.cpp���н��:\n";
 BiTree root;
 BiTree sroot=NULL;
 BiTree croot=NULL;
 int all[16]={0,1,2,3,0,0,4,5,0,0,0,0,6,0,0,0};
 int i,a[10]={45,23,12,3,33,27,56,90,120,62};
 int n=7,b[]={10,7,6,9,20,12,22};
 BiSearchT my;
 my.CreateSubTree(root,all,1);
 cout<<"�������(root,all):\n";
 my.PreOrderTraverse(root,printelem);
 cout<<"\n�������(root,all):\n";
 my.InOrderTraverse(root,printelem);
 for(i=0;i<10;i++)
   my.InsertBST(&sroot,a[i]);
 cout<<"\n�������(sroot,a):\n";
 my.InOrderTraverse(sroot,printelem);
 for(i=0;i<3;i++)
  my.DeleteBST(&sroot,a[i]);
 cout<<"\nNow sroot has nodes:\n";
 my.InOrderTraverse(sroot,printelem);
 for(i=0;i<n;i++)
   my.InsertBST(&croot,b[i]);
 cout<<"\n�������(croot,b):\n";
 my.InOrderTraverse(croot,printelem);
 my.InsertBST(&croot,8);
 cout<<"\n�������(croot,b):\n";
 my.InOrderTraverse(croot,printelem);
 my.DeleteBST(&croot,7);
 cout<<"\n�������(croot,b):\n";
 my.InOrderTraverse(croot,printelem);
 cin.get();}
