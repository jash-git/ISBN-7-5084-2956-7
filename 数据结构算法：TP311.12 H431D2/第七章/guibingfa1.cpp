//�鲢����(�෽��)guibingfa1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define M 11
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[M];
class guibing {
 public:
  guibing(sqlist b)
  {for(int i=0;i<M;i++) r[i]=b[i];}
  void output(sqlist r,int n)
  {for(int i=0;i<n;i++)
    cout<<setw(4)<<r[i].key;
   cout<<endl;}
  void xuanze(sqlist b,int m,int n)
  {int i,j,k;
   for(i=m;i<n-1;i++)
   {k=i;
    for(j=i;j<n;j++)
    if(b[k].key>b[j].key) k=j;
    if(k!=i)
    {rec temp=b[k];
     b[k]=b[i];b[i]=temp;}}}
  void merge(int l,int m,int h,sqlist r2)
  {xuanze(r,l,m);
   xuanze(r,m,h);
   output(r,M);
   int i,j,k;
   k=i=l;
   for(j=m;i<m&&j<h;k++)
   {if(r[i].key<=r[j].key)
     {r2[k]=r[i];i++;}
    else
     {r2[k]=r[j];j++;}
    output(r2,M);}
    while(j<h)
    {r2[k]=r[j];j++;k++;}
    while(i<=m)
    {r2[k]=r[i];i++;k++;}
    output(r2,M);}
 private:
   sqlist r;
};
void main()
{cout<<"guibingfa1.cpp���н��:\n";
 sqlist a,b;int i,j=0,k=M/2,n=M;
 srand(time(0));
 for(i=0;i<M;i++)
  {a[i].key=rand()%80;b[i].key=0;}
 guibing gx(a);
 cout<<"����ǰ����:\n";
 gx.output(a,M);
 cout<<"��������Ĺ�����ʾ:\n";
 gx.merge(j,k,n,b);
 cout<<"���������:\n";
 gx.output(b,M);cin.get();}



