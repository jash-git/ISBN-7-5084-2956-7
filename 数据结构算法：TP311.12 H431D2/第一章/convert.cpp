//十进制数转换成八进制数convert.cpp
#include<iostream.h>
#include<iomanip.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
typedef int Status;
typedef int SElemType;
#include "stack.cpp"

void conversion()
{SqStack *S;
 SElemType e;
 int n;
 S->InitStack(&S);
 printf("输入十进制数:");cin>>n;
 if(n<0)
   { printf("\n数必须大于零!\n");
     return;}
 if(!n) S->Push(0);
 while(n){
   S->Push(n%8);n=n/8;}
 printf("结果是:");
 while(!S->StackEmpty()){
   S->Pop(&e);
   printf("%d",e);}
}
void main()
{ printf("convert.cpp运行结果:\n");
  conversion();
  getch();}
