//˫��ѭ������Ĳ�����Ӧ��dcirlinklm.cpp
#include<iomanip.h>
#include "dcirlinkl.cpp"
void main()
{cout<<"dcirlinklm.cpp���н��:\n";
 int m=150,i,n=10,x,it;
 DuLinkList p,t,q,mylink;
 p.CreateCLinkL(n,m,1);
 if(p.CListEmpty()) cout<<"˫��ѭ������p��!\n";
 else cout<<"˫��ѭ������p�ǿ�!\n";
 cout<<"˫��ѭ������p(����):\n";
 p.TraverseCList();
 if(p.CListEmpty()) cout<<"˫��ѭ������p��!\n";
 else cout<<"˫��ѭ������p�ǿ�!\n";
 if(p.EndCList()) cout<<"˫��ѭ������p��!\n";
 else cout<<"˫��ѭ������p����!\n";
 cout<<"˫��ѭ������t(����):\n";
 t.CreateCLinkL(n-2,m);
 t.TraverseCList();
 cout<<"˫��ѭ������t�ĳ���:"<<t.CListSize()<<endl;
 cout<<"˫��ѭ������q(����):\n";
 q.CreateCLinkL(n,m,-1);
 q.TraverseCList();
 cout<<"˫��ѭ������q�ĳ���:"<<q.CListSize()<<endl;
 cout<<"����q�ĵ�1��Ԫ��:"<<q.GetElem(1)<<endl;
 cout<<"����q�ĵ�1��Ԫ�ص�ַ:"<<q.Index(1)<<endl;
 cout<<"����q�ĵ�5��Ԫ��:"<<q.GetElem(5)<<endl;
 cout<<"����q�ĵ�5��Ԫ�ص�ַ:"<<q.Index(5)<<endl;
 cout<<"����q�ĵ�10��Ԫ��:"<<q.GetElem(10)<<endl;
 cout<<"����q�ĵ�10��Ԫ�ص�ַ:"<<q.Index(10)<<endl;
 cout<<"����q��curr->next��ָԪ�ص�ַ:"<<q.Next()<<endl;
 x=65;it=66;
 if(q.FindCList(x)) cout<<x<<"���ҳɹ�!\n";
 else cout<<x<<"���Ҳ��ɹ�!\n";
 if(q.UpdateCList(x,it)) cout<<x<<"���³ɹ�!\n";
 else cout<<x<<"���²��ɹ�!\n";
 cout<<"���º�˫��ѭ������q:\n";
 q.TraverseCList();
 cout<<"�����˫��ѭ������q:\n";
 it=100;q.InsertCLfront(it,1);
 q.TraverseCList();
 cout<<"�����˫��ѭ������q:\n";
 it=101;q.InsertCLfront(it,5);
 q.TraverseCList();
 cout<<"�����˫��ѭ������q:\n";
 it=102;q.InsertCLfront(it,13);
 q.TraverseCList();
 cout<<"�����q��:"<<q.CListSize()<<endl;
 cout<<"��1����:"<<q.DeleteCList(1)<<"ɾ���ɹ�!\n";
 cout<<"ɾ����q��:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"��5����:"<<q.DeleteCList(5)<<"ɾ���ɹ�!\n";
 cout<<"ɾ����q��:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"��11����:"<<q.DeleteCList(11)<<"ɾ���ɹ�!\n";
 cout<<"ɾ����q��:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"ɾ������Ϊ:"<<q.DeleteNt()<<endl;
 cout<<"ɾ����q��:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"���Լɪ��(Josephus)����\n";
 cout<<"��������n:";cin>>n;
 cout<<"����ڴ���m:";cin>>m;
 for(i=0;i<n;i++) mylink.InsertCLafter(i+1,i);
 cout<<"Ա���������Ϊ:";
 DuLNode *w=mylink.Reset();
 while(!mylink.EndOCList())
  {cout<<setw(3)<<w->data;
   w=mylink.Next();}
 cout<<endl;
 cout<<"ɾ����������Ϊ:\n";
 mylink.Reset(-1);
 for(i=0;i<n-1;i++)
 {for(int j=0;j<m-1;j++)
  {w=mylink.Next();
   if(mylink.EndOCList()) w=mylink.Next();}
  if(mylink.EndCList()) w=mylink.Next();
  cout<<"ɾ����"<<mylink.DeleteNt()<<"��\n";}
 cout<<"���ʣ�µ���:��"<<mylink.GetElem(1)<<"����\n";
 cin.get();cin.get();}

