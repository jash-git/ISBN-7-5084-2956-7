//B-树的(类方法)操作B_Tree1.cpp
#include<iostream.h>
#include<iomanip.h>
typedef int KeyType;
typedef int RecType;
#define K 20//结点个数
#define m 5//定义B-树的阶树
//B-树的结点类型定义
typedef struct BTreeNode
  {int keynum;  //结点中关键字个数
   struct BTreeNode *parent;//指向双亲结点的指针
   KeyType key[m+1];//组关键字向量
   struct BTreeNode *ptr[m+1];//子树指针向量
   RecType *recptr[m+1];//记录指针向量
}*BTree;
BTree t=new BTreeNode[K];//申请堆内存
//B-树的类定义
class BSTree
{public:
  BTree T;//指向结构体BTreeNode的指针
  //构造函数
  BSTree(BTree t):T(t){}
  //B-树的查找算法
  int BTSearch(KeyType k,BTree *p);
  //将关键码k插入到B-树T中,并返回树根
  BTree Insert(KeyType k);
  //结点*p中包含m个关键字,从中分裂出一个新结点,并返回新结点指针
  BTree split(BTree &p);
  //在B-树T中删除关键字的操作,情况(2)
  int MoveKey(BTree &p);
  //在B-树T中删除关键字的操作,情况(3)
  BTree merge(BTree &p);
  //在B-树T中删除关键字k,并返回树根.
  BTree Delete(KeyType k);
};
//B-树的类实现
//B-树的查找算法
int BSTree::BTSearch(KeyType k,BTree *p)
{BTree q;
 int i;
 *p=q=T;
 while(q!=NULL)
 {*p=q;
  q->key[0]=k;   //设置哨兵
  for(i=q->keynum;k<q->key[i];i--)//在*q中查找k
   if(i>0&&q->key[i]==k) return i;//查找成功,返回i和p
  q=q->ptr[i];//沿q的第i个子树继续搜索
 }
 return 0;
}
//将关键码k插入到B-树T中,并返回树根
BTree BSTree::Insert(KeyType k){
 BTree p,s1=NULL,s2=NULL;
 int i;
 if(BTSearch(k,&p))       //在树中搜索k,若找到
    return T;               //直接返回,不进行插入
 while(p!=NULL){
   p->key[0]=k;            //设置哨兵
   for(i=p->keynum;k<p->key[i];i--)
    {p->key[i+1]=p->key[i];
     p->ptr[i+1]=p->ptr[i];}
   p->key[i]=k;     //插入关键码k
   cout<<setw(3)<<p->key[i];
   p->ptr[i-1]=s1;  //置关键码k的左边孩子指针
   p->ptr[i]=s2;    //置关键码k的右边孩子指针
   if(++(p->keynum)<m)
     break;//若插入后关键码个数小于m,则完成插入
   else {
    s2=split(p);//分裂*p,将分裂的新结点作为右边孩子
    s1=p;       //将分裂后的*p作为左边孩子
    k=p->key[p->keynum+1];//取出要插入到父结点的关键码
    p=p->parent;
   }
  }
  if(p==NULL) //需要产生新的根结点
  {p=++t;     //申请新结点
   p->keynum=1;p->key[1]=k;
   p->ptr[0]=s1;p->ptr[1]=s2;
   return p;}
  else return T;
}
//在B-树T中删除关键字的操作,情况(2)
int BSTree::MoveKey(BTree &p)
{BTree b,f=p->parent;     //f指向*p的父结点
 int i,j;
 for(i=0;f->ptr[i]!=p;i++); //在*f中找出指向*p的指针位置
 if(i>0)                    //若*p有左邻兄弟
  {b=f->ptr[i-1];           //b指向*p的左邻兄弟
   if(b->keynum>(m-1)/2)    //左邻兄弟有多余的关键字
    {for(j=p->keynum;j>=0;j--)//将*P中的关键字和指针后移
   {p->key[j+1]=p->key[j];p->ptr[j+1]=p->ptr[j];}
     p->key[1]=f->key[i];   //将*f中关键字下移到*p中
     f->key[i]=b->key[b->keynum];//将*b中的最大关键字上移到*f中
     p->ptr[0]=b->ptr[b->keynum];//将*b中的最右边子树移到*f的最左边
     p->keynum++;b->keynum--;    //修改*p和*b中的关键字数目
     return 1;                  //完成关键字移动,返回
    }
    if(i<f->keynum)             //若*p有右邻兄弟
    {b=f->ptr[i+1];             //b指向*p的右邻兄弟
     if(b->keynum>(m-1)/2)       //右邻兄弟有多余的关键字
      {p->key[p->keynum]=f->key[i+1];//将*f中的关键字下移到*p中
       f->key[i+1]=b->key[1];     //将*b中的最小关键字上移到*f中
       p->ptr[p->keynum]=b->ptr[0];//将*b中的最左边子树移到*f的最右边
       for(j=0;j<b->keynum;j++) //将*b中的关键字和指针前移
        {b->key[j]=b->key[j+1];b->ptr[j]=b->ptr[j+1];}
       p->keynum++;b->keynum--; //修改*p和*b中的关键字数目
       return 1;               //完成关键字移动,返回
      }
    }}
  return 0;
}
//结点*p中包含m个关键字,从中分裂出一个新结点,并返回新结点指针
BTree BSTree::split(BTree &p)
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
//在B-树T中删除关键字的操作,情况(3)
BTree BSTree::merge(BTree &p)
{BTree b,f=p->parent;      //f指向*p的父结点
 int i,j;
 for(i=0;f->ptr[i]!=p;i++) ;//在*f中找出指向*p的指针位置
 if(i>0)                     //若*p有左邻兄弟
  b=f->ptr[i-1];             //b指向*p的左邻兄弟
 else {
  b=p;
  p=f->ptr[i+1];
 }           //p指向*p的右邻兄弟
 b->key[++b->keynum]=f->key[i];//将*f中第i个关键字合并到*b中
 b->ptr[p->keynum]=p->ptr[0]; //将*p中的最左边子树移到*b的最右边
 for(j=1;j<=b->keynum;j++)    //将*p中的关键字和指针移到*b中
 {b->key[++b->keynum]=p->key[j];
  b->ptr[b->keynum]=p->ptr[j];
 }
 delete p;
 for(j=i+1;j<f->keynum;j++)//将*f中第i个之后的关键字和指针前移
 {f->key[j-1]=f->key[j];
  f->ptr[j-1]=f->ptr[j];
 }
 f->keynum--;
 return b;
}
//在B-树T中删除关键字k,并返回树根.
BTree BSTree::Delete(KeyType k)
{BTree p,s;
 int i,j;
 i=BTSearch(k,&p);    //在树中搜索k
 if(i==0) return T;
 if(i>0&&p->ptr[i-1])   //当p不是叶结点时
 {s=p->ptr[i-1];        //取关键字k的左邻子树
  while(s->ptr[s->keynum])//在子树中找包含最大关键字的结点
   s=s->ptr[s->keynum];
  p->key[i]=s->key[s->keynum];//用子树中最大关键字取代k
  p=s;i=s->keynum;
 }
 for(j=i+1;j<=p->keynum;j++)//从*p删除第i个关键字
  p->key[j-1]=p->key[j];
 p->keynum--;
 while(p->keynum<(m-1)/2&&p->parent)//若*p的关键字数目不够
 {if(!MoveKey(p)) //按第(2)种情况处理,若不成功
   p=merge(p);    //合并结点
  p=p->parent;    //检查父结点
 }
 if(p==T&&T->keynum==0)//若根结点中无关键字
 {T=T->ptr[0];//树根下移一层
  delete p;    //释放原来根结点
 }
 return T;
}
//B-树的类相关操作的测试
void main()
{cout<<"B_Tree1.cpp运行结果:\n";
 KeyType k=12;
 t->keynum=1;t->key[0]=0;
 t->ptr[0]=NULL;t->recptr[0]=NULL;
 BSTree my(t);
 cout<<"插入关键字:\n";
 for(int i=1;i<=k;i++)
   my.Insert(2*i);
 cout<<endl;
 for(i=2;i<=k;i+=2)
	 if(my.Delete(i)) cout<<"关键字"<<i<<"删除成功!\n";
  else cout<<"关键字"<<i<<"删除不成功!\n";
 cin.get();}
