//ð������(�³�)maopao3.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define N 10
void gensort(int b[],int n)
{int i,j;
 for(i=1;i<n;i++)
 {for(j=0;j<n-i;j++)
   if(b[j]>b[j+1])
    {int temp=b[j];
     b[j]=b[j+1];b[j+1]=temp;}
  for(int k=0;k<n;k++)
   cout<<setw(4)<<b[k];
  cout<<endl;
 }
}
void main()
{cout<<"maopao3.cpp���н��:\n";
 int ai[N],i;
 srand(time(0));
 for(i=0;i<N;i++)
  ai[i]=rand()%100;
 cout<<"����ǰ����:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;
 cout<<"���������ʾ:\n";
 gensort(ai,sizeof(ai)/sizeof(int));
 cout<<"���������:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;cin.get();}






