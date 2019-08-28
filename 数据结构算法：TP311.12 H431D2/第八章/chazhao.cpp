//˳���Ĳ���chazhao.cpp
#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdlib.h>
#include<time.h>
//���͵Ĺؼ�������˵����
typedef int KeyType;//����
//����ֵ�͹ؼ���
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))

//���Ա���˳��洢�ṹ�µ�˳�����
typedef  struct
{int key;
 float info;
}STable;
//˳����ҵ��㷨��
int Search_seq(STable ST[ ],int n,int key)
{int i=n;
 ST[0].key=key;
 while(ST[i].key!=key) i--;//�ӱ�β��ǰ��
 return i;
}
//���Ա�����ʽ�洢�ṹ�µ�˳�����
struct node
{int data;
 struct node *next;
};
int searlb(struct node *h,int x)
{struct node *m;
 m=h;
 while(m->next!=NULL&&m->data!=x) m=m->next;
 return(m->data);
}
//��̬���ұ��˳��洢�ṹ�µ�˳�����
typedef struct{
  KeyType key;//ѧ��
  int maths;//��ѧ�ɼ�
  int english;//Ӣ��ɼ�
}ElemType;
typedef struct {
  ElemType *elem;
  int length;//ѧ������
}SSTable;
int Search_Seq(SSTable ST,KeyType key)
{int i;
 ST.elem[0].key=key;
 for(i=ST.length;!EQ(ST.elem[i].key,key);--i);
 return i;
}
//��̬���ұ��˳��洢�ṹ�µ��۰����
int Search_Bin(SSTable ST,KeyType key)
{int low,mid,high;
 low=0;high=ST.length;
 while(low<=high){
   mid=(low+high)/2;
   if EQ(key,ST.elem[mid].key) return mid;
   else if LT(key,ST.elem[mid].key) high=mid -1;
   else  low=mid +1;}
 return 0;
}
void getdata(SSTable * t)
{char *fp=".\\stu.dat";
 int i=0;
 fstream ff(fp,ios::in|ios::trunc);
 ff.read((char *)&(t->length),4);
 while(i<t->length)
   {ff.read((char *)&(t->elem[i].key),4);
    ff.read((char *)&(t->elem[i].maths),4);
    ff.read((char *)&(t->elem[i].english),4);
    i++;
   }
 ff.close();
}
void main()
{cout<<"chazhao.cpp���н��:\n";
  ElemType stu[50];
  SSTable  clas;
  clas.length=10;
  char *fp=".\\stu.dat";
  srand(time(0));
  fstream fa(fp,ios::out|ios::trunc);
  fa.write((char *)&(clas.length),4);
  for(int i=0;i<10;i++)
   {stu[i].key=1000+i;
    stu[i].maths=rand()%100;
    stu[i].english=rand()%100;
    fa.write((char *)&(stu[i]),12);}
  fa.close();
  int j,k;
  clas.elem=stu;
  getdata(&clas);
  cout<<"�ð�ѧ����:"<<clas.length;
  cout<<"\n����Ҫ���ҵ�ѧ��:";cin>>k;
  i=Search_Seq(clas,k);
  j=Search_Bin(clas,k);
  cout<<"\nѧ�� ��ѧ  Ӣ��\n";
  cout<<clas.elem[i].key<<setw(4)
      <<clas.elem[i].maths<<setw(6)<<clas.elem[i].english<<endl;
  cout<<clas.elem[j].key<<setw(4)
      <<clas.elem[j].maths<<setw(6)<<clas.elem[j].english<<endl;
  cout<<"ѧ��   �ܷ�\n";
  for(i=0;i<10;i++)
    {j=stu[i].maths+stu[i].english;
     cout<<1000+i<<setw(6)<<j<<endl;}
  cin.get();cin.get();}
