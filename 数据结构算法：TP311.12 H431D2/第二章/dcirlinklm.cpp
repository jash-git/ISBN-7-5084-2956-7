//双向循环链表的测试与应用dcirlinklm.cpp
#include<iomanip.h>
#include "dcirlinkl.cpp"
void main()
{cout<<"dcirlinklm.cpp运行结果:\n";
 int m=150,i,n=10,x,it;
 DuLinkList p,t,q,mylink;
 p.CreateCLinkL(n,m,1);
 if(p.CListEmpty()) cout<<"双向循环链表p空!\n";
 else cout<<"双向循环链表p非空!\n";
 cout<<"双向循环链表p(升序):\n";
 p.TraverseCList();
 if(p.CListEmpty()) cout<<"双向循环链表p空!\n";
 else cout<<"双向循环链表p非空!\n";
 if(p.EndCList()) cout<<"双向循环链表p满!\n";
 else cout<<"双向循环链表p非满!\n";
 cout<<"双向循环链表t(无序):\n";
 t.CreateCLinkL(n-2,m);
 t.TraverseCList();
 cout<<"双向循环链表t的长度:"<<t.CListSize()<<endl;
 cout<<"双向循环链表q(降序):\n";
 q.CreateCLinkL(n,m,-1);
 q.TraverseCList();
 cout<<"双向循环链表q的长度:"<<q.CListSize()<<endl;
 cout<<"链表q的第1个元素:"<<q.GetElem(1)<<endl;
 cout<<"链表q的第1个元素地址:"<<q.Index(1)<<endl;
 cout<<"链表q的第5个元素:"<<q.GetElem(5)<<endl;
 cout<<"链表q的第5个元素地址:"<<q.Index(5)<<endl;
 cout<<"链表q的第10个元素:"<<q.GetElem(10)<<endl;
 cout<<"链表q的第10个元素地址:"<<q.Index(10)<<endl;
 cout<<"链表q的curr->next所指元素地址:"<<q.Next()<<endl;
 x=65;it=66;
 if(q.FindCList(x)) cout<<x<<"查找成功!\n";
 else cout<<x<<"查找不成功!\n";
 if(q.UpdateCList(x,it)) cout<<x<<"更新成功!\n";
 else cout<<x<<"更新不成功!\n";
 cout<<"更新后双向循环链表q:\n";
 q.TraverseCList();
 cout<<"插入后双向循环链表q:\n";
 it=100;q.InsertCLfront(it,1);
 q.TraverseCList();
 cout<<"插入后双向循环链表q:\n";
 it=101;q.InsertCLfront(it,5);
 q.TraverseCList();
 cout<<"插入后双向循环链表q:\n";
 it=102;q.InsertCLfront(it,13);
 q.TraverseCList();
 cout<<"插入后q表长:"<<q.CListSize()<<endl;
 cout<<"第1个数:"<<q.DeleteCList(1)<<"删除成功!\n";
 cout<<"删除后q表长:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"第5个数:"<<q.DeleteCList(5)<<"删除成功!\n";
 cout<<"删除后q表长:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"第11个数:"<<q.DeleteCList(11)<<"删除成功!\n";
 cout<<"删除后q表长:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"删除的数为:"<<q.DeleteNt()<<endl;
 cout<<"删除后q表长:"<<q.CListSize()<<endl;
 q.TraverseCList();
 cout<<"求解约瑟夫(Josephus)问题\n";
 cout<<"输入人数n:";cin>>n;
 cout<<"输入第次数m:";cin>>m;
 for(i=0;i<n;i++) mylink.InsertCLafter(i+1,i);
 cout<<"员工编号依次为:";
 DuLNode *w=mylink.Reset();
 while(!mylink.EndOCList())
  {cout<<setw(3)<<w->data;
   w=mylink.Next();}
 cout<<endl;
 cout<<"删除次序依次为:\n";
 mylink.Reset(-1);
 for(i=0;i<n-1;i++)
 {for(int j=0;j<m-1;j++)
  {w=mylink.Next();
   if(mylink.EndOCList()) w=mylink.Next();}
  if(mylink.EndCList()) w=mylink.Next();
  cout<<"删除第"<<mylink.DeleteNt()<<"人\n";}
 cout<<"最后剩下的是:第"<<mylink.GetElem(1)<<"个人\n";
 cin.get();cin.get();}

