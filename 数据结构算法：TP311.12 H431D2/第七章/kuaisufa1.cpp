//��������(�෽��)kuaisufa1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define MAXI 10
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[MAXI];
class kuaisu
{public:
  kuaisu(sqlist a,int m):n(m)
  {for(int i=0;i<n;i++) b[i]=a[i];}
  void quicksort(int s,int t)
  {int i;
   if(s<t) {
    i=part(s,t);
    quicksort(s,i-1);
    quicksort(i+1,t);}
   else return;}
  int part(int s,int t)
  {int i,j;rec p;
   i=s;j=t;p=b[s];
   while(i<j)
   {while(i<j&&b[j].key>=p.key) j--;
     b[i]=b[j];
     while(i<j&&b[i].key<=p.key) i++;
     b[j]=b[i];}
    b[i]=p;
    output();
    return i;}
  void output()
   {for(int i=0;i<n;i++)
    cout<<setw(4)<<b[i].key;
    cout<<endl;}
 private:
  sqlist b;int n;
};
void main()
{cout<<"kuaisufa1.cpp���н��:\n";
 sqlist a1;int i,n=MAXI,low=0,high=9;
 srand(time(0));
 for(i=0;i<n;i++)
  a1[i].key=rand()%80;
 kuaisu px(a1,n);
 cout<<"����ǰ����:\n";
 px.output();
 cout<<"��������Ĺ�����ʾ:\n";
 px.quicksort(low,high);
 cout<<"���������:\n";
 px.output();cin.get();}

