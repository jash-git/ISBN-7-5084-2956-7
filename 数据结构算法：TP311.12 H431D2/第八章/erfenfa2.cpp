//���ֲ��ҷ�(�ǵݹ����)erfenfa2.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
void binsrch(int a[],int n,int x)
{int mid,top=0,bot=n-1,find=0,m=0;
 do {
  m=m+1;
  mid=(top+bot)/2;
  if(a[mid]==x)
   {cout<<x<<"���������ҵ�!\n";find=1;}
  else if(x<a[mid]) bot=mid-1;
  else if(x>a[mid]) top=mid+1;
 }while((top<=bot)&&(find==0));
 if(find==0) cout<<x<<"��������δ�ҵ�!\n";
 cout<<"���Ҵ���:"<<m<<endl;}
void main()
{cout<<"erfenfa2���н��:\n";
 int b[]={1,3,5,7,9,10,12,15,17,19};
 int x=9,n=10;
 cout<<"����Ҫ���ҵ�x:";cin>>x;
 cout<<"���ҽ��:\n";
 binsrch(b,n,x);
 cin.get();cin.get();}


