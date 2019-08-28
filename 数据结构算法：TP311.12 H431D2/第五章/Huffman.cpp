//Huffman.cpp
//�շ�������շ�������
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
const int MaxV=1000;//��ʼ�趨�����Ȩֵ
const int MaxBit=10;//��ʼ�趨��������λ��
const int MaxN=10;//��ʼ�趨���������
//�շ������Ľ��ṹ
typedef struct
  {int weight;//Ȩֵ
   int flag;  //���
   int parent;//˫�׽���±�
   int left;//�����±�
   int right;//�Һ����±�
  }HuffNode;
  typedef struct
  {int bit[MaxN];//��ű�������
   int start;//�������ʼ�±�
   int weight;//�ַ���Ȩֵ
  }Code;
//�ඨ��
class HuffmanT
{public:
  //���캯��
  HuffmanT(HuffNode *&,Code *&,int);
  //����Ҷ������Ϊn,Ȩֵ����Ϊweight�ĺշ�����HuffTree
  void MakeHufm(int weight[],int n);
  //��n�����ĺշ�����HuffTree����շ�������huffCode
  void HuffCode(int n);
 private:
  HuffNode *HuffTree;
  Code *huffCode;
};
HuffmanT::HuffmanT(HuffNode *&huffnode,Code *&huCode,int n)
{huffnode=new HuffNode[2*n+1];
 huCode=new Code[n];
 HuffTree=huffnode;
 huffCode=huCode;
}
void HuffmanT::MakeHufm(int weight[],int n)
{int j,m1,m2,x1,x2,i;
 //�շ�����HuffTree�ĳ�ʼ��
 for(i=0;i<2*n-1;i++)
 {if(i<n) HuffTree[i].weight=weight[i];
  else HuffTree[i].weight=0;
  HuffTree[i].parent=0;
  HuffTree[i].flag=0;
  HuffTree[i].left=-1;
  HuffTree[i].right=-1;
 }
 //����շ�����HuffTree��n-1����Ҷ���
 for(i=0;i<n-1;i++)
 {m1=m2=MaxV;
  x1=x2=0;
  for(j=0;j<n+i;j++)
  {if(HuffTree[j].weight<m1&&HuffTree[j].flag==0)
    {m2=m1;
     x2=x1;
     m1=HuffTree[j].weight;
     x1=j;
    }
   else if(HuffTree[j].weight<m2&&HuffTree[j].flag==0)
    {m2=HuffTree[j].weight;
     x2=j;
    }
  }
  //���ҳ�������Ȩֵ��С�������ϲ�Ϊһ������
  HuffTree[x1].parent=n+i;
  HuffTree[x2].parent=n+i;
  HuffTree[x1].flag=1;
  HuffTree[x2].flag=1;
  HuffTree[n+i].weight=HuffTree[x1].weight+HuffTree[x2].weight;
  HuffTree[n+i].left=x1;
  HuffTree[n+i].right=x2;
 }
}
void HuffmanT::HuffCode(int n)
{Code *cd=new Code;
 int child,parent;
 //��n��Ҷ���ĺշ�������
 for(int i=0;i<n;i++)
 {cd->start=n-1;//���ȳ���������һλΪn-1
  cd->weight=HuffTree[i].weight;//ȡ�ñ����ӦȨֵ���ַ�
  child=i;
  parent=HuffTree[child].parent;
  //��Ҷ�������ֱ�������
  while(parent!=0)
  {if(HuffTree[parent].left==child)
    cd->bit[cd->start]=0;//���ӽ�����0
   else
    cd->bit[cd->start]=1;//�Һ��ӽ�����1
   cd->start--;
   child=parent;
   parent=HuffTree[child].parent;
  }
  //����ÿ��Ҷ���ı���Ͳ��ȳ��������ʼλ
  for(int j=cd->start+1;j<n;j++)
   huffCode[i].bit[j]=cd->bit[j];
  huffCode[i].start=cd->start;
  huffCode[i].weight=cd->weight;//��ס�����ӦȨֵ���ַ�
 }
}
//�շ�����������Ĳ���
void main()
{cout<<"Huffman.cpp���н��:\n";
 int i,j,n=4;
 int weight[]={1,3,5,7};
 HuffNode *myHuffTree;
 Code *myHuffCode;
 HuffmanT t(myHuffTree,myHuffCode,n);
 if(n>MaxN)
 {cout<<"nԽ��,�޸�MaxN!\n";exit(1);}
 t.MakeHufm(weight,n);
 t.HuffCode(n);
 //���ÿ��Ҷ���ĺշ�������
 for(i=0;i<n;i++)
 {cout<<"weight="<<myHuffCode[i].weight<<"  Code=";
  for(j=myHuffCode[i].start+1;j<n;j++)
   cout<<myHuffCode[i].bit[j];
  cout<<endl;
 }
 cin.get();
}

