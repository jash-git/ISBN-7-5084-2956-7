//���ѵ�ʵ��maxheap.cpp
#include "maxheap.h"
maxheap::maxheap(int MaxSize)
{if(MaxSize<=0) {
  cerr<<"����MaxSize�Ƿ�!\n";exit(1);}
 heapArray=(ElemType *) new ElemType[MaxSize];
 if(!heapArray) exit(-1);
 maxheapSize=HeapSIZE;
 heapsize=0;
}
void maxheap::Destroyheap()
{free(heapArray);}

void maxheap::Clearheap()
{heapsize=0;}

bool maxheap::heapEmpty()
{ if(heapsize==0) return true;
  else return false;
}
bool maxheap::heapFull()
{return heapsize==maxheapSize;}
int maxheap::heapLength()
{ return heapsize;}
ElemType maxheap::GetTop()
{ if(heapsize==0)
   {cerr<<"���ѿ�!\n";exit(1);}
  return heapArray[0];
}
void maxheap::FilterUp()
{int c,p;
 ElemType temp;
 c=heapsize-1;
 p=(c-1)/2;
 temp=heapArray[c];
 while(c!=0)
 {if(heapArray[p]>temp) break;
  heapArray[c]=heapArray[p];
  c=p;
  p=(c-1)/2;}
 heapArray[c]=temp;
}
void maxheap::FilterDown()
{int c,p;
 ElemType temp;
 p=0;
 c=2*p+1;
 temp=heapArray[p];
 while(c<heapsize)
 {if(c+1<heapsize&&heapArray[c+1]>heapArray[c])
   c=c+1;
  if(temp>heapArray[c]) break;
  heapArray[p]=heapArray[c];
  p=c;
  c=2*p+1;}
 heapArray[p]=temp;
}
void maxheap::heapInsert(ElemType item)
{if(heapsize==HeapSIZE)
  {cerr<<"������!\n";exit(1);}
 heapArray[heapsize]=item;
 heapsize++;
 FilterUp();
}
ElemType maxheap::heapDelete()
{ElemType temp;
 if(heapsize==0)
  {cerr<<"���ѿ�!\n";exit(1);}
 temp=heapArray[0];
 heapArray[0]=heapArray[heapsize-1];
 heapsize--;
 FilterDown();
 return(temp);}
