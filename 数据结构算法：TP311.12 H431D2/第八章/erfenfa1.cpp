//���ֲ��ҷ�(�ݹ����)erfenfa1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
double a[10]={1.1,1.3,1.5,1.7,1.9,2.1,2.3,2.5,2.7,2.9};
void binsrch(int s,int r,double x)
{int m;
 m=(s+r)/2;
 if(a[m]==x)
  {cout<<x<<"���������ҵ�!\n";}
 else if(s>r)
   {cout<<x<<"��������δ�ҵ�!\n";
    cin.get();cin.get();exit(-1);}
 else if(x>a[m])
    binsrch(m+1,r,x);
 else binsrch(s,m-1,x);
}
void main()
{cout<<"erfenfa1���н��:\n";
 double x=2.3;
 int s=0,r=9;
 cout<<"����x:";cin>>x;
 cout<<"���ҽ��:\n";
 binsrch(s,r,x);
 cin.get();cin.get();}


