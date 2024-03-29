//桶排序bucketsort.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<time.h>
//欲桶排序的数组长度
const int SIZE=12;
void bucketSort(int []);
void distributeElements(int [],int [][SIZE],int);
void collectElements(int [],int [][SIZE]);
int numberOfDigits(int [],int);
void zeroBucket(int [][SIZE]);

void main()
{cout<<"bucketsort.cpp运行结果:\n";
 int array[SIZE];
 cout<<"原数组:\n";
 srand(time(0));
 for(int i=0;i<SIZE;++i)
 {array[i]=rand()%100;
  cout<<setw(3)<<array[i];}
 cout<<'\n';
 cout<<"排序过程演示:\n";
 bucketSort(array);
 cout<<"排序后数组:\n";
 for(int j=0;j<SIZE;++j)
   cout<<setw(3)<<array[j];
 cout<<endl;cin.get();
}
// 桶排序算法
void bucketSort(int a[])
{int totalDigits,bucket[10][SIZE]={0};
 totalDigits=numberOfDigits(a,SIZE);
 for(int i=1;i<=totalDigits;++i) {
   distributeElements(a,bucket,i);
   collectElements(a,bucket);
   //将桶数组初始化为0
   if(i!=totalDigits) zeroBucket(bucket);
 for(int j=0;j<SIZE;++j)
   cout<<setw(3)<<a[j];
 cout<<endl;}
}
//确定单下标数组的最大数的位数
int numberOfDigits(int b[],int arraySize)
{  int largest=b[0],digits=0;
   for(int i=1;i<arraySize;++i)
     if(b[i]>largest)
      largest=b[i];
  while(largest!=0) {
      ++digits;
      largest/=10;}
  return digits;
}
// 将单下标数组的每个值放到桶数组的行中
void distributeElements(int a[],int buckets[][SIZE],int digit)
{int divisor=10,bucketNumber,elementNumber;
 for(int i=1;i<digit;++i)
   divisor*=10;       
 for(int k=0;k<SIZE;++k) {
  bucketNumber=(a[k]%divisor-a[k]%(divisor/10))/(divisor/10);
  elementNumber=++buckets[bucketNumber][0];
  buckets[bucketNumber][elementNumber]=a[k];}
}
//将桶数组的值复制回原数组
void collectElements(int a[],int buckets[][SIZE])
{int subscript=0;
 for(int i=0;i<10;++i)
  for(int j=1;j<=buckets[i][0];++j)
    a[subscript++]=buckets[i][j];
}
//将桶数组初始化为0
void zeroBucket(int buckets[][SIZE])
{for(int i=0;i<10;++i)
  for(int j=0;j<SIZE;++j)
   buckets[i][j]=0;}

