//ɢ���ļ��Ĳ��롢ɾ���Ͳ��Ҳ���
//HashFM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
//mΪɢ�б�ĳ���,ȷ��ȡֵΪ16
  const int m=16;  
//kmΪɢ�����ļ���ÿ�����������Ԫ�ظ�����
//ȡֵ���ڵ���1,��ȡΪ3
  const int km=3;  
//����ؼ�������Ϊ����
  typedef int KeyType;
//�������ļ��еļ�¼Ԫ������
struct ElemType {
 int key;    //�ؼ�����
 char rest[10];//������,�����ַ������ʾ
};
//�������ļ��еĽ������
struct FLNode {
  ElemType data[km];//ֵ��
  int next; //ָ����һ������ָ����
};
//b1Ϊ�������ļ��еļ�¼����
  const int b1=sizeof(int);
//b2Ϊ�������ļ��еļ�¼����
  const int b2=sizeof(FLNode); 
//NullTag��Ϊ�չؼ��ֵı��,�ٶ���-10��ʾ
  const int NullTag=-10;
//ɢ���ļ����ඨ��
template<class T>
class HFile
{public:
  //���캯��,��ʼ��ɢ�б��ļ������ļ�
  HFile(char* fn1,char* fn2);
  //��Ԫ��x���뵽��Ͱɢ�е��ļ���
  void THFInsertA(char* fn1,char* fn2,T x);
  //������x��n��Ԫ�ز��뵽��Ͱɢ�е��ļ���
  void THFInsertB(char* fn1,char* fn2,T x[],int n);
  //�Ӱ�Ͱɢ�е��ļ���ɾ���ؼ���Ϊx.key��Ԫ��,
  //����x���ظ�Ԫ��,��ɾ���ɹ��򷵻�1,���򷵻�0
  bool THFDelete(char* fn1, char* fn2, T& x);
  //�Ӱ�Ͱɢ�е��ļ��в��ҹؼ���Ϊx.key��Ԫ��,
  //����x���ظ�Ԫ��,�����ҳɹ��򷵻�1,���򷵻�0
  bool THFSearch(char* fn1,char* fn2,T& x);
  //��������˳���ӡ����Ͱɢ�����ļ���ÿ����������Ԫ��ֵ
  void THFPrint(char* fn1,char* fn2);
};
//ɢ���ļ�����ʵ��
//��ʼ��ɢ�б��ļ������ļ�
template<class T>
HFile<T>::HFile(char* fn1,char* fn2)
{//�������ʽ�򿪲������յ�ɢ�б��ļ�
 ofstream f1(fn1, ios::out|ios::binary);
 if(!f1) {
   cerr<<fn1<<' '<<"���ܴ�!"<<endl;
   exit(1);}
//�������ʽ�򿪲������յ�ɢ�����ļ�
 ofstream f2(fn2, ios::out|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"���ܴ�!"<<endl;
	  exit(1);}
//��̬�������m+1�����ʹ洢�ռ������A
 int* A=new int[m+1];
 if(!A){cerr<<"������ڴ�ʧ��!"<<endl;
       	exit(1);}
//������A�е�ÿ��Ԫ�ظ���ֵ-1����ʾ��ָ��
 for(int i=0; i<m+1; i++)
   A[i]=-1;
//��ʼ��ɢ�б��ļ�
  f1.write((char*)A, (m+1)*b1);
 //ɾ������A���ر��ļ�
  delete [] A;
  f1.close();
  f2.close();
}
//��Ԫ��x���뵽��Ͱɢ�е��ļ���
template<class T>
void HFile<T>::THFInsertA(char* fn1, char* fn2, T x)
{//����������Ͳ��½���ʽ��ɢ�б��ļ�
 fstream f1(fn1,ios::in|ios::out|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"���ܴ�!"<<endl;
      exit(1);}
 //����������Ͳ��½���ʽ��ɢ�����ļ�
 fstream f2(fn2, ios::in|ios::out|ios::binary);
 if(!f2){cerr<<fn2<<' '<<"���ܴ�!"<<endl;
         exit(1);}
 //������A�е�ÿ��Ԫ�ظ���ֵ-1����ʾ��ָ��
 int* A=new int[m+1];
 if(!A) {cerr<<"������ڴ�ʧ��!"<<endl;
	 exit(1);}
 //��ɢ�б��ļ��е�����ȫ�����뵽����A��
 f1.read((char*)A, (m+1)*b1);
 //�Թؼ���x.key����x��ɢ�е�ַ
 int d=x.key%m;
 //��x���뵽d������ı�ͷ�����
 int j;
 FLNode temp;
 if(A[d]!=-1)
  {f2.seekg(A[d]*b2);
   f2.read((char*)&temp, b2);
   for(j=0; j<km; j++)
    if(temp.data[j].key==NullTag) break;
    if(j<km) {
      temp.data[j]=x;
      f2.seekg(-b2, ios::cur);
      f2.write((char*)&temp, b2);
      goto END;  //�����ͷ����תȥ����������
  }}
  //��d������Ϊ�ջ�ͷ�����û�п���λ��ʱ����ִ��
  //����������d�������ͷ���ڴ���temp
  temp.data[0]=x;
  for(j=1; j<km; j++)
   temp.data[j].key=NullTag;
  temp.next=A[d];
  //��temp����ֵд�뵽f2�ļ�β�������ӵ�d������ı�ͷ
  if(A[m]==-1) {
  //��f2�е��ļ�ָ�������ļ�β
   f2.seekg(0,ios::end);
  //������ļ�β�Ľ��λ�����
   int len=f2.tellg()/b2;
  //��temp����ֵд���ļ�β
   f2.write((char*)&temp,b2);
  //ʹA[d]ָ���²���Ľ��
   A[d]=len;}
  //��temp����ֵд�뵽f2�ļ���һ�����н����
  //�������ӵ�d������ı�ͷ
   else {//pָ����е�����ı�ͷ���
     int p=A[m];
   //ʹ���е�����ı�ͷָ��ָ������һ�����
     f2.seekg(p*b2);
     FLNode pn;
     f2.read((char*)&pn, b2);
     A[m]=pn.next;
   //ʹtemp��ֵд�뵽pλ�õĽ����
     f2.seekg(-b2, ios::cur);
     f2.write((char*)&temp, b2);
   //ʹA[d]ָ���²����p���
     A[d]=p;}
  //������A�е�ȫ������д�ص�ɢ�б��ļ�f1��
   f1.seekg(0);
   f1.write((char*)A, (m+1)*b1);
  //ɾ����̬����A�͹ر������ļ�
   END:
    delete [] A;
    f1.close();
    f2.close();
}
//������x��n��Ԫ�ز��뵽��Ͱɢ�е��ļ���
template<class T>
void HFile<T>::THFInsertB(char* fn1,char* fn2,T x[],int n)
{fstream f1(fn1, ios::in|ios::out|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"���ܴ�!"<<endl;
	  exit(1);}
 fstream f2(fn2, ios::in|ios::out|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"���ܴ�!"<<endl;
          exit(1);}
 int* A=new int[m+1];
 if(!A) {cerr<<"������ڴ�ʧ��!"<<endl;
	 exit(1);}
 f1.read((char*)A, (m+1)*b1);
 for(int i=0; i<n; i++)
  {int d=x[i].key%m;
   int j;
   FLNode temp;
   if(A[d]!=-1)
    {f2.seekg(A[d]*b2);
     f2.read((char*)&temp, b2);
     for(j=0; j<km; j++)
      if(temp.data[j].key==NullTag) break;
      if(j<km) {
       temp.data[j]=x[i];
       f2.seekg(-b2, ios::cur);
       f2.write((char*)&temp, b2);
       continue;}}
      temp.data[0]=x[i];
      for(j=1;j<km;j++)
	temp.data[j].key=NullTag;
      temp.next=A[d];
      if(A[m]==-1) {
       f2.seekg(0,ios::end);
       int len=f2.tellg()/b2;
       f2.write((char*)&temp,b2);
       A[d]=len;}
      else {int p=A[m];
	f2.seekg(p*b2);
	FLNode pn;
	f2.read((char*)&pn, b2);
	A[m]=pn.next;
	f2.seekg(-b2, ios::cur);
	f2.write((char*)&temp, b2);
	A[d]=p;}}
    f1.seekg(0);
    f1.write((char*)A, (m+1)*b1);
    delete [] A;
    f1.close();f2.close();
}
//�Ӱ�Ͱɢ�е��ļ���ɾ���ؼ���Ϊx.key��Ԫ��,����x���ظ�
//Ԫ��,��ɾ���ɹ��򷵻�1,���򷵻�0
template<class T>
bool HFile<T>::THFDelete(char* fn1,char* fn2,T& x)
{fstream f1(fn1,ios::in|ios::out|ios::binary);
 int k;
 if(!f1) {cerr<<fn1<<' '<<"���ܴ�!"<<endl;
	  exit(1);}
 fstream f2(fn2,ios::in|ios::out|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"���ܴ�!"<<endl;
	  exit(1);}
 int* A=new int[m+1];
 if(!A) {cerr<<"������ڴ�ʧ��!"<<endl;
	 exit(1);}
 f1.read((char*)A, (m+1)*b1);
 int DeleteTag=0;  //��DeleteTag��Ϊɾ���Ƿ�ɹ��ı��
 int d=x.key%m;
 int p=A[d],i=0;  //��p����d������ı�ͷ����λ����ţ�
 //��i����ý���б�ɾ��Ԫ�ص��±���һ����Ԫ�ص��±�
 FLNode temp;
 //��d������ı�ͷ�����ɾ���ؼ���Ϊx.key��Ԫ��
 if(p!=-1)
  {f2.seekg(p*b2);
   f2.read((char*)&temp, b2);
   while(i<km && temp.data[i].key!=NullTag)
    if(temp.data[i].key==x.key) break;
    else i++;
    if(i<km && temp.data[i].key==x.key) {
     x=temp.data[i]; //��x���ر�ɾ����Ԫ��ֵ
    for(k=i+1; k<km; k++)
     if(temp.data[k].key!=NullTag)
       temp.data[k-1]=temp.data[k];
     else break;
   temp.data[k-1].key=NullTag;
   if(k-1==0) { //ɾ��d�������б�ͷ�ս��
    A[d]=temp.next;
    temp.next=A[m];
    A[m]=p;}
    f2.seekg(-b2, ios::cur);
    f2.write((char*)&temp, b2);
    DeleteTag=1;//����ֵ1��ʾɾ���ɹ�
    goto END;  //תȥ����������
  }}
 //��d������Ϊ��,��תȥ����������
  else goto END;
  //��d������ĵڶ��������˳����ұ�ɾ����Ԫ��
  int j,q;
  q=temp.next;  //q��ʼָ��ڶ������
  FLNode tq;//��tq����ɢ�����ļ���λ��Ϊq�Ľ��
  while(q!=-1)
    {f2.seekg(q*b2);
     f2.read((char*)&tq, b2);
     for(j=0; j<km; j++)
       if(tq.data[j].key==x.key) {
	 x=tq.data[j];break;}
     if(j<km) break;
     q=tq.next;}
 //���ҵ��˱�ɾ����Ԫ��,�򽫵�һ������е����һ��Ԫ��
 //�ƶ�����ɾ��Ԫ�ص�λ��
  if(q!=-1) {tq.data[j]=temp.data[i-1];
    temp.data[i-1].key=NullTag;
    f2.seekg(q*b2);
    f2.write((char*)&tq, b2);
    if(i==1) {//�ѿյı�ͷ������ӵ����б�ı�ͷ
     A[d]=temp.next;
     temp.next=A[m];
     A[m]=p;}
     f2.seekg(p*b2);
     f2.write((char*)&temp, b2);
     DeleteTag=1;}  //��ɾ���ɹ���־
  //��ɾ�������Ľ����������
  END:
   if(DeleteTag==1) {
     f1.seekg(0);
     f1.write((char*)A,(m+1)*b1);}
     delete [] A;
     f1.close();
     f2.close();
     if(DeleteTag==1) return true;
     else return false;
}
//�Ӱ�Ͱɢ�е��ļ��в��ҹؼ���Ϊx.key��Ԫ��,
//����x���ظ�Ԫ��,�����ҳɹ��򷵻�1,���򷵻�0
template<class T>
bool HFile<T>::THFSearch(char* fn1,char* fn2,T& x)
{//������Ͳ��½���ʽ��ɢ�б��ļ�
 ifstream f1(fn1, ios::in|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"���ܴ�!"<<endl;
       	exit(1);}
 //������Ͳ��½���ʽ��ɢ�����ļ�
 ifstream f2(fn2, ios::in|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"���ܴ�!"<<endl;
	exit(1);}
  //��������A����f1�ļ�����A��
 int* A=new int[m+1];
 if(!A) {cerr<<"������ڴ�ʧ��!"<<endl;
	exit(1);}
 f1.read((char*)A, (m+1)*b1);
  //����xԪ����ɢ�б��еĵ�ַ
 int i,d=x.key%m;
  //��d��������˳����ҹؼ���Ϊx.key��Ԫ��
 int p=A[d];
  //��d��������˳����ҹؼ���Ϊx.key��Ԫ��
 FLNode temp;
 while(p!=-1)
   {f2.seekg(p*b2);
    f2.read((char*)&temp, b2);
    for(i=0;i<km;i++)
     if(temp.data[i].key==x.key)
      {x=temp.data[i];//�����ҵ���Ԫ����x����
       	break;}
    if(i<km) break;
    else  p=temp.next;}
  //���в��ҽ�������
 delete [] A;
 f1.close();f2.close();
 if(p==-1) return false; else return true;
}
//��������˳���ӡ����Ͱɢ�����ļ���ÿ����������Ԫ��ֵ
template<class T>
void HFile<T>::THFPrint(char* fn1, char* fn2)
{ifstream f1(fn1, ios::in|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"���ܴ�!"<<endl;
   exit(1);}
 ifstream f2(fn2, ios::in|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"���ܴ�!"<<endl;
   exit(1);}
  int* A=new int[m+1];
  if(!A) {cerr<<"������ڴ�ʧ��!"<<endl;
   exit(1);}
  f1.read((char*)A, (m+1)*b1);
  int p;
  FLNode pn;
  for(int i=0; i<m+1; i++)
    {cout<<setw(2)<<i<<':';
     p=A[i];
     while(p!=-1) {
      f2.seekg(p*b2);
      f2.read((char*)&pn, b2);
      //�������λ�����
      cout<<setw(2)<<p<<"->";
      //��������ÿ��Ԫ�صĹؼ��֣��Դ˴������ֵ
      for(int j=0; j<km; j++)
        cout<<pn.data[j].key<<"  ";
      //ʹpָ����һ�����
	p=pn.next;}
     cout<<endl;}
}
//ɢ���ļ�����ʵ�ֵĲ���
void main()
{ cout<<"HashFM.cpp���н��:\n";
  //���屣���¼������a����ʼ��
  ElemType a[15]={{13,"li"},{18,"liu"},{17,"wphp"},{37,"menrm"},
  {8,"ytong"},{22,"zhua"},{24,"push"},{48,"qian"},{34,"tang"},
  {57,"shdm"},{55,"kang"},{30,"liuli"},{25,"qiaoh"},
  {31,"dukun"},{17,"haiang"}};
  //���屣���¼������b����ʼ��
  ElemType b[16]={{23,"tang"},{38,"suan"},{56,"kony"},
  {55,"shao"},{80,"caik"},{70,"ganwu"},{65,"dukun"},{42,"sini"},
  {29,"liuda"},{43,"xitu"},{71,"taoto"},{77,"shouw"},
  {93,"shum"},{69,"liyz"},{45,"xuyang"},{19,"wxy"}};
  //����ɢ�б��ļ������ļ������֣������ַ�ָ��p1��p2��ָ��
  char *p1=".\\HFile.idx", *p2=".\\HFile.dat";
  //��ʼ��ɢ�б��ļ������ļ�	
  HFile<ElemType> myfile(p1,p2);
  //��ɢ���ļ���������a��b�б���ļ�¼  
  myfile.THFInsertB(p1,p2,a,15);
  myfile.THFInsertB(p1,p2,b,16);
  //��mark���ڱ���ɾ������Һ������ص�ֵ
  int mark;
  //����x����һ���������Ԫ��ֵ�򱣴��ɾ�������Ԫ�صĹؼ���
  ElemType x;
  //���ü����������ɢ���ļ�
  while(1) {
    cout<<endl<<"���ܺű�"<<endl;
    cout<<"1---��ɢ���ļ�����һ��Ԫ��"<<endl;
    cout<<"2---��ɢ���ļ���ɾ��һ��Ԫ��"<<endl;
    cout<<"3---��ɢ���ļ��в���һ��Ԫ��"<<endl;
    cout<<"4---���ɢ�����ļ�"<<endl;
    cout<<"5---��������"<<endl;
    char ch;
    cout<<"���������ѡ��(1-5): ";cin>>ch;
    switch (ch)
     {case '1':
	cout<<"���������Ԫ��x��ֵ(һ��������һ���ַ���):";
	  cin>>x.key>>x.rest;
        myfile.THFInsertA(p1,p2,x);break;
      case '2':
        cout<<"�����ɾ��Ԫ��x�Ĺؼ���:";
          cin>>x.key;
	mark=myfile.THFDelete(p1,p2,x);
        if(mark==1) cout<<"ɾ���ɹ�!"<<x.key<<' '<<x.rest<<endl;
	else cout<<"ɾ��ʧ��!"<<endl;break;
      case '3':cout<<"���������Ԫ��x�Ĺؼ���:";
	        cin>>x.key;
	mark=myfile.THFSearch(p1,p2,x);
        if(mark==1)
	  cout<<"���ҳɹ�!"<<x.key<<' '<<x.rest<<endl;
        else cout<<"����ʧ��!"<<endl;break;
      case '4':myfile.THFPrint(p1,p2);break;
      case '5':return;
      default:cout<<"����ѡ�����,������!"<<endl;
}}}
