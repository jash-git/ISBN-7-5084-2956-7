//�����׺���ʽ��ֵEvaluatem.cpp
#include<iostream.h>
#include<strstrea.h>
#include<iomanip.h>
#include<stdio.h>
typedef float ElemType;
#include "Evaluate.cpp"
void main()
{char p[40];
 float y;
 printf("Evaluatem.cpp���н��:\n");
 printf("�����׺���ʽ:");
 gets(p);
 y=Evaluate(p);
 printf("��׺���ʽ��ֵ:");
 printf("%5.0f\n",y);cin.get();}


