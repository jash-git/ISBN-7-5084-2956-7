//���Ա��Ӧ��linelist1m.cpp
#include<iostream.h>
#include<iomanip.h>
#include<malloc.h>
#include<string.h>
#include "linelist1.cpp"
void main()
{ cout<<"linelist1m.cpp���н��:\n";
  ElemType e,e1,e2,e3,e4,e5,e6;
  List *La,*Lb,*Lc;
  int k;
  cout<<"���ȵ��ò��뺯��.\n";
  La->init(&La,4);
  strcpy(e1.name,"stu1");
  strcpy(e1.stuno,"100001");
  e1.age=22;
  e1.score=88;
  La->ListInsert(1,e1);
  strcpy(e2.name,"stu2");
  strcpy(e2.stuno,"100002");
  e2.age=21;
  e2.score=79;
  La->ListInsert(2,e2);
  strcpy(e3.name,"stu3");
  strcpy(e3.stuno,"100003");
  e3.age=19;
  e3.score=87;
  La->ListInsert(3,e3);
  La->printlist(0);
  cout<<"��La��:"<<La->ListLength()<<endl;
  cin.get();

  Lb->init(&Lb,4);
  strcpy(e4.name,"zmofun");
  strcpy(e4.stuno,"100001");
  e4.age=20;
  e4.score=94;
  Lb->ListInsert(1,e4);
  strcpy(e5.name,"bobjin");
  strcpy(e5.stuno,"100002");
  e5.age=23;
  e5.score=69;
  Lb->ListInsert(2,e5);
  strcpy(e6.name,"stu1");
  strcpy(e6.stuno,"100001");
  e6.age=22;
  e6.score=88;
  Lb->ListInsert(3,e6);
  Lb->printlist(0);
  cout<<"��Lb��:"<<Lb->ListLength()<<endl;
  cin.get();

  cout<<"��La��Lb�ϲ�Ϊ��Lc:\n";
  Lc->init(&Lc,6);
  Lc->MergeList(La,Lb);
  Lc->printlist(0);
  cout<<"��Lc��:"<<Lc->ListLength()<<endl;
  cin.get();

  cout<<"��La��Lb����Ϊ��La:\n";
  La->UnionList(La,Lb);
  La->printlist(0);
  cout<<"��La��:"<<La->ListLength()<<endl;
  cin.get();

  k=Lc->ListDelete(-1,e6);
  if(k==0) cout<<"ɾ��ʧ��!\n";
  else cout<<"ɾ���ɹ�!\n";
  cout<<"�����Lc:\n";
  Lc->printlist(0);
  cin.get();
  strcpy(e.name,"NoName");
  La->PriorElem(e2,e);
  if(strcmp(e.name,"NoName")==0) cout<<"e2��ǰ��!\n";
  else cout<<"e2��ǰ��e.name="<<e.name<<endl;
  strcpy(e.name,"NoName");
  La->NextElem(e3,e);
  if(strcmp(e.name,"NoName")==0) cout<<"e3�޺��!\n";
  else cout<<"e3�ĺ��e.name="<<e.name<<endl;
  cin.get();
  cout<<"���ɼ����������Lc\n";
  Lc->printlist(1);cin.get();
  cout<<"���ɼ����������Lc\n";
  Lc->printlist(-1);cin.get();
}
