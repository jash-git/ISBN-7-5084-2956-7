//ϡ�������ඨ�������xishu.h
//�����0Ԫ���������ֵΪ100
#define MAXSIZE 100
//��Ԫ��˳���
class TSMatrix;
class Triple
{public:
  int ii,jj;//�кź��к�
  ElemType e;
  friend class TSMatrix;
};
class TSMatrix
{public:
   //���캯��
   TSMatrix( ) {}
  //���캯��
  //����һ��Mrow��,Mcol���ҷ���Ԫ����Ϊt��ϡ�����
  TSMatrix(int Mrow,int Mcol,int t);
  //��ϡ������ת�þ���
  void TrMatrix(TSMatrix &);
  //����ת��
  void FastTrMatrix(TSMatrix &);
  //ϡ��������
  void mulmatrix(TSMatrix &,TSMatrix &);
  Triple data[MAXSIZE];//��0��Ԫ���
  int mu,nu,tu;//ϡ�����������������ͷ���Ԫ����
};
//����һ��Mrow��,Mcol���ҷ���Ԫ����Ϊt��ϡ�����
TSMatrix::TSMatrix(int Mrow,int Mcol,int t)
{ int m,n,i,j,f0=0;
  if(t<=0) exit(0);
  ElemType (*A)[MCOL]=new ElemType[MROW][MCOL];
  if(!A){cerr<<"�ڴ����ʧ��!\n";exit(-1);}
  for(i=0;i<Mrow;i++)
   for(j=0;j<Mcol;j++) A[i][j]=0;
  srand(150);
  while(f0<=t)
   {m=rand()%100;
    n=rand()%10;
    if(m>=0&&m<Mrow&&n>=0&&n<Mcol)
     {A[m][n]=rand()%10;
      if(A[m][n]!=0) f0++;
   }}
 for(i=0;i<Mrow;i++)
 {for(j=0;j<Mcol;j++)
   cout<<setw(3)<<A[i][j];
  cout<<endl;}
}
//��ϡ������ת�þ���
void TSMatrix::TrMatrix(TSMatrix &T)
{int p,q,col;
 T.mu=nu;T.nu=mu;T.tu=tu;
 if(T.tu){ //���T�ķ�0Ԫ������Ϊ0
  q=0;
  for(col=0;col<nu;++col)
   for(p=0;p<tu;++p)
     if(data[p].jj==col){
       T.data[q].ii = data[p].jj;
       T.data[q].jj = data[p].ii;
       T.data[q].e = data[p].e;
       ++q;}}
}
//����ת��
void TSMatrix::FastTrMatrix(TSMatrix &T)
{int col,p,q,t,num[N],cpot[N];
 T.mu=nu;T.nu=mu;T.tu=tu;
 if(T.tu){
  for(col=0;col<nu;++col)  num[col] = 0;
    //����Mÿ�з�0Ԫ������Ϊ0
  for(t=0;t<tu;++t)  ++num[data[t].jj];
    //��M��ÿһ�з�0Ԫ����
  cpot[0]=0; //M�е�һ�е�һ����Ԫ��T�е����Ϊ1
  for(col=1;col<nu;++col)
    cpot[col]=cpot[col-1]+num[col-1];
    //��M�е�col���е�һ����0Ԫ��T�е����
  for(p=0;p<tu;++p){
   col=data[p].jj; //����M�е�p��Ԫ�ص��к�
   q=cpot[col];     //�����е�һ����0Ԫ��T�е����
   T.data[q].ii=data[p].jj;
   T.data[q].jj=data[p].ii;
   T.data[q].e=data[p].e;//�С��н���,����ֵ
   ++cpot[col];}} //������һ����0Ԫ���=��һ�����+1
}
//ϡ��������
void TSMatrix:: mulmatrix(TSMatrix &b,TSMatrix &c)
{int i,colB,colA,rowA;
 if(nu!=b.mu){
   cerr<<"error\n"; exit(0);}
 if(tu*b.tu!=0){
  int *rowSize=new int[b.mu];
  int *rowStart=new int[b.mu+1];
  ElemType *temp=new ElemType[b.nu];
  for(i=0;i<b.mu;i++) rowSize[i]=0;
  for(i=0;i<b.tu;i++) rowSize[b.data[i].ii]++;
  rowStart[0]=0;
  for(i=1;i<=b.mu;i++) rowStart[i]=rowStart[i-1]+rowSize[i-1];
  int current=0,lastInresult=-1;
  while(current<tu)
  {rowA=data[current].ii;
   for(i=0;i<b.nu;i++) temp[i]=0;
   while(current<tu&&data[current].ii==rowA)
   {colA=data[current].jj;
    for(i=rowStart[colA];i<rowStart[colA+1];i++)
    {colB=b.data[i].jj;
     temp[colB]+=data[current].e*b.data[i].e;}
     current++;}
     for(i=0;i<b.nu;i++)
     if(temp[i]!=0)
      {lastInresult++;
       c.data[lastInresult].ii=rowA;
       c.data[lastInresult].jj=i;
       c.data[lastInresult].e=temp[i];
      }
    }
 c.mu=mu;c.nu=b.nu;c.tu=lastInresult+1;
 delete []rowSize;delete []rowStart;delete []temp;
}}
