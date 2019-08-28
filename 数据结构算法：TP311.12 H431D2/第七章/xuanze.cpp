//通用选择排序法xuanze.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define N 10
typedef bool (*isgreat)(void *this_num,void *next_num);
void gensort(void *base,int n,int elemsize,isgreat great)
{int i,j,k;
 for(i=0;i<n-1;i++)
 {k=i;char *this_num=(char *)base+k*elemsize;
  char *that=this_num;
  for(j=i+1;j<n;j++)
   {char *next_num=(char *)base+j*elemsize;
    if(great(that,next_num)) that=next_num;
   }
  if(this_num!=that)
   {for(int k=0;k<elemsize;k++)
     {char temp=this_num[k];
       this_num[k]=that[k];
       that[k]=temp;
}}}}
bool greatint(void *first,void *second)
  {return (*(int *)first>*(int *)second);}
bool greatdouble(void *first,void *second)
  {return (*(double *)first>*(double *)second);}
//通用选择排序法测试
void main()
{cout<<"xuanze.cpp运行结果:\n";
 int ai[N],i;
 srand(time(0));
 for(i=0;i<N;i++)
  ai[i]=rand()%100;
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];cout<<endl;
 gensort(ai,sizeof(ai)/sizeof(int),sizeof(int),greatint);
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];cout<<endl;
 double bf[N];
 for(i=0;i<N;i++)
  bf[i]=rand()/200.0;
 cout<<setiosflags(ios::fixed);
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setprecision(2)<<setw(7)<<bf[i];cout<<endl;
 gensort(bf,sizeof(bf)/sizeof(double),sizeof(double),greatdouble);
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
  cout<<setprecision(2)<<setw(7)<<bf[i];
 cout<<endl;cin.get();}





