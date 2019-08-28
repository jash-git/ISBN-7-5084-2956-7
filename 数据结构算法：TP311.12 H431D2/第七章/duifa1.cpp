//������(�෽��)duifa1.cpp
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
class duifa {
 public:
  duifa(sqlist b)
  {for(int i=1;i<M;i++) r[i]=b[i];}
  void output()
  {for(int i=1;i<M;i++)
   cout<<setw(4)<<r[i].key;
    cout<<endl;}
  void sift(int s,int m)
  {int j;rec x;
   x=r[s];
   for(j=2*s;j<=m;j*=2)
   {if(j<m&&(r[j].key<r[j+1].key)) ++j;
    if(!(x.key<r[j].key)) break;
     r[s]=r[j];s=j;}
     r[s]=x;}
  void heapsort(int m)
  {int i;rec w;
   for(i=m/2;i>0;--i) sift(i,m);
   for(i=m;i>1;--i)
   {w=r[i];r[i]=r[1];r[1]=w;
    output();
    sift(1,i-1);}}
 private:sqlist r;
};
void main()
{cout<<"duifa1.cpp���н��:\n";
 sqlist a;int i;
 srand(time(0));
 for(i=1;i<M;i++)
  a[i].key=rand()%80;
 duifa dx(a);
 cout<<"����ǰ����:\n";
 dx.output();
 cout<<"��������Ĺ�����ʾ:\n";
 dx.heapsort(M);
 cout<<"���������:\n";
 dx.output();cin.get();}

