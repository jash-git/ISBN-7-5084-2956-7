//计算后缀表达式的值Evaluatem.cpp
#include<iostream.h>
#include<strstrea.h>
#include<iomanip.h>
#include<stdio.h>
typedef float ElemType;
#include "Evaluate.cpp"
void main()
{char p[40];
 float y;
 printf("Evaluatem.cpp运行结果:\n");
 printf("输入后缀表达式:");
 gets(p);
 y=Evaluate(p);
 printf("后缀表达式的值:");
 printf("%5.0f\n",y);cin.get();}


