//字符串的模式匹配Findstr.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSTRLEN 64

void GetNext(char T[MAXSTRLEN],int (&next)[64])
{int i,j;i=1;next[1]=j=0;
 while(i<(int)T[0])
 if(j==0||T[i]==T[j])
  {++i;++j;next[i]=j;}
 else j=next[j];
 for(j=1;j<(int)T[0];j++)
 {printf("next[%d]=%-3d",j,next[j]);
  if((j)%5==0) printf("\n");}
 cout<<endl; 
}
void GetNext(char T[MAXSTRLEN],int (&next)[64],int m)
{int i,j;i=0;next[0]=-1;
 for(j=1;j<m;j++)
 {i=next[j-1];
 while(T[j]!=T[i+1]&&i>=0) i=next[i];
 if(T[j]==T[i+1]) next[j]=i+1;
 else next[j]=-1;}
 for(j=0;j<=m;j++)
  {printf("next[%d]=%-3d",j,next[j]);
   if((j+1)%5==0) printf("\n");}
 cout<<endl;
}
void GetNextVal(char T[MAXSTRLEN],int (&next)[64])
{int i,j;i=1;next[1]=j=0;
 while(i<(int)T[0])
 if(j==0||T[i]==T[j])
  {++i;++j;
   if(T[i]!=T[j]) next[i]=j;
   else next[i]=next[j];}
  else j=next[j];
 for(i=1;i<(int)T[0];i++)
  {printf("next[%d]=%-3d",i,next[i]);
   if(i%5==0) cout<<endl;}
 cout<<endl;  
}
int IndexKMP(char S[MAXSTRLEN],char T[MAXSTRLEN],int (&next)[64])
{int i,j,n,m;i=j=1;
 n=(int)S[0];m=(int)T[0];
 while((i<n||j<m)&&T[j]!='\0'&&S[i]!='\0')
  if(j==0||S[i]==T[j]) {++i;++j;}
  else j=next[j];
 if(j>=m) return i+1-m;
 else return 0;
}
int IndexKMP(char S[MAXSTRLEN],char T[MAXSTRLEN],int (&next)[64],int pos)
{int i,j;i=pos;j=1;
 while((i<(int)S[0]||j<(int)T[0])&&T[j]!='\0'&&S[i]!='\0')
  if(j==0||S[i]==T[j]) {++i;++j;}
  else j=next[j];
 if(j>=(int)T[0]) return i+1-(int)T[0];
 else return 0;
}
int IndexKMP(char S[MAXSTRLEN],char T[MAXSTRLEN],int (&next)[64],int n,int m)
{int i,j;i=j=0;
 while(i<n&&j<m)
  if(S[i]==T[j]) {++i;++j;}
  else if(j==0) i++;
       else j=next[j-1]+1;
 if(j<m) return -1;
 else return i-m+1;
}
int IndexBF(char S[MAXSTRLEN],char T[MAXSTRLEN],int pos)
{int i,j;i=pos;j=1;
 while(i<=S[0]&&j<=T[0])
  if(S[i]==T[j]) {++i;++j;}
  else {i=i-j+2;j=1;}
 if(j>T[0]) return i-T[0];
 else return 0;
}
void main()
{printf("Findstr.cpp运行结果:\n");
 int Index,N,M,next[64]={0};
 char s[MAXSTRLEN],t[MAXSTRLEN];
 printf("GetNext-IndexKMP的结果:\n");
 printf("输入主串s:");gets(s);
 printf("输入模式串t:");gets(t);
 N=strlen(s);M=strlen(t);
 printf("主串s长=%d\n",N);
 printf(" 模式串t长=%d\n",M);
 GetNext(t,next,M);
 Index=IndexKMP(s,t,next,N,M);
 if(Index!=-1)
  printf("模式串在主串的位置从第%d个字符开始\n",Index);
 else printf("主串s中不含模式串t\n");

 printf("GetNext-IndexKMP的结果:\n");
 s[0]=N;t[0]=M;
 GetNext(t,next);
 Index=IndexKMP(s,t,next,1);
 if(Index)
  printf("模式串在主串的位置从第%d个字符开始\n",Index);
 else printf("主串s中不含模式串t\n");

 printf("GetNextVal-IndexKMP的结果:\n");
 GetNextVal(t,next);
 Index=IndexKMP(s,t,next,1);
 if(Index)
  printf("模式串在主串的位置从第%d个字符开始\n",Index);
 else printf("主串s中不含模式串t\n");

 printf("GetNext-IndexKMP的结果:\n");
 GetNext(t,next);
 Index=IndexKMP(s,t,next);
 if(Index)
   printf("模式串t在主串s中的位置从第%d个字符开始\n",Index);
 else printf("主串s中不含模式串t\n");
 
 printf("IndexBF的结果:\n");
 Index=IndexBF(s,t,1);
 if(Index)
   printf("模式串t在主串s中的位置从第%d个字符开始\n",Index);
 else printf("主串s中不含模式串t\n");
 cin.get();}


