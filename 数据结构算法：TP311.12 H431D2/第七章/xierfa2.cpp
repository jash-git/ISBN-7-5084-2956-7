//ϣ������xierfa2.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define MAXI 11
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[MAXI];
void shellsort(sqlist b,int n)
{int i,j,gap,k;rec x;
 gap=n/2;
 while(gap>0)
 {for(i=gap+1;i<n;i++)
  {j=i-gap;
   while(j>0)
   if(b[j].key>b[j+gap].key)
   {x=b[j];b[j]=b[j+gap];
    b[j+gap]=x;j=j-gap;}
   else j=0;
   for(k=1;k<n;k++)
    cout<<setw(4)<<b[k].key;
   cout<<endl;}
   gap=gap/2;}
}
void main()
{cout<<"xierfa2.cpp���н��:\n";
 sqlist a;int i,n=MAXI;
 srand(time(0));
 for(i=1;i<n;i++)
  {a[i].key=rand()%80;
   a[i].data=rand()%100;}
 cout<<"����ǰ����:\n";
 for(i=1;i<n;i++)
  cout<<setw(4)<<a[i].key;
 cout<<endl;
 cout<<"�������������ʾ:\n";
 shellsort(a,n);
 cout<<"���������:\n";
 for(i=1;i<n;i++)
  cout<<setw(4)<<a[i].key;
 cout<<endl;cin.get();}

