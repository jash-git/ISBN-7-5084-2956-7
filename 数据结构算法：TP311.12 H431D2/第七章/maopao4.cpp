//ͨ��ð������(�ϸ�)maopao4.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define N 10
typedef int (*isgreat)(void *this_num,void *next_num);
void gensort(void *base,int n,int elemsize,isgreat great)
{int i,j;
 for(i=0;i<n-1;i++)
 {char *this_num=(char *)base+i*elemsize;
  char *that=this_num;
  for(j=i+1;j<n;j++)
  {char *next_num=(char *)base+j*elemsize;
   if(great(that,next_num)>0)
    for(int k=0;k<elemsize;k++)
    {char temp=next_num[k];
     next_num[k]=that[k];
     that[k]=temp;}}
 }
}
int greatint(void *first,void *second)
 {return (*(int *)first>*(int *)second);}
int greatfloat(void *first,void *second)
 {return (*(float *)first>*(float *)second);}
void main()
{cout<<"maopao4.cpp���н��:\n";
 int ai[N],i;
 srand(time(0));
 for(i=0;i<N;i++)
  ai[i]=rand()%100;
 cout<<"����ǰ����:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];cout<<endl;
 gensort(ai,sizeof(ai)/sizeof(int),sizeof(int),greatint);
 cout<<"���������:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];cout<<endl;
 float bf[N];
 for(i=0;i<N;i++)
  bf[i]=rand()/200.0;
 cout<<setiosflags(ios::fixed);
 cout<<"����ǰ����:\n";
 for(i=0;i<N;i++)
  cout<<setprecision(2)<<setw(7)<<bf[i];cout<<endl;
 gensort(bf,sizeof(bf)/sizeof(float),sizeof(float),greatfloat);
 cout<<"���������:\n";
 for(i=0;i<N;i++)
  cout<<setprecision(2)<<setw(7)<<bf[i];
 cout<<endl;cin.get();}





