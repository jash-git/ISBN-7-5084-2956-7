//选择排序法xuanze1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define N 10
void gensort(int b[],int n)
{int i,j,k;
 for(i=0;i<n-1;i++)
 {k=i;
  for(j=i+1;j<n;j++)
   if(b[k]>b[j]) k=j;
  if(k!=i)
   {int temp=b[k];
    b[k]=b[i];b[i]=temp;
   }
}}
//选择排序法测试
void main()
{cout<<"xuanze1.cpp运行结果:\n";
 int ai[N],i;
 srand(time(0));
 for(i=0;i<N;i++)
  ai[i]=rand()%100;
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;
 gensort(ai,sizeof(ai)/sizeof(int));
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;cin.get();}

