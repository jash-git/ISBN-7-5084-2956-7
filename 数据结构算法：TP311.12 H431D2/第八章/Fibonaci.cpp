//Fibonacci���ҷ�Fibonaci.cpp
#include<iostream.h>
typedef int KeyType;
typedef struct RecType
{KeyType key;}RecType;
int fib(int n)
{int i,f,f0=0,f1=1;
 if(n==0) return 0;
 if(n==1) return 1;
 for(i=2;i<=n;i++)
 {f=f0+f1;
  f0=f1;
  f1=f;
 }
 return f;
}

int FibSearch(RecType R[],int m,KeyType k)
{int low,high,mid,f1,f2;
 low=1;
 high=fib(m);
 f1=fib(m-1);
 f2=fib(m-2);
 while(low<=high)
  {mid=low+f1-1;
   if(R[mid].key==k)
    return mid;
   else if(R[mid].key>k)
    {high=mid-1;
     f2=f1-f2;
     f1=f1-f2;}
   else
    {low=mid+1;
     f1=f1-f2;
     f2=f2-f1;
    }
  }
  return 0;
}
//Fibonacci���ҷ�����
void main()
{cout<<"Fibonaci.cpp���н��:\n";
 int n=7;
 KeyType k=21;
 int a[10]={5,8,13,21,34,55,89,144,233,377};
 RecType r[10];
 for(int i=0;i<10;i++)
   r[i].key=a[i];
 if(FibSearch(r,n,k))
  cout<<"���ҳɹ�!\n";
 else cout<<"����ʧ��!\n";
 cin.get();}
