//�������򷽷�DZpaixu.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 20
#define LT(a,b) ((a)<(b))
typedef int KeyType;
typedef int InfoType;
typedef struct{
  KeyType key;
  InfoType otherinfo;
}RedType;
typedef struct{
  RedType r[MAXSIZE+1];
  int length;
}SqList;
//��������
void InsertSort(SqList *L)
{ int i,j;
  for(i=2;i<=L->length;++i)
    if(LT(L->r[i].key,L->r[i-1].key)){
      L->r[0]=L->r[i];
      for(j=i-1;LT(L->r[0].key,L->r[j].key);--j)
	L->r[j+1]=L->r[j];
      L->r[j+1]=L->r[0];}
}
//�۰��������
void BInsertSort(SqList *L)
{ int i,j;
  int low,high,m;
  for(i=2;i<=L->length;++i){
    L->r[0]=L->r[i];
    low=1;high=i-1;
    while(low<=high){
      m=(low+high)/2;
      if (LT(L->r[0].key,L->r[m].key))
	high=m-1;
      else low=m+1;}
    for(j=i-1;j>=high+1;--j)
      L->r[j+1]=L->r[j];
    L->r[high+1]=L->r[0];}
}
//��������
int Partition(SqList *L,int low,int high)
{ int pivotkey;
  L->r[0]=L->r[low];
  pivotkey=L->r[low].key;
  while(low<high){
    while(low<high&&L->r[high].key>=pivotkey) --high;
    L->r[low]=L->r[high];
    while(low<high&&L->r[low].key<=pivotkey) ++low;
    L->r[high]=L->r[low];}
  L->r[low]=L->r[0];
  return low;
}
void QSort(SqList *L,int low,int high)
{ int pivotloc;
  if(low<high){
    pivotloc=Partition(L,low,high);
    QSort(L,low,pivotloc-1);
    QSort(L,pivotloc+1,high);}
}
void QuickSort(SqList *L)
{ QSort(L,1,L->length);}

//ѡ������
int SelectMinKey(SqList L,int i)
{int k;int j;
  k=i;
  for(j=i;j<L.length+1;j++)
    if(L.r[k].key>L.r[j].key)
      k=j;
  return k;
}
void SelectSort(SqList *L)
{ RedType t;
  int i,j;
  for(i=1;i<L->length;++i){
    j=SelectMinKey(*L,i);
    if(i!=j) {
      t=L->r[i];
      L->r[i]=L->r[j];
      L->r[j]=t;}}
}
//������
typedef SqList HeapType;
void HeapAdjust(HeapType *H,int s,int m)
{ RedType rc;
  int j;
  rc=H->r[s];
  for(j=2*s;j<=m;j*=2){
    if(j<m&&LT(H->r[j].key,H->r[j+1].key)) ++j;
    if(!LT(rc.key,H->r[j].key)) break;
    H->r[s]=H->r[j];
    s=j;}
  H->r[s]=rc;
}
void HeapSort(HeapType *H)
{ RedType t;
  int i;
  for(i=H->length/2;i>0;--i)
    HeapAdjust(H,i,H->length);
  for(i=H->length;i>1;--i){
    t=H->r[1];
    H->r[1]=H->r[i];
    H->r[i]=t;
    HeapAdjust(H,1,i-1);}
}
void main()
{ int a[11];
  int i,k,T=1;
  SqList s;
  cout<<"\nDZpaixu.cpp���н��:\n";
  srand(time(0));
  cout<<"����ǰ����a:\n";
  for(i=1;i<11;i++)
    { s.r[i].key=a[i-1]=rand()%100;
      cout<<setw(4)<<a[i-1];}
  s.length=i-1;
  while(T){
   cout<<"    \n   ������ѡ��(1---6)��\n";
   cout<<"1:��������   2:�۰��������\n";
   cout<<"3:��������   4:ѡ������\n";
   cout<<"5:������     6:�˳�\n";
   cout<<"ѡ����k:";cin>>k;
   if(k<0||k>6) cout<<"����ѡ�����������!\n";
   switch(k){
    case 1:InsertSort(&s);break;
    case 2:BInsertSort(&s);break;
    case 3:QuickSort(&s);break;
    case 4:SelectSort(&s);break;
    case 5:HeapSort(&s);break;
    case 6:return;}
   cout<<"���������a:\n";
   for(i=1;i<11;i++)
    cout<<setw(4)<<s.r[i].key;
   cout<<endl;
  }
 getch();
}
