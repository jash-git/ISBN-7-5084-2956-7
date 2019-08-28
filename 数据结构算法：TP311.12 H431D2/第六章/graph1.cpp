//ͼ����������ʵ��graph1.cpp
#include"graph1.h"
//���캯��,��ʼ��ͼ���ڽӱ�
AdjAdjoin::AdjAdjoin(edgenode **gL,int n)
{GL=gL;
 for(int i=0;i<n;i++)
  {g[i].adj=GL[i]=NULL;}
 size=numE=0;
}
//����ͼ���ڽӱ�
void AdjAdjoin::CreateAdjoin(int n,int k1,int k2,RCW rcw[])
{int i,j,k,e,w;
 cout<<"����ͼ���ܱ���:";
  cin>>e;
 if(k1==0 && k2==0) {  //����������Ȩͼ
   cout<<"����"<<e
       <<"��������Ȩ�ߵ������յ����!"<<endl;
   for(k=1; k<=e; k++) {
    cin>>i>>j;
    Check(n,i,j);
   //�����i�ĵ�����ı�ͷ����һ���߽��
   edgenode *p=new edgenode;
   p->adjvex=j; p->weight=1;
   p->next=GL[i];
   GL[i]=p;//�����j�ĵ�����ı�ͷ����һ���߽��
   p=new edgenode;
   p->adjvex=i; p->weight=1;
   cout<<'('<<p->adjvex<<','<<j<<','<<p->weight<<")\n";
   p->next=GL[j];
   GL[j]=p;}
 }
 else if(k1==0 && k2!=0) {  //����������Ȩͼ
   cout<<"����"<<e
       <<"�������Ȩ�ߵ������յ���ż�Ȩֵ!"<<endl;
   for(k=0; k<e; k++) {
    i=rcw[k].row;j=rcw[k].col;w=rcw[k].weight;
    //cin>>i>>j>>w;
    Check(n,i,j);
   //�����i�ĵ�����ı�ͷ����һ���߽��
   edgenode *p=new edgenode;
   p->adjvex=j; p->weight=w;
   p->next=GL[i];
   GL[i]=p;
   //�����j�ĵ�����ı�ͷ����һ���߽��
   p=new edgenode;
   p->adjvex=i;p->weight=w;
   p->next=GL[j];
   GL[j]=p;}
 }
 else if(k1!=0&&k2==0) {  //����������Ȩͼ
   cout<<"����"<<e<<"��������Ȩ�ߵ������յ����!"<<endl;
   for(k=1; k<=e; k++) {
    cin>>i>>j;
    Check(n,i,j);
    //�����i�ĵ�����ı�ͷ����һ���߽��
    edgenode* p=new edgenode;
    p->adjvex=j; p->weight=1;
    p->next=GL[i];
    GL[i]=p;}
 }
 else if(k1!=0&&k2!=0) {  //����������Ȩͼ
   cout<<"����"<<e
       <<"��������Ȩ�ߵ������յ���ż�Ȩֵ!"<<endl;
   for(k=1; k<=e; k++) {
    cin>>i>>j>>w;
    Check(n,i,j);
    edgenode* p=new edgenode;
    p->adjvex=j; p->weight=w;
    p->next=GL[i];
    GL[i]=p;}}
 numE=e;size=n;   
}
//�ӳ�ʼ��vi������������������ڽӱ�GL��ʾ��ͼ
void AdjAdjoin::dfsAdjoin(bool*& visited,int i,int n)
{cout<<g[i].data<<':'<<i<<"  ";
 visited[i]=true;
 //ȡvi�ڽӱ�ı�ͷָ��
 edgenode *p=GL[i];
 //��������vi��ÿ���ڽӵ�
 while (p!=NULL) {
   int j=p->adjvex;//jΪvi��һ���ڽӵ����
   if(!visited[j])
   dfsAdjoin(visited,j,n);
   p=p->next;  //ʹpָ��vi���������һ���߽��
}}
//�ӳ�ʼ��vi������������������ڽӱ�GL��ʾ��ͼ
void AdjAdjoin::bfsAdjoin(bool*& visited,int i,int n)
{const int  MaxLength=30;
 //����һ������q,��Ԫ������ӦΪ����
 int q[MaxLength]={0};
 //������׺Ͷ�βָ��
 int front=0, rear=0;
 //���ʳ�ʼ��vi
 cout<<g[i].data<<':'<<i<<"  ";
 //��ǳ�ʼ��vi�ѷ��ʹ�
 visited[i]=true;
 //���ѷ��ʹ��ĳ�ʼ�����i���
 q[++rear]=i;
 //�����зǿ�ʱ����ѭ������
 while(front!=rear) {
  //ɾ������Ԫ�أ���һ��ִ��ʱk��ֵΪi
  front=(front+1)%MaxLength;
  int k=q[front];
  //ȡvk�ڽӱ�ı�ͷָ��
  edgenode* p=GL[k];
  while(p!=NULL)
    {//��������vk��ÿһ���ڽӵ�
     int j=p->adjvex;  //vjΪvk��һ���ڽӵ�
     if(!visited[j]) { //��vjû�б����ʹ�����д���
       cout<<g[j].data<<':'<<j<<"  ";
       visited[j]=true;
       rear=(rear+1)%MaxLength;//�������j���
       q[rear]=j;}
       p=p->next; //ʹpָ��vk�ڽӱ����һ���߽��
}}}
//�������ı�����Ƿ�Խ��,��Խ��������
void AdjAdjoin::Check(int n,int& i,int& j)
{while(1) {
  if(i<0||i>=n||j<0||j>=n)
    cout<<"��������,������!";
  else return;
  cin>>i>>j;
 }
}
//ȡ����i��ֵ
char AdjAdjoin::GetValue(const int i)
{if(i<0||i>size)
  {cerr<<"����iԽ��!\n";exit(1);}
 return g[i].data;
}
//ȡ��<v1,v2>��Ȩ
int AdjAdjoin::GetWeight(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"����v1��v2Խ��!\n";exit(1);}
 edgenode *p=g[v1].adj;
 while(p!=NULL&&p->adjvex<v2) p=p->next;
 if(v2!=p->adjvex)
  {cerr<<"��<v1,v2>������!\n";exit(1);}
 return p->weight; 
}
//��λ��pos�����붥��V
void AdjAdjoin::InsertV(const char &V)
{g[size].data=V;
 size++; 
}
//���뻡<v1,v2>,ȨΪweight
void AdjAdjoin::InsertEdge(const int v1,const int v2,int weight)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"����v1��v2Խ��!\n";exit(1);}
 edgenode *q=new edgenode(v2,weight);
 //q->adjvex=v2;q->weight=weight;
 if(g[v1].adj==NULL) //��һ�β���
  g[v1].adj=q;
 else                //�ǵ�һ�β���
  {edgenode *curr=g[v1].adj,*pre=NULL;
   while(curr!=NULL&&curr->adjvex<v2)
   {pre=curr;
    curr=curr->next;
   }
   if(pre==NULL)    //�ڵ�һ�����ǰ����
    {q->next=g[v1].adj;
     g[v1].adj=q;
    }
   else            //������λ�ò���
    {q->next=pre->next;
     pre->next=q;
    }
  }
 numE++; 
}
//ɾ������v�붥��v��ص����б�
void AdjAdjoin::DeleteVE(const int v)
{edgenode *pre,*curr;
 for(int i=0;i<size;i++)
 {pre=NULL;       //ɾ������v�����
  curr=g[i].adj;
  while(curr!=NULL&&curr->adjvex<v)
  {pre=curr;
   curr=curr->next;
  }
  if(pre==NULL&&curr->adjvex==v)
   {g[i].adj=curr->next; //�ó��߽��������ĵ�һ���ʱ
    delete curr;
    numE--;
   }
  else if(curr!=NULL&&curr->adjvex==v)
   {pre->next=curr->next;//�ó��߽����������������ʱ
    delete curr;
    numE--;
   }
 }
 edgenode *p=g[v].adj,*q;
 for(i=v;i<size-1;i++)
  g[i]=g[i+1]; //ɾ������Ķ���vԪ��
 numE--;
 while(p!=NULL)//ɾ������v�����г���
 {q=p->next;
  delete p;    //�ͷſռ�
  p=q;
  numE--;
 }
}
//ɾ����<v1,v2>
void AdjAdjoin::DeleteEdge(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size||v1==v2)
  {cerr<<"����v1��v2����!\n";exit(1);}
 edgenode *curr=g[v1].adj,*pre=NULL;
  while(curr!=NULL&&curr->adjvex<v2)
  {pre=curr;
   curr=curr->next;
  }
  if(pre==NULL&&curr->adjvex==v2)//Ҫɾ���Ľ��������ĵ�һ���
   {g[v1].adj=curr->next;
    delete curr;
    numE--;
   }
  else if(curr!=NULL&&curr->adjvex==v2)//��������ĵ�һ���
   {pre->next=curr->next;
    delete curr;
    numE--;
   }
  else
   {cerr<<"��<v1,v2>������!\n";exit(1);}
}
//ɾ��ͼ���ڽӱ�
void AdjAdjoin::DeleteAdjoin(int n)
{int i;
 edgenode* p;
 for(i=0;i<n;i++)
 {p=GL[i];
  while(p!=NULL)
   {GL[i]=p->next;
    delete p;p=GL[i];
   }
 }
 delete []GL;
}
//�Է���ͨͼ���������������
void AdjAdjoin::dfsAdjoin(int n)
{bool *vis=new bool[NumV()];
 for(int i=0;i<NumV();i++) vis[i]=false;
 for(i=0;i<NumV();i++)
  if(!vis[i]) dfsAdjoin(vis,i,n);
 delete []vis;
}
//�Է���ͨͼ���й����������
void AdjAdjoin::bfsAdjoin(int n)
{bool *vis=new bool[NumV()];
 for(int i=0;i<NumV();i++) vis[i]=false;
 for(i=0;i<NumV();i++)
  if(!vis[i]) bfsAdjoin(vis,i,n);
 delete []vis;
}
void AdjAdjoin::CreatGraph(char V[],int n,RCW E[],int e)
{for(int i=0;i<n;i++) InsertV(V[i]);
 for(int k=0;k<e;k++)
  InsertEdge(E[k].row,E[k].col,E[k].weight);
 cout<<"���������ͼ:\n";
 for(i=0;i<n;i++)
  cout<<g[i].data<<"  ";
 cout<<endl;  
}  
