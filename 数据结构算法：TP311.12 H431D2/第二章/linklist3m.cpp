//linklist3m.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
//#include<stdio.h>
#include"linklist3.cpp"
void ff(int &a)//���ڱ����ĺ���
{cout<<a<<"  ";}
void main()
{cout<<"\nlinklist3m.cpp���н��:\n";
 int init_size,seed,xu;
 cout<<"�����빹�쵥����list1";
 cout<<"\n��ʼ������(1--30):";
 cin>>init_size;
 seed=150;
 cout<<"�Ƿ�����:(=0������,=1����,=-1����):";
 cin>>xu;
 //���쵥����list1���������βι��캯��
 LinkList list1(init_size,seed,xu);
 cout<<"\n������list1����ɹ�!"<<"\n����:";
 list1.TraverseList(ff);
 cout<<"\n��Ϊ����?(1:��;0:����):"<<list1.ListEmpty();
 cout<<"\n����Ϊ:"<<list1.ListSize() ;
 int i;
 cout<<"\n����������õ��ڼ���Ԫ�ص�ֵ(1--"<<init_size<<"):";
 cin>>i;
 cout<<"������list1�е�"<<i<<"��ֵ��"<<list1.GetElem(i);
 int it;
 cout<<"\n����������ɾ���ڼ���Ԫ�ص�ֵ(1--"<<init_size<<"):";
 cin>>i;
 list1.DeleteList(it,i);
 cout<<"\n������list1ɾ����"<<i<<"��Ԫ��"<<"\'"<<it<<"\'"<<"���Ϊ:";
 list1.TraverseList(ff);//�Ե�����list1ÿ�������б���.
 int news,olds;
 cout<<"\n������Ҫ���޸ĵ�Ԫ��:"; cin>>olds;
 cout<<"�������޸ĺ�Ҫ��ɵ�Ԫ��:";cin>>news;
 list1.UpdateList(olds,news);
 cout<<"\n�޸ĺ�����list1��Ϊ:";
 list1.TraverseList(ff);
 cout<<"\n�����빹�쵥����list2";
 cout<<"\n�����뵥����list2��ʼ������(1--30):";
 cin>>init_size;
 seed=120;
 cout<<"��ѡ���Ƿ�����:(=0������,=1����,=-1����):";
 cin>>xu;
 //���쵥����list2���������βι��캯��
 LinkList list2(init_size,seed,xu);
 cout<<"\n������list2Ϊ:";
 list2.TraverseList(ff);
 LinkList list3;//���쵥����list3 ����һ���βι��캯��
 list1.pailie(); //�Ե����������������
 list2.pailie(); //�Ե����������������
 list3.MergeList_L(list1,list2);//����list1��list2
 cout<<"\nlist1��list2����֮��Ϊlist3:\n";
 list3.TraverseList(ff);
 cout<<"\n��ʱ��Ϊ����?(1:��;0:����):"<<list3.ListEmpty();
 cout<<"\n����Ϊ:"<<list3.ListSize() ;
 list3.ClearList();//��յ�����list3
 cout<<"\n��յ�����list3\n";
 cout<<"\n���س�������...";
 cin.get();cin.get();}
