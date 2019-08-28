//���Ա��ʵ��linelist1.cpp
#include "linelist1.h"
void List::init(List **L,int ms)
{*L=(List *)malloc(sizeof(List));
 (*L)->length=0;
 (*L)->MaxSize=ms;
}
int List::ListLength()
{return length;}

ElemType List::PriorElem(ElemType cur_e,ElemType &pre_e)
{for(int i=0;i<length;i++)
  if(i!=0&&strcmp(cur_e.name,elem[i].name)==0)
   {pre_e=elem[i-1];return pre_e;}
 return cur_e;
}
ElemType List::NextElem(ElemType cur_e,ElemType &next_e)
{for(int i=0;i<length;i++)
  if(i!=length-1&&strcmp(cur_e.name,elem[i].name)==0)
   {next_e=elem[i+1];return next_e;}
 return cur_e;
}
bool List::ListDelete(int mark,ElemType &e)
{int i,j;
 if(ListEmpty()) return false;
 if(mark>0) {  //ɾ����ͷԪ��
    e=elem[0];
    for(i=1; i<length; i++)
     elem[i-1]=elem[i];}
 else   //ɾ����βԪ��
   if(mark<0) e=elem[length-1];
   else {  //ɾ��ֵΪe��Ԫ��
    for(i=0;i<length;i++)
     if(strcmp(elem[i].name,e.name)==0) break;
     if(i>=length) return false;
     else e=elem[i];
     for(j=i+1;j<length;j++)
      elem[j-1]=elem[j];}
 length--;
 return true;
}
void List::ListTraverse()
{for(int i=0;i<length;i++)
   {cout<<setw(8)<<elem[i].name;
    cout<<setw(10)<<elem[i].stuno;
    cout<<setw(9)<<elem[i].age;
    cout<<setw(8)<<elem[i].score<<endl;}
}
void List::GetElem(int i,ElemType *e)
{*e=elem[i];}

bool List::EqualList(ElemType *e1,ElemType *e2)
{ if (strcmp(e1->name,e2->name))
    return false;
  if (strcmp(e1->stuno,e2->stuno))
    return false;
  if (e1->age!=e2->age)
    return false;
  if (e1->score!=e2->score)
    return false;
  return true;
}
bool List::Less_EqualList(ElemType *e1,ElemType *e2)
{ if(strcmp(e1->name,e2->name)<=0) return true;
  else return false;
}
bool List::LocateElem(ElemType e,int type)
{ int i;
  switch (type)
    { case EQUAL:
	for(i=0;i<length;i++)
	  if(EqualList(&elem[i],&e))
	    return true;
	break;
      default:break;}
  return false;
}
//�������Ա��еĸ���Ԫ��
bool List::UpdateList(ElemType& e,ElemType e1)
{for(int i=0;i<length;i++)
   if(strcmp(elem[i].name,e.name)==0) {
     elem[i]=e1;return true;}
 return false;
}
bool List::ListInsert(int i,ElemType &e)
{ElemType *p,*q;
 if(i<1||i>length+1) return false;
 q=&elem[i-1];
 for(p=&elem[length-1];p>=q;--p)
   *(p+1)=*p;
 *q=e;
 ++length;
 return true;
}
void List::MergeList(List *La,List *Lb)
{ int i,j,La_len,Lb_len;
  La_len=La->ListLength();Lb_len=Lb->ListLength();
  for(i=0;i<La_len;i++)
   elem[i]=La->elem[i];
  for(j=0;j<Lb_len;j++)
   elem[i+j]=Lb->elem[j];
  length=La_len+Lb_len;
}
void List::UnionList(List *La, List *Lb)
{ int i,La_len,Lb_len;
  ElemType e;
  La_len=La->ListLength();Lb_len=Lb->ListLength();
  for(i=0;i<Lb_len;i++)
    {Lb->GetElem(i,&e);
     if(!LocateElem(e,EQUAL))
      ListInsert(++La_len,e);}
}
//�����Ա�����������
void List::printlist(int mark)
{int* b=new int[length];
 int i,k;
 cout<<"    ����     ѧ��       ����    �ɼ�\n";
 if(mark!=0){
  for(i=0; i<length;i++) b[i]=i;
  for(i=0; i<length;i++) {k=i;
   for(int j=i+1;j<length;j++) {
    if(mark==1&&elem[b[j]].score<elem[b[k]].score) k=j;
    if(mark==-1&&elem[b[k]].score<elem[b[j]].score) k=j;}
    if(k!=i) {int x=b[i];b[i]=b[k];b[k]=x;}}
  for(int i=0;i<length;i++)
  {cout<<setw(8)<<elem[b[i]].name;
   cout<<setw(10)<<elem[b[i]].stuno;
   cout<<setw(9)<<elem[b[i]].age;
   cout<<setw(8)<<elem[b[i]].score<<endl;}}
 else {
  for(i=0;i<length;i++)
   {cout<<setw(8)<<elem[i].name;
    cout<<setw(10)<<elem[i].stuno;
    cout<<setw(9)<<elem[i].age;
    cout<<setw(8)<<elem[i].score<<endl;}}
}
