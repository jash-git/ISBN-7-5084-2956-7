//LHashLM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include "LHashL.cpp"
//ɢ�б������ز����Ĳ���
void main()
{ cout<<"LHashLM.cpp���н��:\n";
  //��������b����ʼ��
  ElemType a[16]={12,18,15,32,6,23,21,48,36,57,
   45,29,25,38,14,9},d;
  //Ԫ�ظ���
  int m=16,b,*p=NULL;
  //�������
  LHList<ElemType> B(m);
  //���ü�������������ļ��Ĳ��롢ɾ���Ͳ���
  while(1) {
    cout<<endl<<"���ܺű�:"<<endl;
    cout<<"1---����ɢ�б�"<<endl;
    cout<<"2---�����ļ�����Ԫ��"<<endl;
    cout<<"3---�����ļ���ɾ��Ԫ��"<<endl;
    cout<<"4---�����ļ��в���Ԫ��"<<endl;
    cout<<"5---������ļ�"<<endl;
    cout<<"6---��������"<<endl;
    char ch;
    cout<<"���������ѡ��(1-5): ";
      cin>>ch;
    switch (ch)
     {case '1':cout<<"����ɢ�б�"<<endl;
               B.CreateHashTable(a,m);break;
      case '2':cout<<"���������Ԫ��d:";
	        cin>>d;B.Insert(d); break;
      case '3':cout<<"�����ɾ��Ԫ��b:";cin>>b;
            if(B.Delete(b)) cout<<"ɾ���ɹ�!\n";
	    else cout<<"ɾ�����ɹ�!\n";break;
      case '4':cout<<"���������Ԫ��b:";cin>>b;
            p=B.Search(b);
	    if(p==NULL) cout<<"���Ҳ��ɹ�!\n";
	    else cout<<"���ҳɹ�!\n";break;
      case '5':B.PrintHashList();break;
      case '6':return;
      default:cout<<"����ѡ�����,������!"<<endl;
}}}

