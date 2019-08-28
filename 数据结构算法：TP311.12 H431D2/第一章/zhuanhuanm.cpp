//zhuanhuanm.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
//含有int isdigit(int c)函数的原型
#include<ctype.h>
typedef char ElemType;
#include "zhuanhuan.cpp"

void main()
{printf("\nzhuanhuanm.cpp运行结果:\n");
 printf("输入中缀表达式:");
 char p1[40],p2[40];
 gets(p1);
 zhuanhuan(p1,p2);
 printf("\n输出后缀表达式:");
 printf("%s",p2);cin.get();
}
 


