//最小堆类的测试minheapm.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
typedef int ElemType;
#include "minheap.cpp"
void PrintArray(int a[],int n)
{for(int i=0;i<n;i++)
  cout<<setw(3)<<a[i];
 cout<<endl;
}
void main()
{cout<<"minheapm.cpp运行结果:\n";
 ElemType b[10];
 srand(350);
 for(int i=0;i<10;i++)
  b[i]=rand()%100;
 cout<<"输出数组b:\n";
 PrintArray(b,10);
 minheap H(10),H1(10);
 for(i=0;i<10;i++)
  H.heapInsert(b[i]);
 cout<<"输出当前堆H的堆顶元素:\n";
 cout<<setw(3)<<H.GetTop()<<endl;
 cout<<"输出插入后数组b:\n";
 PrintArray(b,10);
 cout<<"输出逐个删除的H堆中元素:\n";
 while(!H.heapEmpty())
  cout<<setw(3)<<H.heapDelete();
 cout<<endl;
 for(i=0;i<10;i++)
  H1.heapInsert(rand()%100);
 cout<<"输出当前堆H1的堆顶元素:\n";
 cout<<setw(3)<<H1.GetTop()<<endl;
 cout<<"输出逐个删除的H1堆中元素:\n";
 while(!H1.heapEmpty())
  cout<<setw(3)<<H1.heapDelete();
 cout<<endl;
 H.Destroyheap();H1.Destroyheap();
 getch();}


