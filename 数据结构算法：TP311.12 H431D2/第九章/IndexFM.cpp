//IndexFM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include "IndexF.cpp"
//�����ļ�����ʵ�ֵĲ���
void main()
{cout<<"IndexFM.cpp���н��:\n";
 //���屣���¼������a����ʼ��
 ElemType a[15]={{13,"li"},{18,"liu"},{17,"wphp"},{37,"menrm"},
  {8,"ytong"},{22,"zhua"},{24,"push"},{48,"qian"},{34,"tang"},
  {57,"shdm"},{55,"kang"},{30,"liuli"},{25,"qiaoh"},
  {31,"dukun"},{17,"haiang"}};
 //���屣���¼�ؼ��ֵ�����b����ʼ��
 KeyType b[16]={12,18,15,32,6,23,21,48,36,57,45,29,25,38,14,9};
 //�������ļ��������ļ������֣������ַ�ָ��p1��p2��ָ��
 char *p1=".\\HFile1.dat",*p2=".\\HFile1.idx";
 int m;//��¼����
 InFile<IndexItem,ElemType> myfile;
 //���ü�������������ļ��������ļ��Ĳ��롢ɾ���Ͳ���
 while(1) {
    cout<<endl<<"���ܺű�:"<<endl;
    cout<<"1---�����ļ��������ɼ�¼"<<endl;
    cout<<"2---�����ļ���ɾ�����ɼ�¼"<<endl;
    cout<<"3---�����ļ��в������ɼ�¼"<<endl;
    cout<<"4---������ļ�fn1"<<endl;
    cout<<"5---��������ļ�fn2"<<endl;
    cout<<"6---��������"<<endl;
    char ch;
    cout<<"���������ѡ��(1-6): ";cin>>ch;
    switch (ch)
     {case '1':cout<<"����������¼����m:";
	   cin>>m;myfile.MFAppend(p1,p2,a,m);break;
      case '2':cout<<"�����ɾ����¼����m:";
        cin>>m;myfile.MFDelete(p1,p2,b,m);break;
      case '3':cout<<"��������Ҽ�¼����m:";
        cin>>m;myfile.MFSearch(p1,p2,b,m);break;
      case '4':myfile.PrintMainFile(p1);break;
      case '5':myfile.PrintIndexFile(p2);break;
      case '6':return;
      default:cout<<"����ѡ�����,������!"<<endl;
}}}

