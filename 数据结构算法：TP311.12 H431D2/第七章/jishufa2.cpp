//��������(����ģ��)jishufa2.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
const int N=10;
const int rd=10;
const int D=2;
void output(int a[],int n)
 {cout<<"    ";
  for(int i=0;i<n;i++)
   cout<<setw(4)<<a[i];
  cout<<endl;}
template<class Elem,class Comp>
void radix(Elem A[],Elem B[],int n,int k,int r,int cnt[])
{int j;
 for(int i=0,rtok=1;i<k;i++,rtok*=r)
 {for(j=0;j<r;j++) cnt[j]=0;
  for(j=0;j<n;j++) cnt[(A[j]/rtok)%r]++;
  for(j=1;j<r;j++) cnt[j]=cnt[j-1]+cnt[j];
  for(j=n-1;j>=0;j--) B[--cnt[(A[j]/rtok)%r]]=A[j];
  for(j=0;j<n;j++) A[j]=B[j];
  output(A,n);}
}
void main()
{cout<<"jishufa2.cpp���н��:\n";
 int a[N],b[N],c[N],i,k=2;
 srand(time(0));
 for(i=0;i<N;i++)
 {a[i]=rand()%100;
  b[i]=0;}
 cout<<"����ǰ����a:\n";
 output(a,N);
 cout<<"��������Ĺ�����ʾ:\n";
 radix<int,int>(a,b,10,k,10,c);
 cout<<"���������a:\n";
 output(a,N);cin.get();}







