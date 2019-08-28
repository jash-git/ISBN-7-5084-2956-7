//������С����ز������ж�����heapsort.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
typedef int ElemType;

#include "minheap.cpp"
#include "linelist.cpp"
void PrintList(List *L)
{int i,n;
 ElemType e;
 n=L->ListLength();
 for(i=0;i<n;i++)
  {cout<<setw(4)<<L->GetElem(i,&e);
   if((i+1)%10==0) cout<<endl;}
 cout<<endl;
}
void HeapSort(List *L)
{int i,n;
 ElemType e;
 n=L->ListLength();
 minheap H(n);
 for(i=0;i<n;i++)
  H.heapInsert(L->GetElem(i,&e));
 L->ClearList();i=0;
 while(!H.heapEmpty())
  L->ListInsert(i++,H.heapDelete());
 H.Destroyheap();
}
void main()
{cout<<"heapsort.cpp���н��:\n";
 int i;
 List L;
 L.init(&L);
 srand(300);
 for(i=0;i<10;i++)
  L.ListInsert(i,rand()%100);
 cout<<"ԭ��:\n";
 PrintList(&L);
 HeapSort(&L);
 cout<<"������:\n";
 PrintList(&L);
 L.DestroyList(L);
 cin.get();}
 

