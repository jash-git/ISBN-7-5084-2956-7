//����������������ʹ洢�ṹ��TBSTree.h
template<class T> class TBSTree;
template<class T> class ITBSTree;
template<class T> struct THNode
{public:
  int lflag,rflag;//��־��
  THNode<T> *left;//��һ�����ӽ��ָ����
  THNode<T> *right;//��һ���ֵܽ��ָ����
  T data;//������
  friend class TBSTree<T>;//������������Ϊ��Ԫ
  friend class ITBSTree<T>;
//���캯��
  THNode():left(NULL),right(NULL),lflag(0),rflag(0){ }
  THNode(int la,int ra,T value,THNode<T> *fc=NULL,
   THNode<T> *ns=NULL):data(value),left(fc),
    right(ns){lflag=la;rflag=ra;}
//����ָ����ĳ�Ա����
  THNode<T>* &FirstChild()
   {return left;}
  THNode<T>* &NextSibling()
   {return right;}
};
//������������
template<class T> class TBSTree
{protected:
  THNode<T> *root;//�����ָ��
  THNode<T> *curr;//��ǰ���ָ��
  int nextC;
  int priorC;
 public:
  //���캯������������
  TBSTree(){root=curr=NULL;}
  TBSTree(THNode<T> *&tree)
  {root=tree;
   curr=root;
   if(tree==NULL)
    {nextC=1;priorC=1;}
   else {nextC=0;priorC=0;}
  }
  //���麯��
  virtual THNode<T> *First()=0;
  virtual void Next()=0;
  virtual void Last()=0;
  virtual void Prior()=0;
  int EndOfNext()
   {return nextC;}
  int EndOfPrior()
   {return priorC;}
  //���ݼ������޸ĳ�Ա����
  T &Data();
};
//�������������ʵ��
template<class T>
T &TBSTree<T>::Data()
{if(root==NULL)
 {cout<<"��������!\n";exit(1);}
 return curr->data;
}
//�ɽ�㹹������������������һ�㺯��
template<class T>
THNode<T> *GetTreeNode(T item,THNode<T> *le=NULL,
   THNode<T> *ri=NULL,int lf=0,int rf=0)
{THNode<T> *p=new THNode<T>;
 p->data=item;p->left=le;p->right=ri;
 p->lflag=lf;p->rflag=rf;
 if(p==NULL)
  {cerr<<"�ڴ����ʧ��!\n";exit(1);}
 return p;
}
//�����ض�����������������һ�㺯��
template<class T>
THNode<T> *MakeCharT(THNode<T> *&root,int num)
{THNode<T> *b,*c,*d,*e,*f,*g,*null=NULL;
 if(num==1)
  root=GetTreeNode('X',null);
 if(num==2)
 {e=GetTreeNode('R');
  f=GetTreeNode('W');
  d=GetTreeNode('P',e,f);
  g=GetTreeNode('Q');
  b=GetTreeNode('N',d,g);
  c=GetTreeNode('O');
  root=GetTreeNode('M',b,c);
 }
 if(num==3)
 {g=GetTreeNode('G');
  d=GetTreeNode('D',null,g);
  b=GetTreeNode('B',d);
  e=GetTreeNode('E');
  f=GetTreeNode('F');
  c=GetTreeNode('C',e,f);
  root=GetTreeNode('A',b,c);
 }
 return root;
}


