//�����ļ�����ز���
//IndexF.cpp
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
//����һ�ζ�д�ļ����߼���Ĵ�С
const int m=5;
//�����ļ���¼���߼�ɾ�����
const int DMark=-10;
//��ؼ��ֵ�����Ϊ����
typedef int KeyType;
//���ļ��еļ�¼����
struct ElemType {
  KeyType key;  //�ؼ�����
  char rest[10];//������,�����ַ������ʾ
};
//�����ļ��еļ�¼����
struct IndexItem {
  KeyType key;  //�ؼ�����
  int next;  //�����Ӧ��¼�Ĵ洢λ����
};
//�����ļ����ඨ��
template<class T,class T1>
class InFile
{public:
  //˳���ӡ�����ļ�fn1�е�ÿ����¼
  void PrintMainFile(char* fn1);
  //˳���ӡ�����������ļ�fn2�е�ÿ��������
  void PrintIndexFile(char* fn2);
  //�������ļ���Ϊfn1ָ����ָ���ļ���׷��n����¼
  void MFAppend(char* fn1,char* fn2,T1 a[],int n);
  //�������ļ���Ϊfn1ָ����ָ���ļ���ɾ��n����¼
  void MFDelete(char* fn1,char* fn2,KeyType a[],int n);
  //�������ļ���Ϊfn1ָ����ָ���ļ��в���n����¼
  void MFSearch(char* fn1,char* fn2,KeyType a[],int n);
  //��һ����¼����������뵽��������A��
  void SeqInsert(T A[], int mm, T x);
  //����fn2ָ������ʾ�����������ļ��в���x������
  void IFInsert(char *fn2, T x);
  //����������A��ɾ��һ���ؼ���Ϊx.key��������
  bool SeqDelete(T A[],int mm,T& x);
  //����fn2ָ������ʾ�����������ļ���ɾ��
  //�ؼ���Ϊx.key��������,����x���ر�ɾ����������
  bool IFDelete(char *fn2, T& x);
  //����fn2ָ������ʾ�����������ļ���
  //���ҹؼ���Ϊx.key���������x����
  bool IFSearch(char* fn2, T& x);
};
//�����ļ�����ʵ��
//˳���ӡ�����ļ�fn1�е�ÿ����¼
template<class T,class T1>
void InFile<T,T1>::PrintMainFile(char* fn1)
{ifstream fin(fn1,ios::in|ios::binary);
 if(!fin)
  {cerr<<fn1<<' '<<"not find!"<<endl;exit(1);}
 T1 x;
 fin.seekg(0,ios::end);       //���ļ�ָ�������ļ�δ
 int b1=sizeof(T1);
 int n=fin.tellg()/b1;        //��n��ʾ�ļ������ļ�¼��
 fin.seekg(0);                //���ļ�ָ�������ļ���
 for(int i=0;i<n;i++) {
    fin.read((char*) &x, b1); //���ļ��ж���һ����¼
    if(i%4==0)  cout<<endl;   //ÿ����ʾ4������
    cout<<setw(5)<<x.key<<setw(10)<<x.rest;}
    cout<<endl;
    fin.close();}
//˳���ӡ�����������ļ�fn2�е�ÿ��������
template<class T,class T1>
void InFile<T,T1>::PrintIndexFile(char* fn2)
{ifstream fin(fn2,ios::in|ios::binary);
 if(!fin)
  {cerr<<fn2<<' '<<"not find!"<<endl;exit(1);}
 T x;
 fin.seekg(0,ios::end);     //���ļ�ָ�������ļ�δ
 int b2=sizeof(T);
 int n=fin.tellg()/b2;      //��n��ʾ�ļ������ļ�¼��
 fin.seekg(0);              //���ļ�ָ�������ļ���
 for(int i=0;i<n;i++) {
 fin.read((char*) &x, b2);  //���ļ��ж���һ��������
 if(i%8==0)  cout<<endl;    //ÿ����ʾ8������
 cout<<setw(4)<<x.key<<setw(3)<<x.next;}
  cout<<endl;
 fin.close();}
//�������ļ���Ϊfn1ָ����ָ���ļ���׷��n����¼
template<class T,class T1>
void InFile<T,T1>::MFAppend(char* fn1,char* fn2,T1 a[],int n)
{//����һ������ļ�������ofs,�����ļ�����ϵ
 ofstream ofs(fn1,ios::out|ios::binary);
 if(!ofs)
  {cerr<<fn1<<' '<<"not open!"<<endl;exit(1);}
 int i;
 //���T1��¼���͵ĳ���
 int b1=sizeof(T1);
 //���ļ�ָ���Ƶ��ļ�β
 ofs.seekp(0, ios::end);
 //�����ǰ���ļ�����
 int flen=ofs.tellp()/b1;
 //��a�����е�n����¼д�뵽���ļ���
 for(i=0; i<n; i++)
   ofs.write((char*) &a[i],b1);
 //�ر��߼��ļ�ofs
 ofs.close();
 //��a��n����¼�����������β��뵽�����ļ�fn2��
 T x;
 for(i=0; i<n; i++) {
  x.key=a[i].key;
  x.next=flen+i;
  IFInsert(fn2,x);}
}
//�������ļ���Ϊfn1ָ����ָ���ļ���ɾ��n����¼
template<class T,class T1>
void InFile<T,T1>::MFDelete(char* fn1,char* fn2,KeyType a[],int n)
{//����һ����������ļ�������fio,�����ļ�����ϵ
 fstream fio(fn1,ios::in|ios::out|ios::binary);
 if(!fio)
  {cerr<<fn1<<' '<<"not open!"<<endl;exit(1);}
 int b1=sizeof(T1);
 T x;
 T1 y;
 int i;
 //����ɾ��ÿ����¼
  for(i=0; i<n; i++) {
    x.key=a[i];
    bool k=IFDelete(fn2,x);
    if(!k)
     {cout<<"�ؼ���Ϊ"<<x.key<<"�ļ�¼������"<<endl;continue;}
    fio.seekg(x.next*b1);
    fio.read((char*) &y, b1);
    y.key=DMark;
    fio.seekg(-b1, ios::cur);
    fio.write((char*) &y, b1);
    cout<<"�ؼ���Ϊ"<<x.key<<"�ļ�¼��ɾ��"<<endl;}
    fio.close();
}
//�������ļ���Ϊfn1ָ����ָ���ļ��в���n����¼
template<class T,class T1>
void InFile<T,T1>::MFSearch(char* fn1,char* fn2,KeyType a[],int n)
{//����һ����������ļ�������ifs,�����ļ�����ϵ
 ifstream ifs(fn1,ios::in|ios::binary);
 if(!ifs)
  {cerr<<fn1<<' '<<"not open!"<<endl;exit(1);}
 int b1=sizeof(T1);
 T x;
 T1 y;
 int i;
 //���β���ÿ����¼
 for(i=0; i<n; i++) {
   x.key=a[i];
   bool k=IFSearch(fn2,x);
   if(!k)
    {cout<<"���ҹؼ���Ϊ"<<x.key<<"�ļ�¼ʧ��!"<<endl;continue;}
   ifs.seekg(x.next*b1);
   ifs.read((char*) &y, b1);
   cout<<"���ҹؼ���Ϊ"<<x.key<<"�ļ�¼�ɹ�!"<<endl;
   cout<<"�ü�¼����Ϊ:"<<y.key<<' '<<y.rest<<endl;}
 ifs.close();
}
//��һ����¼����������뵽��������A��
template<class T,class T1>
void InFile<T,T1>::SeqInsert(T A[],int mm,T x)
{int i;
 for(i=mm-1;i>=0;i--)
  {//��β����ǰΪѰ�Ҳ���λ�ý���˳��ȽϺ��ƶ�
   if(A[i].key>x.key) A[i+1]=A[i];
   else {A[i+1]=x; break;}}
 if(i<0) A[0]=x;
}
//����fn2ָ������ʾ�����������ļ��в���x������
template<class T,class T1>
void InFile<T,T1>::IFInsert(char *fn2, T x)
{//�����뷽ʽ����fn2ָ������ʾ�����������ļ�
 fstream ifs(fn2,ios::in|ios::binary);
 if(!ifs)
  {cerr<<fn2<<' '<<"not open!"<<endl;exit(1);}
 //�������ʽ��temp�ļ�
 ofstream ofs(".\\temp",ios::out|ios::binary);
 if(!ofs)
  {cerr<<"temp"<<' '<<"not open!"<<endl;exit(1);}
 //��̬����һ������m+1��Ԫ�ص�����A
 T* A=new T[m+1];
 //��ԭ�ļ�ָ��ָ���ļ���ʼλ�ã�������ʡ��
 ifs.seekg(0);
 //ͨ��whileѭ����ɲ������
 int b2=sizeof(T);
 while(1)
  {ifs.read((char*)A, m*b2);
   int s=ifs.gcount()/b2;
   //��������A��ʵ����������������s��
   if(s==m)
    {if(A[m-1].key<x.key) {
      ofs.write((char*)A,m*b2);}
     else {
      SeqInsert(A, m, x);//��x��������뵽��������A��
      ofs.write((char*)A,(m+1)*b2);
      while(!ifs.eof())
      { //��ԭ�ļ���ʣ������м�¼д�뵽����ļ���
       ifs.read((char*)A, m*b2);
       s=ifs.gcount()/b2;
       ofs.write((char*)A, s*b2);}
     break;  //�˳�while(1)ѭ��
   }}
   else
     {SeqInsert(A, s, x);
      ofs.write((char*)A, (s+1)*b2);
      break;//���������һ�����ݿ�ʱ�˳�while(1)ѭ��
   }}
   delete [] A;
   ifs.close();
   ofs.close();
   remove(fn2);
   rename("temp",fn2);
}
//����������A��ɾ��һ���ؼ���Ϊx.key��������
template<class T,class T1>
bool InFile<T,T1>::SeqDelete(T A[], int mm, T& x)
{//������A����Ԫ�ؿ�ʼ˳����ҹؼ���Ϊx.key��������
 int i=0;
 while(i<mm && A[i].key<x.key) i++;
 //�������ڴ�ɾ�����������򷵻ؼ�
 if(i==mm || A[i].key!=x.key) return false;
 //��ɾ�����������x����
 x=A[i];
 //ʹi+1��mm-1������Ԫ��ǰ��һ��λ��
 for(int j=i+1; j<mm; j++) A[j-1]=A[j];
 //�������ʾɾ���ɹ�
 return true;
}
//����fn2ָ������ʾ�����������ļ���ɾ��
//�ؼ���Ϊx.key��������,����x���ر�ɾ����������
template<class T,class T1>
bool InFile<T,T1>::IFDelete(char *fn2, T& x)
{//�����뷽ʽ����fn2ָ������ʾ�����������ļ�
 ifstream ifs(fn2, ios::in|ios::binary);
 if(!ifs) {
   cerr<<fn2<<' '<<"not found!"<<endl;exit(1);}
 //�������ʽ��temp�ļ�
 ofstream ofs("temp",ios::out|ios::binary);
 if(!ofs) {
   cerr<<"temp"<<' '<<"not open!"<<endl;exit(1);}
 int b2=sizeof(T);
 //��̬����һ������m��Ԫ�ص�����A
 T* A=new T[m];
 //��d����true��false��ʾɾ���Ƿ�ɹ�
 bool d;
 //ͨ��while���ɾ������
 while(1)
  {ifs.read((char*)A, m*b2);
   int s=ifs.gcount()/b2;
   //��������A��ʵ����������������s��
   if(s==m)
   {if(A[m-1].key<x.key) {
     ofs.write((char*)A, m*b2);}
    else {d=SeqDelete(A, m, x);
     if(d) ofs.write((char*)A,(m-1)*b2);
     else ofs.write((char*)A,m*b2);
  while(!ifs.eof())
   { //��ԭ�ļ���ʣ������м�¼д�뵽����ļ���
    ifs.read((char*)A, m*b2);
    s=ifs.gcount()/b2;
    ofs.write((char*)A, s*b2);}
    break;  //�˳�while(1)ѭ��
   }}
   else
   {d=SeqDelete(A, s, x);
    if(d)
     ofs.write((char*)A, (s-1)*b2);
    else
     ofs.write((char*)A,s*b2);
    break;//���������һ�����ݿ�ʱ�˳�while(1)ѭ��
 }}
 delete [] A;
 ifs.close();
 ofs.close();
 remove(fn2);
 rename("temp", fn2);
 if(d) return true; else return false;
}
//����fn2ָ������ʾ�����������ļ���
//���ҹؼ���Ϊx.key���������x����
template<class T,class T1>
bool InFile<T,T1>::IFSearch(char* fn2, T& x)
{ifstream ifs(fn2,ios::in|ios::binary);
 //�����뷽ʽ����fn2ָ������ʾ�����������ļ�
 if(!ifs)
  {cerr<<fn2<<' '<<"not found!"<<endl;exit(1);}
 ifs.seekg(0,ios::end);
 int b2=sizeof(T);
 int n=ifs.tellg()/b2;
 ifs.seekg(0);
 int low=0, high=n-1;
 while(low<=high)
   { //���������е�Ԫ�ص��±�
    int mid=(low+high)/2;
    //���ļ��ж��������е�Ԫ�ز�����tm
    T tm;
    ifs.seekg(mid*b2);
    ifs.read((char*)&tm,b2);
    //���ҳɹ�����x���ز��ҵ��������������
    if(x.key==tm.key) {x=tm;
     ifs.close();
     return true;}
    //�����ӱ��м�������
    else if(x.key<tm.key)
      high=mid-1;
    //�����ӱ��м�������
    else  low=mid+1;}
    ifs.close();
    return false;}//����ʧ�ܷ��ؼ�

