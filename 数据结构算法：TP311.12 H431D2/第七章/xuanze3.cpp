//ѡ������(�෽��)xuanze3.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define N 10
class xuanze
{public:
  xuanze(int a[],int m):n(m)
  {for(int i=0;i<n;i++) b[i]=a[i];}
  void xuanzesort()
  {int i,j,k;
   for(i=0;i<n-1;i++)
   {k=i;
    for(j=i+1;j<n;j++)
     if(b[k]>b[j]) k=j;
    if(k!=i)
    {int temp=b[k];
     b[k]=b[i];b[i]=temp;}
    for(int m=0;m<n;m++)
     cout<<setw(4)<<b[m];
    cout<<endl;}}
   void output()
   {for(int i=0;i<n;i++)
    cout<<setw(4)<<b[i];
    cout<<endl;}
 private:
  int b[N],n;
};
//ѡ�����򷨲���
void main()
{cout<<"xuanze3.cpp���н��:\n";
 int ai[N],i;
 srand(time(0));
 for(i=0;i<N;i++)
  ai[i]=rand()%100;
 xuanze px(ai,N);
 cout<<"����ǰ����:\n";
 px.output();
 cout<<"�������������ʾ:\n";
 px.xuanzesort();
 cout<<"���������:\n";
 px.output();cin.get();}

