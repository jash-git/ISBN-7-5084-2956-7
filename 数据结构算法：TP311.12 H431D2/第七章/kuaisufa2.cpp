//��������(�෽��)kuaisufa2.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
#define N 10
class kuaisu
{public:
  kuaisu(float a[],int m):n(m)
   {for(int i=0;i<n;i++) b[i]=a[i];}
  void quicksort(int s,int t)
  {int i;
   if(s<t) {
    i=part(s,t);
    quicksort(s,i-1);
    quicksort(i+1,t);}
   else return;}
  int part(int s,int t)
  {int i,j;float p;
   i=s;j=t;p=b[s];
   while(i<j)
   {while(i<j&&b[j]>=p) j--;
     b[i]=b[j];
     while(i<j&&b[i]<=p) i++;
     b[j]=b[i];}
    b[i]=p;
    output();
    return i;}
  void output()
   {for(int i=0;i<n;i++)
    cout<<setprecision(2)<<setw(7)<<b[i];
    cout<<endl;}
 private:
  float b[N];int n;
};
void main()
{cout<<"kuaisufa2.cpp���н��:\n";
 float a1[N];int i,n=N,low=0,high=9;
 srand(time(0));
 for(i=0;i<n;i++)
  a1[i]=rand()/200.0;
 kuaisu px(a1,n);
 cout<<"����ǰ����:\n";
 cout<<setiosflags(ios::fixed);
 px.output();
 cout<<"��������Ĺ�����ʾ:\n";
 px.quicksort(low,high);
 cout<<"���������:\n";
 px.output();cin.get();}

