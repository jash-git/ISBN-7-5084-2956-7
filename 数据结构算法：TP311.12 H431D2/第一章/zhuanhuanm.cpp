//zhuanhuanm.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
//����int isdigit(int c)������ԭ��
#include<ctype.h>
typedef char ElemType;
#include "zhuanhuan.cpp"

void main()
{printf("\nzhuanhuanm.cpp���н��:\n");
 printf("������׺���ʽ:");
 char p1[40],p2[40];
 gets(p1);
 zhuanhuan(p1,p2);
 printf("\n�����׺���ʽ:");
 printf("%s",p2);cin.get();
}
 


