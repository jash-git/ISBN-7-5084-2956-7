//���б༭LINEEDIT.CPP
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define EOFILE '`'
typedef char Status;
typedef char SElemType;
#include "stack.cpp"
void LineEdit()
{ SqStack *S,*T;
  char str[100];
  int strlen=0;
  char e;
  char ch;
  S->InitStack(&S);
  T->InitStack(&T);
  ch=getchar();
  while(ch!=EOFILE)
   {while(ch!=EOFILE&&ch!='\n')
     { switch(ch){
	case '#':
	  S->Pop(&ch);
	  break;
	case '@':
	  S->ClearStack();
	  break;
	default:
	  S->Push(ch);
          break;}
       ch=getchar();
     }
    if(ch=='\n') S->Push(ch);
      while(!S->StackEmpty())
       {S->Pop(&e);
        T->Push(e);}
      while(!T->StackEmpty())
       { T->Pop(&e);
         str[strlen++]=e;}
    if(ch!=EOFILE) ch=getchar();
   }
  printf("����༭���ַ���:\n");
  str[strlen]='\0';
  printf("%s\n",str);
  S->DestroyStack();
  T->DestroyStack();
}
void main()
{printf("LINEEDIT.CPP���н��:\n");
 printf("�����ַ���,�������ַ�`��Ϊ����:\n");
 LineEdit();
 getch();getch();}
