//������ز����Ĳ���TreeM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include "Tree.h"
#include "Tree.cpp"
void main()
{printf("TreeM.cpp���н��:\n");
 int i;
 Tree<char> t;
 t.InsertChild('A');
 for(i=0;i<7;i++)
 {t.Root();
  if(i>=3&&i<5) t.FirstChild();
  t.InsertChild('B'+i);
 }
 printf("�����������ʾ�Ľ�����Ϊ:\n");
 t.DisplayTree1();
 int k;
 printf("\n������ɾ���ڼ������(k):");scanf("%d",&k);
 if(t.DeleteChild1(k))
   printf("\n��%d�����ӽ��,ɾ���ɹ�!\n",k);
 else printf("��%d�����ӽ��,ɾ��ʧ��!\n",k);
 printf("���ȸ�������ʾ�Ľ�����Ϊ:\n");
 t.DisplayTree();
 cin.get();
 printf("\n������������������ͷŽ��Ĵ���Ϊ:\n");
 cin.get();
}



