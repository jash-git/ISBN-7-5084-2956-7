//�ݹ�����(ջ��Ӧ��)Recurve.cpp
#include <iostream.h>
#include <iomanip.h>
class list;
class listnode{
  friend class list;
  int data;
  listnode *link;
  listnode(int value,listnode *zz):data(value),link(zz)
   {}
};
class list{
  listnode *first;
  //�ۼӺ�
  long sum(listnode *p);
  //������
  long count(listnode *p);
public:
  list():first(NULL){}
  //����ջ
  void add(int value);
  //��ʾջ������
  void display();
  //��ȡ�ۼӺ�
  long get_sum(){return sum(first);}
  //��ȡ���ݸ���
  long get_count(){return count(first);}
  //��ƽ��
  float get_avg()
  {return (float)sum(first)/count(first);}
};
void list::add(int value){
  listnode *p=new listnode(value,first);
  if(p!=NULL) first=p;
  else cerr <<"Memory Error!" <<endl;
}
void list::display(){
  cout<<"������ĸ���ֵ:";
  for(listnode *p=first;p!=NULL;p=p->link)
    cout<<setw(2)<<p->data;
  cout <<endl;
}
long list::sum(listnode *p){
  if(p->link==NULL) return p->data;
  else return p->data+sum(p->link);
}
long list::count(listnode *p){
  long n=1;
  if(p->link==NULL){return 1;}
  else{return count(p->link)+n;}
}
void main()
{cout<<"Recurve.cpp���н��:\n";
 list a;
 a.add(1);
 a.add(2);
 a.add(3);
 a.add(4);
 a.display();
 cout<<"�ۼӺ�sum="<<a.get_sum()<<endl;
 cout<<"���ݸ���count="<<a.get_count()<<endl;
 cout<<"ƽ��ֵavg="<<a.get_avg()<<endl;
 cin.get();}

