//�շ�������շ�������
//Huffman1.cpp
#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
const int MaxV=100;//��ʼ�趨�����Ȩֵ
const int MaxBit=15;//��ʼ�趨��������λ��
const int MaxN=15;//��ʼ�趨���������
//�շ������Ľ��ṹ
typedef struct
  {int weight;//Ȩֵ
   int parent;//˫�׽���±�
   int left;//�����±�
   int right;//�Һ����±�
  }HTNode,*HuffmanTree;
typedef char **HuffmanCode;
//����Ȩֵ����Ϊw�ĺշ�����HT,�����n���ַ��ĺշ�������HC
void MakeHufm(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{int m,m1,m2,x1,x2,i,j,start,c,f;
 HuffmanTree p;
 //�շ�����HuffTree�ĳ�ʼ��
 if(n<=1) return;
 m=2*n-1;
 HT=(HuffmanTree)malloc((2*n)*sizeof(HTNode));
 for(p=HT,i=0;i<n;++i,++p,++w)
  {p->weight=*w;p->parent=0;
   p->left=0;p->right=0;}
 for(;i<m;++i,++p)
  {p->weight=0;p->parent=0;
   p->left=0;p->right=0;}
 for(i=n;i<m;++i)//���շ�����
 {m1=m1=MaxV;
  x1=x2=0;
  for(j=0;j<i;j++)
  {if(HT[j].weight<m1&&HT[j].parent==0)
    {m2=m1;
     x2=x1;
     m1=HT[j].weight;
     x1=j;
    }
   else if(HT[j].weight<m2&&HT[j].parent==0)
    {m2=HT[j].weight;
     x2=j;
    }
  }
  //���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
  HT[x1].parent=i;HT[x2].parent=i;
  HT[i].left=x1;HT[i].right=x2;
  HT[i].weight=HT[x1].weight+HT[x2].weight;
 }
 //��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
 HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//ͷָ��
 //���������Ĺ����ռ�
 char *cd=(char *)malloc(n*sizeof(char));
 cd[n-1]='\0';//���������
 for(i=0;i<=n;++i)//����ַ���շ�������
 {start=n-1;//���������λ��
  //��Ҷ�ӵ������������
  for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
   if(HT[f].left==c) cd[--start]='0';
   else cd[--start]='1';
  //Ϊ��i���ַ��������ռ�
  HC[i]=(char *)malloc((n-start)*sizeof(char));
  strcpy(HC[i],&cd[start]);//���Ʊ���
 }
 free(cd);  
}
//�շ�����������Ĳ���
void main()
{cout<<"Huffman1.cpp���н��:\n";
 int i,n=4,q[4]={1,3,5,7};
 HuffmanTree ht;
 char **hc;
 MakeHufm(ht,hc,q,n);
 //���ÿ��Ҷ���ĺշ�������
 for(i=0;i<n;i++)
 {cout<<"weight="<<ht[i].weight;
  cout<<"  Code="<<hc[i]<<'\n';
 }
 cin.get();
}

