//��������(�෽��)charufa1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<time.h>
#include<stdlib.h>
#define MAXI 10
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[MAXI];
class charu
{public:
  charu(sqlist a,int m):n(m)
  {for(int i=0;i<n;i++) b[i]=a[i];}
  void insertsort()
  {int i,j,k;
   for(i=1;i<n;i++)
   {rec d=b[i];
    for(j=i;j>0&&b[j-1].key>d.key;j--)
     b[j]=b[j-1];
    b[j]=d;
    for(k=0;k<n;k++)
     cout<<setw(4)<<b[k].key;
    cout<<endl;}}
  void output()
   {for(int i=0;i<n;i++)
     cout<<setw(4)<<b[i].key;
    cout<<endl;}
 private:
  sqlist b;int n;
};
void main()
{cout<<"charufa1.cpp���н��:\n";
 sqlist a1;int i;
 srand(time(0));
 for(i=0;i<10;i++)
 {a1[i].key=rand()%100;
  a1[i].data=rand()%80;}
 charu px(a1,10);
 cout<<"����ǰ����:\n";
 px.output();
 cout<<"�������������ʾ:\n";
 px.insertsort();
 cout<<"���������:\n";
 px.output();cin.get();}

