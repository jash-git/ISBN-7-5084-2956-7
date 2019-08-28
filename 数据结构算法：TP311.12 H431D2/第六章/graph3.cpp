//ͼ�������ʵ���ļ�graph3.cpp
#include"graph3.h"
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
//��ʼ��ͼ���ڽӱ�
void adjMList::InitGAdjoin(adjlist& GL,int n)
{GL=new edgenode*[n];
 for(int i=0; i<n; i++) GL[i]=NULL;
}
//ɾ��ͼ���ڽӱ�
void adjMList::DeleteAdjoin(adjlist GL,int n)
{int i;
 edgenode* p;
 for(i=0;i<n;i++) {
   p=GL[i];
   while(p!=NULL) {GL[i]=p->next;
    delete p;p=GL[i];}}
 delete []GL;
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
//������Ȩͼ���ڽӾ���
void adjMList::CreateMatrix(int n,int &e,RCW r[])
{int i,j,k=0,w;
 cout<<"���������Ȩͼ��ÿ���ߵ������յ�"<<endl;
 cout<<"��ż�Ȩֵ!ֱ������ȨֵΪ0�ı�Ϊֹ!"<<endl;
 do {i=r[k].row;j=r[k].col;w=r[k].weight;
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
//���ÿ�³˹����������߼�����GE��ʾͼ��
//��С������,����ÿ�������δ�������C��
void adjMList::Kruskal(RCW GE[],RCW C[],int n,int e)
{int i,j;
 RCW x;
 //����������ͼ�ı߼�����
 for(i=1; i<=e-1; i++)
  {x=GE[i];
   for(j=i-1; j>=0; j--)
    if(x.weight<GE[j].weight) GE[j+1]=GE[j];
    else break;
   GE[j+1]=x;
  }
 edgenode* p;
 //�����ڽӱ�s��Ϊ����ʹ��,����ÿһ��������s[i]������ʾһ������
 adjlist s;
 //��ʼ���ڽӱ�s
 InitGAdjoin(s,n);
 //��ʼ��s����,ʹÿһ����������ڲ�ͬ�ļ���
 for(i=0; i<n; i++)
  {p=new edgenode;
   p->adjvex=i;p->next=NULL;
   s[i]=p;}
   int k=1; //k��ʾ����ȡ����С�������еı���,��ֵΪ1
   int d=0; //d��ʾGE�д�ɨ���Ԫ�ص��±�λ��,��ֵΪ0
   //m1��m2�����ֱ��¼һ���ߵ������������ڼ��ϵ����
   int m1,m2;
  //����n-1��ѭ��,�õ���С�������е�n-1����
  while(k<n)
   {//���GE[d]�������������ڼ��ϵ����m1��m2
    for(i=0; i<n; i++)
     {p=s[i];
      while(p!=NULL) {
       if(p->adjvex==GE[d].row) m1=i;
       if(p->adjvex==GE[d].col) m2=i;
	 p=p->next;}
     }
   //����������Ų���,�����GE[d]��
   //�������е�һ����,Ӧ�������뵽����C��
  if(m1!=m2)
   {C[k-1]=GE[d];
    k++;
    //�ϲ���������,������һ����Ϊ�ռ�
    p=s[m1];
    while(p->next!=NULL) p=p->next;
    p->next=s[m2];
    s[m2]=NULL;
   }
  //d����һ��λ��,�Ա�ɨ��GE�е���һ����
  d++;}
  //ɾ���ڽӱ�s
 DeleteAdjoin(s,n);
}
