//ͼ�������ʵ���ļ�graph2.cpp
#include"graph2.h"
//���캯��,��ʼ��ͼ���ڽӾ�����߼�����
adjMList::adjMList(RCW GE[],int n,int e)
{int i,j;
 for(i=0; i<n; i++)
 for(j=0; j<n; j++)
  if(i==j) GA[i][j]=0;
  else GA[i][j]=MaxValue;
 for(i=0;i<e;i++) GE[i].weight=0;
 numE=0;
}
//����߼������е�ÿ����
void adjMList::OutputEdgeSet(RCW ge[],int e)
{int i,k=0;
 cout<<"{";
 for(i=0; i<=e-2; i++)
  if(ge[i].weight>0){k++;
   cout<<'('<<ge[i].row<<','<<ge[i].col;
   cout<<','<<ge[i].weight<<") ";
   if(k%5==0) cout<<endl;}
  if(e>0&&ge[i].weight>0) {
   cout<<'('<<ge[e-1].row<<','<<ge[e-1].col;
   cout<<','<<ge[e-1].weight<<')';}
   cout<<'}'<<endl;
}
//���������Ȩͼ���ڽӾ���
void adjMList::CreateMatrix(int n,int &e,RCW r[])
{int i,j,k=0,w;
 cout<<"�������������Ȩͼ��ÿ���ߵ������յ�"<<endl;
 cout<<"��ż�Ȩֵ!ֱ������ȨֵΪ0�ı�Ϊֹ!"<<endl;
 do {i=r[k].row;j=r[k].col;w=r[k].weight;
     //cin>>i>>j>>w;
     Check(n,i,j);
     if(k==e-1) break;
     GA[i][j]=GA[j][i]=w;k++;
   }while(1);
 numE=e=k;
 cout<<"�ڽӾ���:\n";
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
   cout<<setw(4)<<GA[i][j];
   cout<<endl;}
}
//�������ı�����Ƿ�Խ��,��Խ��������
void adjMList::Check(int n, int& i, int& j)
{while(1) {
   if(i<0 || i>=n ||j<0 || j>=n)
    cout<<"��������,������!";
   else return;
  cin>>i>>j;}
}
//����ͼ���ڽӾ�������ͼ�ı߼�����
void adjMList::ChangeEdgeSet(RCW GE[],int n,int e)
{//�ٶ�ֻ��������ͼ�����
 int i,j,k=0;
 for(i=0; i<n; i++)
 for(j=i+1; j<n; j++)
  if(GA[i][j]!=0 && GA[i][j]!=MaxValue)
   {if(k==e) {cout<<"����GE�±�Խ��!\n";
     exit(1);}
    GE[k].row=i;
    GE[k].col=j;
    GE[k].weight=GA[i][j];
    k++;
   }
}
//����������ͼ�ı߼�����
void adjMList::SortEdgeSet(RCW GE[],int e)
{int i,j;
 RCW x;
 for(i=1; i<=e-1; i++)
  {x=GE[i];
   for(j=i-1; j>=0; j--)
    if(x.weight<GE[j].weight) GE[j+1]=GE[j];
    else break;
   GE[j+1]=x;
  }
}
//��������ķ�㷨�Ӷ���v0����������ڽӾ���GA��ʾ
//��ͼ����С������,��С�������ı߼���������CT��
void adjMList::Prim(RCW CT[],int n)
{int i,j, k, min, t, m, w;
  //��CT����ֵ����ӦΪv0���ε����������ı�
 for(i=0; i<n-1; i++)
  {CT[i].row=0;
   CT[i].col=i+1;
   CT[i].weight=GA[0][i+1];}
   //����n-1��ѭ����ÿ�������С�������еĵ�k����
 for(k=1; k<n; k++)
  {//��CT[k-1]~CT[n-2]�в�����̱�CT[m]
   min=MaxValue;
   m=k-1;
   for(j=k-1; j<n-1; j++)
    if(CT[j].weight<min) {
     min=CT[j].weight;
     m=j;}
  //����̱߶Ե�����k-1�±�λ��
  RCW temp=CT[k-1];
  CT[k-1]=CT[m];
  CT[m]=temp;
  //���²�����С������T�еĶ�����Ÿ���j
  j=CT[k-1].col;
  //�޸��йرߣ�ʹT�е�T���ÿһ�����������
  //һ����ĿǰΪֹ��̵ı�
  for(i=k; i<n-1; i++) {
   t=CT[i].col;
   w=GA[j][t];
   if(w<CT[i].weight) {
    CT[i].weight=w;
    CT[i].row=j;
}}}}

