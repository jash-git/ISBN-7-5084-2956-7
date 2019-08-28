//ͼ����������ʵ��graph0.cpp
#include"graph0.h"
//���캯��,��ʼ��ͼ���ڽӾ���
AdjMatrix::AdjMatrix(int n,int k2)
{int i,j;
 if(k2==0){//��ʼ����(��)����Ȩͼ
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    GA[i][j]=0;}
 else {//��ʼ����(��)����Ȩͼ
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    if(i==j) GA[i][j]=0;
    else GA[i][j]=MaxValue;}
 size=numE=0;
}
//����ͼ���ڽӾ���
void AdjMatrix::CreateMatrix(int n,int k1,int k2,RCW r[])
//k1Ϊ0���������Ϊ����,k2Ϊ0����Ȩ����Ϊ��Ȩ
{int i,j,k,e,w;
 cout<<"����ͼ���ܱ���:";
   cin>>e;
 if(k1==0 && k2==0) { //����������Ȩͼ
  cout<<"����"<<e<<"��������Ȩ�ߵ������յ����!"<<endl;
  for(k=0; k<e; k++) {
   i=r[k].row;j=r[k].col;
   Check(n,i,j);
   GA[i][j]=GA[j][i]=1;}
  }
 else if(k1==0 && k2!=0) { //����������Ȩͼ
   cout<<"����"<<e<<"�������Ȩ�ߵ������յ���ż�Ȩֵ!"<<endl;
   for(k=0; k<e; k++) {
    i=r[k].row;j=r[k].col;w=r[k].weight;
    Check(n,i,j);
    GA[i][j]=GA[j][i]=w;}
  }
  else if(k1!=0 && k2==0) { //����������Ȩͼ
    cout<<"����"<<e<<"��������Ȩ�ߵ������յ����!"<<endl;
    for(k=0; k<e; k++) {
     i=r[k].row;j=r[k].col;
     Check(n,i,j);
     GA[i][j]=1;}
  }
  else if(k1!=0 && k2!=0) { //����������Ȩͼ
    cout<<"����"<<e<<"��������Ȩ�ߵ������յ���ż�Ȩֵ!"<<endl;
    for(k=0; k<e; k++) {
     i=r[k].row;j=r[k].col;w=r[k].weight;
     Check(n,i,j);
     GA[i][j]=w;}}
  cout<<"��������ڽӾ���:\n";   
  for(i=0;i<n;i++)
  {for(j=0;j<n;j++)
    cout<<setw(4)<<GA[i][j];
   cout<<endl;}
}
//�ӳ�ʼ��vi������������������ڽӾ����ʾ��ͼ
void AdjMatrix::dfsMatrix(bool*& visited,int i,int n,int k2)
{cout<<g[i]<<':'<<i<<"  ";
 visited[i]=true;        //���vi�ѱ����ʹ�
 for(int j=0; j<n; j++)  //��������vi��ÿ���ڽӵ�
  if(k2==0)
   {if(i!=j&&GA[i][j]!=0&&!visited[j])
     dfsMatrix(visited,j,n,k2);}
  else
   if(i!=j&&GA[i][j]!=MaxValue&&!visited[j])
     dfsMatrix(visited,j,n,k2);
}
//�ӳ�ʼ��vi������������������ڽӾ����ʾ��ͼ
void AdjMatrix::bfsMatrix(bool*& visited,int i,int n,int k2)
{const int MaxLength=30;
 //����һ������q,��Ԫ������ӦΪ����
 int q[MaxLength]={0};
 //������׺Ͷ�βָ��
 int front=0,rear=0;
 //���ʳ�ʼ��vi
 cout<<g[i]<<':'<<i<<"  ";
 //��ǳ�ʼ��vi�ѷ��ʹ�
 visited[i]=true;
  //���ѷ��ʹ��ĳ�ʼ�����i���
 q[++rear]=i;
  //�����зǿ�ʱ����ѭ������
 while(front!=rear) {
  //ɾ������Ԫ��,��һ��ִ��ʱk��ֵΪi
  front=(front+1)%MaxLength;
  int k=q[front];
  //��������vk��ÿһ�����ܵ��ڽӵ�
  for(int j=0;j<n;j++)
   if(k2==0)
    {if(k!=j&&GA[k][j]!=0&&!visited[j])
     {//����һ��δ�����ʹ����ڽӵ�vj
      cout<<g[j]<<':'<<j<<"  ";
      visited[j]=true;     //���vj�ѷ��ʹ�
      rear=(rear+1)%MaxLength;//�������j���
      q[rear]=j;
     }
    }
   else
    if(k!=j&&GA[k][j]!=MaxValue&&!visited[j])
     {//����һ��δ�����ʹ����ڽӵ�vj
      cout<<g[j]<<':'<<j<<"  ";
      visited[j]=true;   //���vj�ѷ��ʹ�
      rear=(rear+1)%MaxLength;//�������j���
      q[rear]=j;
     }
}}
//�������ı�����Ƿ�Խ��,��Խ��������
void AdjMatrix::Check(int n,int& i,int& j)
{while(1) {
  if(i<0||i>=n||j<0||j>=n)
    cout<<"��������,������!";
  else return;
    cin>>i>>j;
 }
}
//��ͼ���ڽӾ���õ�ͼ���ڽӱ�
void AdjMatrix::graphChange(adjlist &GL,int n,int k2)
{int i,j;
 if(k2==0)
 {for(i=0;i<n;i++){
  for(j=0;j<n;j++)
    if(GA[i][j]!=0) {
     edgenode* p=new edgenode;
     p->adjvex=j;
     p->next=GL[i];GL[i]=p;
     cout<<'('<<i<<','<<p->adjvex<<") ";}
  cout<<endl;}}
 else {
  for(i=0;i<n;i++){
   for(j=0;j<n;j++)
    if(GA[i][j]!=0 && GA[i][j]!=MaxValue) {
     edgenode* p=new edgenode;
     p->adjvex=j;p->weight=GA[i][j];
     p->next=GL[i];GL[i]=p;
     cout<<'('<<i<<','<<p->adjvex<<','<<p->weight<<") ";}
   cout<<endl;}
}}
//����ͼ
void AdjMatrix::Creatgraph(int n,int e,RCW r[])
{int i,k;
 for(i=0;i<n;i++) InsertV('A'+i,i);
 for(k=0;k<e;k++)
   InsertEdge(r[k].row,r[k].col,r[k].weight);
}
//ȡ����i��ֵ
char AdjMatrix::GetValue(const int i)
{if(i<0||i>size)
  {cerr<<"����iԽ��!\n";exit(1);}
 return g[i];
}
//ȡ��<v1,v2>��Ȩ
int AdjMatrix::GetWeight(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"����v1��v2Խ��!\n";exit(1);}
 return GA[v1][v2]; 
}
//��λ��pos�����붥��V
void AdjMatrix::InsertV(const char &V,int pos)
{int i;
 if(size==MaxV)
  {cerr<<"������,�޷�����!\n";exit(1);}
 if(pos<0||pos>size)
  {cerr<<"����posԽ��!\n";exit(1);}
 for(i=size;i>pos;i--) g[i]=g[i-1];
 g[pos]=V;
 size++; 
}
//���뻡<v1,v2>,ȨΪweight
void AdjMatrix::InsertEdge(const int v1,const int v2,int weight)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"����v1��v2Խ��!\n";exit(1);}
 GA[v1][v2]=weight;
 numE++; 
}
//ɾ������v�붥��v��ص����б�
char AdjMatrix::DeleteVE(const int v)
{for(int i=0;i<size;i++)
  for(int j=0;j<size;j++)
   if((i==v||j==v)&&GA[i][j]>0&&GA[i][j]<MaxValue)
    {GA[i][j]=MaxValue;
     numE--;}
 if(size==0)
  {cerr<<"���ѿ�,��Ԫ�ؿ�ɾ!\n";exit(1);}
 if(v<0||v>size-1)
  {cerr<<"����vԽ��!\n";exit(1);}
 char temp=g[v];
 for(i=v;i<size-1;i++) g[i]=g[i+1];
 size--;
 g[size]='\0';
 return temp;
}
//ɾ����<v1,v2>
void AdjMatrix::DeleteEdge(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size||v1==v2)
  {cerr<<"����v1��v2����!\n";exit(1);}
 GA[v1][v2]=MaxValue;
 numE--;
}
//�Է���ͨͼ���������������
void AdjMatrix::dfsMatrix(int n,int k2)
{bool *vis=new bool[NumV()];
 int i;
 for(i=0;i<NumV();i++) vis[i]=false;
 for(i=0;i<NumV();i++)
  if(!vis[i]) dfsMatrix(vis,i,n,k2);
 delete []vis;
}
//�Է���ͨͼ���й����������
void AdjMatrix::bfsMatrix(int n,int k2)
{bool *vis=new bool[NumV()];
 int i;
 for(i=0;i<NumV();i++) vis[i]=false;
 for(i=0;i<NumV();i++)
  if(!vis[i]) bfsMatrix(vis,i,n,k2);
 delete []vis;
}

