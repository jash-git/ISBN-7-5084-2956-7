//����������JinBiaoSai.cpp
#include<iostream.h>
#include<iomanip.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
class DataNode //ʤ���������ඨ��
{public:
  int data;//����ֵ
  int index;//���еĽ���
  int active;//��ѡ��־
};
//�����������еĵ����㷨;i�Ǳ��е�ǰ
//��СԪ�ص��±�,��ʤ��.������ʼ���ϵ���
void UpdataTree(DataNode *tree,int i)
{int j;
 if(i%2==0) //iΪż��,����Ϊ����
  tree[(i-1)/2]=tree[i-1];//iΪ����,����Ϊ�ҽ��
 else
  tree[(i-1)/2]=tree[i+1];
 i=(i-1)/2; //i������˫�׽��λ��
 while(i)
 {if(i%2==0) j=i-1;//ȷ��i�Ķ���Ϊ���㻹���ҽ��
  else j=i+1;
  if(!tree[i].active||!tree[j].active)//���������м���һ����
   if(tree[i].active) tree[(i-1)/2]=tree[i];
   else tree[(i-1)/2]=tree[j]; //�ǿ���������˫�׽��
  else                         //�������ֶ���Ϊ��
   if(tree[i].data<tree[j].data) tree[(i-1)/2]=tree[i];
   else tree[(i-1)/2]=tree[j];//ʤ��������˫�׽��
  i=(i-1)/2; //i������˫�׽��
}}
//��������˳��洢����tree,������a[]�е�Ԫ�ظ��Ƶ�ʤ������,
//�����ǽ�������,���ѽ������������,n�Ǵ�����Ԫ�ظ���
void TournmentSort(int a[],int n)
{DataNode *tree; //ʤ�����������
 DataNode item;
 int m,i,j=0;
 for(int k=0;k<n;k++)//��������>=n��2����С���ݵ���
  {m=pow(2,k);if(m>=n) break;}
 int bottomRowSize=m;
 int TreeSize=2*bottomRowSize-1;//����ʤ�����Ĵ�С:�ڽ��+������
 int loadindex=bottomRowSize-1;//���㿪ʼλ��
 tree=new DataNode[TreeSize];  //��̬����ʤ�����������ռ�
 for(i=loadindex;i<TreeSize;i++)//�����������ݵ�����������
 {tree[i].index=i;//�±�
  if(j<n) {tree[i].active=1;tree[i].data=a[j++];}//��������
  else tree[i].active=0; //����Ľ��Ϊ�յ�����
 }
 i=loadindex;           //���г�ʼ�Ƚ�Ѱ����С����
 while(i)
 {j=i;
  while(j<2*i)          //������Ա�����
  {if(!tree[j+1].active||tree[j].data<tree[j+1].data)
    tree[(j-1)/2]=tree[j];
   else tree[(j-1)/2]=tree[j+1];//ʤ������˫��
   j+=2; //��һ�ԲμӱȽϵ���
  }
  i=(i-1)/2;//i�˵�˫��,ֱ��i=0Ϊֹ
 }
 for(i=0;i<n-1;i++)//��������n-1��Ԫ��
 {a[i]=tree[0].data;//��ǰ��СԪ��������a
  tree[tree[0].index].active=0;//��Ԫ����Ӧ���㲻�ٱ���
  UpdataTree(tree,tree[0].index);//�Ӹô������޸�
 }
 a[n-1]=tree[0].data;
}
//���������򷨵Ĳ���
void main()
{cout<<"JinBiaoSai.cpp���н��:\n";
 int n,b[100],i;
 srand(time(0));
 cout<<"���������Ԫ�ظ���n:";cin>>n;
 for(i=0;i<n;i++) b[i]=rand()%100;
 cout<<"����ǰ����:\n";
 for(i=0;i<n;i++)
  cout<<setw(4)<<b[i];
 cout<<endl;
 TournmentSort(b,n);
 cout<<"���������:\n";
 for(i=0;i<n;i++)
  cout<<setw(4)<<b[i];
 cout<<endl;
 cin.get();cin.get();}
 

