//WSort.h
//������ļ�(�����ļ�)����������㷨
typedef struct
  {int key;
   int stn;}ElemType;
int b=sizeof(ElemType);
//�ඨ��
class LoadFile
{public:
  //���캯��
  //�������ļ���Ϊfnameָ����ָ�ļ������n����¼
  LoadFile(char* fname,int n);
  //����ѡ�����򷨶��ļ�A�ļ�¼��������
  void FMergeSort(fstream &A,ElemType (&a)[10],int n);
  //˳���ӡff�ļ���ÿ����¼
  void Print(fstream &ff);
};
//���ʵ��
//�������ļ���Ϊfnameָ����ָ�ļ������n����¼
LoadFile::LoadFile(char* fname,int n)
{fstream f(fname,ios::out|ios::dec|ios::trunc);
 //�������������ļ�������һ������ļ�������f��
 //�����������ļ����Ӧ���߼��ļ�
 if(!f) {
  cerr<<fname<<' '<<"not found!"<<endl;exit(1);}
 for(int i=0;i<n;i++) 
 {//�ٶ���ÿ����¼������������������,��ֵ���������
  ElemType x;
  x.key=i;x.stn=rand()%200;
  f.write((char *)&x,b);}
  f.close();}//�ر��߼��ļ�f
//����ѡ�����򷨶��ļ�A�ļ�¼��������
void LoadFile::FMergeSort(fstream &A,ElemType (&a)[10],int n)
{int i,j,k;
 A.seekg(0,ios::end);//���ļ�ָ�������ļ�δ
 A.seekg(0);//���ļ�ָ�������ļ���
 for(i=0;i<n;i++)
  A.read((char*)&a[i],b);//���ļ��ж�һ��¼��a[i]��
 for(i=0;i<n-1;i++)
 {k=i;
  for(j=i+1;j<n;j++)
   if(a[k].stn>a[j].stn) k=j;
  if(k!=i)
  {int t;
   t=a[k].stn;a[k].stn=a[i].stn;a[i].stn=t;
   t=a[k].key;a[k].key=a[i].key;a[i].key=t;}
 }
 A.seekg(0);
 for(i=0;i<10;i++)
  A.write((char *)&a[i],b);
}
//˳���ӡff�ļ���ÿ����¼
void LoadFile::Print(fstream &ff)
{ElemType x;
 ff.seekg(0,ios::end);//���ļ�ָ�������ļ�δ
 int n=ff.tellg()/b;  //��n��ʾ�ļ������ļ�¼��
 ff.seekg(0);  //���ļ�ָ�������ļ���
 for(int i=0;i<n;i++) {
   ff.read((char*)&x,b);//���ļ��ж�һ��¼��x��
   cout<<setw(4)<<x.stn;}
 cout<<endl;
}

