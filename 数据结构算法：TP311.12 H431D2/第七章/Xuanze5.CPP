//选择排序法xuanze5.cpp
//排序后不改变原数组各元素的值
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define M 10
void sortp(int d[],int *pd[],int b[],int size)
{int i,j,k;
 for(i=0;i<size-1;i++)
 {k=i;
  for(j=i+1;j<size;j++)
   if(d[b[k]]>d[b[j]]) k=j;
  if(i!=k)
  {int g=b[i];b[i]=b[k];b[k]=g;}}
 for(i=0;i<size;i++) pd[i]=&d[b[i]];
}
void main()
{cout<<"xuanze5.cpp运行结果:\n";
 int q[M],a[M],*p[M],n=M,i;
 srand(time(0));
 for(i=0;i<n;i++) q[i]=rand()%100;
 for(i=0;i<n;i++) {a[i]=i;p[i]=&q[i];}
 cout<<"排序前数组:\n";
 for(i=0;i<n;i++)
  cout<<setw(4)<<q[i];
 cout<<endl<<"排序后原数组:\n";
 sortp(q,p,a,n);
 for(i=0;i<n;i++)
  cout<<setw(4)<<q[i];
 cout<<endl<<"排序后数组:\n";
 for(i=0;i<n;i++)
  cout<<setw(4)<<*p[i];
 cout<<endl;cin.get();}
