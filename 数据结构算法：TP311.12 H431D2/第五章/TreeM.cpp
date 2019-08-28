//树类相关操作的测试TreeM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include "Tree.h"
#include "Tree.cpp"
void main()
{printf("TreeM.cpp运行结果:\n");
 int i;
 Tree<char> t;
 t.InsertChild('A');
 for(i=0;i<7;i++)
 {t.Root();
  if(i>=3&&i<5) t.FirstChild();
  t.InsertChild('B'+i);
 }
 printf("按后根遍历显示的结点次序为:\n");
 t.DisplayTree1();
 int k;
 printf("\n输入欲删除第几个结点(k):");scanf("%d",&k);
 if(t.DeleteChild1(k))
   printf("\n第%d个孩子结点,删除成功!\n",k);
 else printf("第%d个孩子结点,删除失败!\n",k);
 printf("按先根遍历显示的结点次序为:\n");
 t.DisplayTree();
 cin.get();
 printf("\n析构函数按后根遍历释放结点的次序为:\n");
 cin.get();
}



