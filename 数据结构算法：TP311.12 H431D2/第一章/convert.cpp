//ʮ������ת���ɰ˽�����convert.cpp
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
 printf("����ʮ������:");cin>>n;
 if(n<0)
   { printf("\n�����������!\n");
     return;}
 if(!n) S->Push(0);
 while(n){
   S->Push(n%8);n=n/8;}
 printf("�����:");
 while(!S->StackEmpty()){
   S->Pop(&e);
   printf("%d",e);}
}
void main()
{ printf("convert.cpp���н��:\n");
  conversion();
  getch();}
