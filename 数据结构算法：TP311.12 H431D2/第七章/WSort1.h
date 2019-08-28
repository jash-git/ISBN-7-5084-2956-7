//����ļ����������WSort1.h
typedef struct
  {int key;
   int stn;}ElemType;
int b=sizeof(ElemType);//b��ʾElemType��¼���͵Ĵ�С
//�ඨ��
class LoadFile
{public:
  //���캯��
  //�������ļ���Ϊfnameָ����ָ�ļ������n����¼
  LoadFile(char* fname,int n);
  //���ļ�A����������λ��s?m��m+1?t�������鲢Ϊ
  //�ļ�R�ж�Ӧλ��s?t�ϵ�һ�������
  void FTwoMerge(fstream &A,fstream &R,int s,int m,int t);
  //���ļ�A����һ�˶�·�鲢���㷨
  void FMergePass(fstream &A,fstream &R,int n,int len);
  //�Դ����ļ����ж�·�鲢������㷨
  void FMergeSort(fstream &A, int BlockSize);
  //˳���ӡff�ļ���ÿ����¼
  void Print(fstream &ff);
};
//���ʵ��
//�������ļ���Ϊfname��ָ����ָ�ļ������n����¼
LoadFile::LoadFile(char* fname, int n)
{ofstream f(fname,ios::out|ios::binary);
 //�������������ļ�������һ������ļ�
 //������f���������ļ����Ӧ���߼��ļ�
 if(!f) {
  cerr<<fname<<' '<<"not found!"<<endl;exit(1);}
 for(int i=0; i<n; i++)
 {//�ٶ���ÿ����¼������������������������
  ElemType x;
  x.key=i;x.stn=rand()%100;
  f.write((char *)&x,b);}
}
//���ļ�A����������λ��s?m��m+1?t�������鲢Ϊ
//�ļ�R�ж�Ӧλ��s?t�ϵ�һ�������
void LoadFile::FTwoMerge(fstream &A,fstream &R,int s,int m,int t)
{int i,j,k;
 ElemType a1,a2;
 i=s; j=m+1; k=s;//�ֱ��ָʾÿ�������Ԫ��λ�õ�ָ�븳��ֵ
 R.seekg(k*b);  //���ļ�R�е��ļ�ָ���Ƶ���¼�±�Ϊk��λ��,
 //�����������ͬʱ����δ�鲢Ԫ��ʱ�Ĵ������
 while(i<=m && j<=t)
  {A.seekg(i*b);
   //���ļ�A�ļ�¼�±�Ϊs��ʼ�Ĺ鲢���ж���һ����¼��a1��
   A.read((char*)&a1,b);
  //���ļ�A�ļ�¼�±�Ϊm+1��ʼ�Ĺ鲢���ж���һ����¼��a2��
   A.seekg(j*b);
   A.read((char*)&a2,b);
  //��a1��a2���������С�ļ�¼д�뵽R�ļ���
  if(a1.stn<=a2.stn) {
     R.write((char*)&a1,b);i++;}
  else {R.write((char*)&a2,b);j++;}}
//��ǰһ���鲢���д��ڵ�δ�鲢Ԫ�ؽ��д���
 A.seekg(i*b);
 while(i<=m) {
   A.read((char*)&a1,b);
   R.write((char*)&a1,b);
   i++;}
 //�Ժ�һ��������д��ڵ�δ�鲢Ԫ�ؽ��д��� 
 A.seekg(j*b);
 while(j<=t) {
   A.read((char*)&a2,b);
   R.write((char*)&a2,b);j++;
}}
//���ļ�A����һ�˶�·�鲢���㷨
void LoadFile::FMergePass(fstream &A,fstream &R,int n,int len)
//���ļ�A��ÿ������Ϊlen������������鲢���ļ�R��
{ElemType x;
 int p=0;//p����ָ��ÿһ�Թ鲢�ε��׼�¼λ��,��ֵΪ0
 while(p+2*len-1<=n-1)
  {//�����鲢���Ⱦ�Ϊlen�������
   FTwoMerge(A,R,p,p+len-1,p+2*len-1);
   p+=2*len;}
 if(p+len-1<n-1)//�鲢����������Ȳ��ȵ������
   FTwoMerge(A,R,p,p+len-1,n-1);
 else { //��ʣ�µ����һ��������Ƶ�R��
   A.seekg(p*b);  //�ƶ��ļ�A�е�ָ�뵽�涨��λ��
   R.seekg(p*b);  //�ƶ��ļ�R�е�ָ�뵽��Ӧλ��
   for(int i=p; i<=n-1; i++) {
     A.read((char*)&x,b);
     R.write((char*)&x,b);}
}}
//�Դ����ļ����ж�·�鲢������㷨
void LoadFile::FMergeSort(fstream &A, int BlockSize)
//���ù鲢����ķ������ļ�A�е�ÿ������
//�ӱ���ΪBlockSize�ļ�¼��������
{char *ff=".\\temp.dat";
 fstream R(ff,ios::in|ios::out|ios::binary|ios::trunc);
 //����һ���ܹ����������ȡ�ĸ����ļ�R
 if(!R) {
  cerr<<"temp.dat"<<' '<<"not open!"<<endl;exit(1);}
 int len=BlockSize;  
 //���������Ϊ����ֵBlockSize��ʼ�鲢
 A.seekg(0,ios::end);  
 //���ļ�A�е�ָ���Ƶ��ļ���ĩβ
 int n=A.tellg()/b;
 //��n��ʾ�ļ��������ļ�¼����,bΪ��¼�Ĵ�С
 while(len<n) {
   FMergePass(A,R,n,len); 
 //��A�鲢��R��,�õ�ÿ�������ĳ���Ϊ2*len
 len*=2;
 //�޸�len��ֵΪR�е�ÿ�������ĳ���
 FMergePass(R,A,n,len);
 //��R�鲢��A��,�õ�ÿ�������ĳ���Ϊ2*len
 len*=2;}
 //�޸�len��ֵΪA�е�ÿ�������ĳ���
 R.close();//�رո����ļ�R
 //�Ӵ�����ɾ��R����Ӧ�������ļ�
 remove(ff);
}
//˳���ӡ��ff�ļ���ÿ����¼
void LoadFile::Print(fstream &ff)
{ElemType x;
 ff.seekg(0,ios::end);//���ļ�ָ�������ļ�δ
 int n=ff.tellg()/b; //��n��ʾ�ļ������ļ�¼��
 ff.seekg(0);  //���ļ�ָ�������ļ���
 for(int i=0;i<n;i++) {
  ff.read((char*) &x, b);//���ļ��ж�һ��¼��x��
  if(i%10==0)//ÿ����ʾ10������
   cout<<endl;//ÿ������ռ4���ַ���ʾλ��
   cout<<setw(4)<<x.stn;}
 cout<<endl;
}


