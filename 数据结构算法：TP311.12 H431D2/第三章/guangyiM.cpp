//��������ز����Ĳ���guangyiM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>
#include "guangyi.h"
#include "guangyi.cpp"
static GList *GL,*GL1,*GL2,*GL3;
static GList GU,GU1,GU2,GU3,GU4;
void main()
{cout<<"guangyiM.cpp���н��:\n";
 char *a="(A,(B),(3,5,7),(a,b),((C)),D)";
 char *b="(A,(B),(3,5),(a,b),7)";
 char *c="(9,(B),(3,5),(a,b))";
 GU3.utype=INTGR;GU3.intinfo=9;
 GU3.first=GL2;
 GL=GU.CreateGList(a);
 cout<<"���ص�ָ��ֵGL="<<GL<<endl;
 cout<<"������Ĺ����=";
 GU.prtGlist(GL);
 cout<<"\n�����GL�����="<<GU.depth(GL);
 GL=GU.delvalue(GL,5);
 cout<<"\nɾ��5��Ĺ����GL=";GU.prtGlist(GL);
 GL=GU.delvalue(GL,'a');
 cout<<"\nɾ��a��Ĺ����GL=";GU.prtGlist(GL);
 cout<<"\n��GU3����Ϊ��lsָʾ�Ĺ�����β:";
 GU.setTail(GL,GU3);GU.prtGlist(GL);
 cout<<"\n���ù�����ͷԪ�غ�Ĺ����:";
 GU.setHead(GL,GU3);GU.prtGlist(GL);
 GL1=GU.Copy(GL);
 cout<<"\n���ƺ�Ĺ����GL1=";
 GU.prtGlist(GL1);
 cout<<"\n�����GU�ĵ�һ��Ԫ�ص�ֵ:\n";
 GU2=GU.Head(GL1);
 cout<<"GU2.utype="<<GU2.utype;
 if(GU2.utype==INTGR)
  cout<<",GU2.intinfo="<<GU2.intinfo<<endl;
 if(GU2.utype==CH)
  cout<<",GU2.charinfo="<<GU2.charinfo<<endl;
 GU=GU.Info(GL1);
 cout<<"�����GU�ĵ�һ��Ԫ�ص�ֵ:\n";
 cout<<"GU.utype="<<GU.utype;
 if(GL1->utype==INTGR)
  cout<<",GU.intinfo="<<GU.intinfo<<endl;
 if(GL1->utype==CH)
  cout<<",GU.charinfo="<<GU.charinfo<<endl;
 GL2=GU1.CreateGList(b);
 if(GU.operator ==(GU1)) cout<<"�����GU��GU1���!\n";
 else cout<<"�����GU��GU1����!\n";
 cout<<"�޸Ĺ����GU1�ı�ͷ��Ĺ����:";
 GL2=GU1.InsertGL(GL2,GU3);
 GU1.prtGlist(GL2);
 GU1=*GL2;
 cout<<"\n�����GU1����һ��Ԫ����������Ԫ����ɵı�:";
 GL2=GU1.Tail();cout<<'(';
 GU1.prtGlist(GL2);cout<<endl;
 GL3=GU4.CreateGList(c);
 cout<<"������Ĺ����=";
 GU4.prtGlist(GL3);
 cout<<"\n��GU3Ϊͷ,��GL3ָʾ�Ĺ����Ϊβ���±�:";
 GU3.utype=CH;GU3.charinfo='F';
 GU3.first=NULL;
 GL3=GU4.Addon(GL3,GU3);cout<<'(';
 GU4.prtGlist(GL3);cout<<')';
 getch();
}








 