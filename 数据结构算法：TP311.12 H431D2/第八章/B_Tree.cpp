//B-���Ĳ���B_Tree.cpp
#include<iostream.h>
#include<iomanip.h>
typedef int KeyType;
typedef int RecType;
#define K 20//������
#define m 5//����B-���Ľ���
//B-���Ľ�����Ͷ���
typedef struct BTnode
{ int keynum;  //����йؼ��ָ���
  struct BTnode *parent;//ָ��˫�׽���ָ��
  KeyType key[m+1];//��ؼ�������,key[0]δ��
  struct BTnode *ptr[m+1];//����ָ������
  RecType *recptr[m+1];//��¼ָ������,recptr[0]δ��
}BTreeNode;
typedef BTreeNode *BTree;//�Զ���ָ��BTreeNode��ָ������
 BTree t=new BTreeNode[K];//������ڴ�
//B-���Ĳ����㷨
int BTSearch(BTree T,KeyType k,BTree *p);
//���ؼ���k���뵽B-��T��,����������
BTree Insert(BTree T,KeyType k);
//���*p�а���m���ؼ���,���з��ѳ�һ���½��,�������½��ָ��
BTree split(BTree p);
//��B-��T��ɾ���ؼ��ֵĲ���,���(2)
int MoveKey(BTree p);
//��B-��T��ɾ���ؼ��ֵĲ���,���(3)
BTree merge(BTree p);
//��B-��T��ɾ���ؼ���k,����������.
BTree Delete(BTree T,KeyType k);
//B-���Ĳ����㷨
int BTSearch(BTree T,KeyType k,BTree *p)
{BTree q;
 int i;
 *p=q=T;
 while(q!=NULL)
 {*p=q;
  q->key[0]=k;   //�����ڱ�
  for(i=q->keynum;k<q->key[i];i--)//��*q�в���k
   if(i>0&&q->key[i]==k) return i;//���ҳɹ�,����i��p
  q=q->ptr[i+1];//��q�ĵ�i��������������
 }
 return 0;
}
//���ؼ���k���뵽B-��T��,����������
BTree Insert(BTree T,KeyType k){
 BTree p,s1=NULL,s2=NULL;
 int i;
 if(BTSearch(T,k,&p))       //����������k,���ҵ�
     return T;               //ֱ�ӷ���,�����в���
 while(p!=NULL){
   p->key[0]=k;            //�����ڱ�
   for(i=p->keynum;k<p->key[i];i--)
    {p->key[i+1]=p->key[i];
     p->ptr[i+1]=p->ptr[i];}
   p->key[i]=k;     //����ؼ���k
   cout<<setw(4)<<p->key[i];
   p->ptr[i-1]=s1;  //�ùؼ���k����ߺ���ָ��
   p->ptr[i]=s2;    //�ùؼ���k���ұߺ���ָ��
   if(++(p->keynum)<m)
     break;//�������ؼ������С��m,����ɲ���
   else {
    s2=split(p);//����*p,�����ѵ��½����Ϊ�ұߺ���
    s1=p;       //�����Ѻ��*p��Ϊ��ߺ���
    k=p->key[p->keynum+1];//ȡ��Ҫ���뵽�����Ĺؼ���
    p=p->parent;
   }
  }
  if(p==NULL) //��Ҫ�����µĸ����
  {p=++t;     //�����½��
   p->keynum=1;p->key[1]=k;
   p->ptr[0]=s1;p->ptr[1]=s2;
   return p;}
  else return T;
}
//��B-��T��ɾ���ؼ��ֵĲ���,���(2)
int MoveKey(BTree p)
{BTree b,f=p->parent;     //fָ��*p�ĸ����
 int i,j;
 for(i=0;f->ptr[i]!=p;i++); //��*f���ҳ�ָ��*p��ָ��λ��
 if(i>0)                    //��*p�������ֵ�
  {b=f->ptr[i-1];           //bָ��*p�������ֵ�
   if(b->keynum>(m-1)/2)    //�����ֵ��ж���Ĺؼ���
    {for(j=p->keynum;j>=0;j--)//��*P�еĹؼ��ֺ�ָ�����
   {p->key[j+1]=p->key[j];p->ptr[j+1]=p->ptr[j];}
     p->key[1]=f->key[i];   //��*f�йؼ������Ƶ�*p��
     f->key[i]=b->key[b->keynum];//��*b�е����ؼ������Ƶ�*f��
     p->ptr[0]=b->ptr[b->keynum];//��*b�е����ұ������Ƶ�*f�������
     p->keynum++;b->keynum--;    //�޸�*p��*b�еĹؼ�����Ŀ
     return 1;                  //��ɹؼ����ƶ�,����
    }
    if(i<f->keynum)             //��*p�������ֵ�
    {b=f->ptr[i+1];             //bָ��*p�������ֵ�
     if(b->keynum>(m-1)/2)       //�����ֵ��ж���Ĺؼ���
      {p->key[p->keynum]=f->key[i+1];//��*f�еĹؼ������Ƶ�*p��
       f->key[i+1]=b->key[1];     //��*b�е���С�ؼ������Ƶ�*f��
       p->ptr[p->keynum]=b->ptr[0];//��*b�е�����������Ƶ�*f�����ұ�
       for(j=0;j<b->keynum;j++) //��*b�еĹؼ��ֺ�ָ��ǰ��
	   {b->key[j]=b->key[j+1];b->ptr[j]=b->ptr[j+1];}
       p->keynum++;b->keynum--; //�޸�*p��*b�еĹؼ�����Ŀ
       return 1;               //��ɹؼ����ƶ�,����
      }
   }}
  return 0;
}
//���*p�а���m���ؼ���,���з��ѳ�һ���½��,�������½��ָ��
BTree split(BTree p)
{int i,mid,j;
 BTree New=++t;
 mid=(m+1)/2;
 New->ptr[0]=p->ptr[mid];
 j=1;
 for(i=mid+1;i<=m;i++)
  {New->key[j]=p->key[i];
   New->ptr[j++]=p->ptr[i];
  }
 New->keynum=m-mid;
 p->keynum=mid-1;
 return(New);
}
//��B-��T��ɾ���ؼ��ֵĲ���,���(3)
BTree merge(BTree p)
{BTree b,f=p->parent;      //fָ��*p�ĸ����
 int i,j;
 for(i=0;f->ptr[i]!=p;i++) ;//��*f���ҳ�ָ��*p��ָ��λ��
 if(i>0)                     //��*p�������ֵ�
  b=f->ptr[i-1];             //bָ��*p�������ֵ�
 else {
  b=p;
  p=f->ptr[i+1];
 }           //pָ��*p�������ֵ�
 b->key[++b->keynum]=f->key[i];//��*f�е�i���ؼ��ֺϲ���*b��
 b->ptr[p->keynum]=p->ptr[0]; //��*p�е�����������Ƶ�*b�����ұ�
 for(j=1;j<=b->keynum;j++)    //��*p�еĹؼ��ֺ�ָ���Ƶ�*b��
 {b->key[++b->keynum]=p->key[j];
  b->ptr[b->keynum]=p->ptr[j];
 }
 delete p;
 for(j=i+1;j<=f->keynum;j++)//��*f�е�i��֮��Ĺؼ��ֺ�ָ��ǰ��
 {f->key[j-1]=f->key[j];
  f->ptr[j-1]=f->ptr[j];
 }
 f->keynum--;
 return b;
}
//��B-��T��ɾ���ؼ���k,����������.
BTree Delete(BTree T,KeyType k)
{BTree p,s;
 int i,j;
 i=BTSearch(T,k,&p);//����������k
 if(i==0) return T;
 if(p->ptr[i-1])   //��p����Ҷ���ʱ
 {s=p->ptr[i-1];   //ȡ�ؼ���k����������
  while(s->ptr[s->keynum])//���������Ұ������ؼ��ֵĽ��
   s=s->ptr[s->keynum];
  p->key[i]=s->key[s->keynum];//�����������ؼ���ȡ��k
  p=s;i=s->keynum;
 }
 for(j=i+1;j<=p->keynum;j++)//��*pɾ����i���ؼ���
   p->key[j-1]=p->key[j];
 p->keynum--;
 while(p->keynum<(m-1)/2&&p->parent)//��*p�Ĺؼ�����Ŀ����
 {if(!MoveKey(p)) //����(2)���������,�����ɹ�
   p=merge(p);    //�ϲ����
  p=p->parent;    //��鸸���
 }
 if(p==T&&T->keynum==0)//����������޹ؼ���
 {T=T->ptr[0];//��������һ��
 delete p;}   //�ͷ�ԭ�������
 return T;}
//B-������ز����Ĳ���
void main()
{cout<<"B_Tree.cpp���н��:\n";
 KeyType N=12;
 t->keynum=1;t->parent=NULL;
 t->key[0]=t->key[1]=0;
 t->ptr[0]=t->ptr[1]=NULL;
 t->recptr[0]=t->recptr[1]=NULL;
 cout<<"����ؼ���:\n";
 for(int i=1;i<=N;i++)
  Insert(t,2*i);
 cout<<endl;
 for(i=2;i<=N;i+=2)
  if(Delete(t,i)) cout<<"�ؼ���"<<i<<"ɾ���ɹ�!\n";
  else cout<<"�ؼ���"<<i<<"ɾ�����ɹ�!\n";
 cin.get();}

