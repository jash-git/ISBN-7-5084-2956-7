//����������������ʹ洢�ṹ��TBSTree1.h
template<class T> class TBSTree;
template<class T> struct THNode
{public:
  int lflag,rflag;//��־��
  THNode<T> *left;//��һ�����ӽ��ָ����
  THNode<T> *right;//��һ���ֵܽ��ָ����
  T data;//������
  friend class TBSTree<T>;//������������Ϊ��Ԫ
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
{public:
  //�ɽ�㹹������������
  THNode<T> *GetTreeNode(T item,THNode<T> *le=NULL,
    THNode<T> *ri=NULL,int lf=0,int rf=0);
  //�����ض�����������
  THNode<T> *MakeCharT(THNode<T> *&,int);
  //������������ʾ�Ķ�����(���������������ֵ)
  void CreateBiTree(THNode<T> *&tr);
  //����������������
  void InThread1(THNode<T> *&);
  //����������������
  void InThread(THNode<T> *&);
  //����������������
  void InThread2(THNode<T> *&);
  //���������������������
  void ThInorder(THNode<T> *&);
};
template<class T>
THNode<T> *TBSTree<T>::GetTreeNode(T item,THNode<T> *le,
   THNode<T> *ri,int lf,int rf)
{THNode<T> *p=new THNode<T>;
 p->data=item;p->left=le;p->right=ri;
 p->lflag=lf;p->rflag=rf;
 if(p==NULL)
  {cerr<<"�ڴ����ʧ��!\n";exit(1);}
 return p;
}
template<class T>
THNode<T> *TBSTree<T>::MakeCharT(THNode<T> *&root,int num)
{THNode<T> *b,*c,*d,*e,*f,*g,*null=NULL;
 if(num==1)
 {e=GetTreeNode('R');
  f=GetTreeNode('W');
  d=GetTreeNode('P',e,f);
  g=GetTreeNode('Q');
  b=GetTreeNode('N',d,g);
  c=GetTreeNode('O');
  root=GetTreeNode('M',b,c);
 }
 else {
  g=GetTreeNode('G');
  d=GetTreeNode('D',null,g);
  b=GetTreeNode('B',d);
  e=GetTreeNode('E');
  f=GetTreeNode('F');
  c=GetTreeNode('C',e,f);
  root=GetTreeNode('A',b,c);
 }
 return root; 
}
template<class T>
void TBSTree<T>::CreateBiTree(THNode<T> *&tr)
{char ch;
 cin>>ch;
 if(ch=='#') tr=NULL;
 else
 {tr=new THNode<T>;
  tr->lflag=tr->rflag=0;
  if(!tr)
   {cerr<<"�ڴ����ʧ��!\n";exit(1);}
  tr->data=ch;
  CreateBiTree(tr->left);
  CreateBiTree(tr->right);
 }
}
template<class T>
void TBSTree<T>::InThread1(THNode<T> *&root)
{static THNode<T> *pre;
 if(root!=NULL)
 {if(root->left==NULL)
    root->lflag=1;
  if(root->right==NULL)
    root->rflag=1;
  if((pre!=NULL)&&(root->lflag==1))
    root->left=pre;
  if((pre!=NULL)&&(pre->rflag==1))
    pre->right=root;
  pre=root;
  if(root->lflag==0)
    InThread(root->left);
  if(root->rflag==0)
    InThread(root->right);
 }
}
template<class T>
void TBSTree<T>::InThread(THNode<T> *&root)
{static THNode<T> *pre;
 if(root!=NULL)
 {InThread(root->left);
  if(root->left==NULL)
    root->lflag=1;
  if(root->right==NULL)
    root->rflag=1;
  if((pre!=NULL)&&(root->lflag==1))
    root->left=pre;
  if((pre!=NULL)&&(pre->rflag==1))
    pre->right=root;
  pre=root;
  if(root->rflag==0)
    InThread(root->right);
 }
}
template<class T>
void TBSTree<T>::InThread2(THNode<T> *&root)
{static THNode<T> *pre;
 if(root!=NULL)
 {InThread(root->left);
  InThread(root->right);
  if(root->left==NULL)
    root->lflag=1;
  if(root->right==NULL)
    root->rflag=1;
  if((pre!=NULL)&&(root->lflag==1))
    root->left=pre;
  if((pre!=NULL)&&(pre->rflag==1))
    pre->right=root;
  pre=root;
 }
}
template<class T>
void TBSTree<T>::ThInorder(THNode<T> *&root)
{THNode<T> *p;
 if(root==NULL) return;
 p=root;
 while(p->lflag==0)
  p=p->left;
  do
  {cout<<p->data<<"  ";
   if(p->rflag==1)
     p=p->right;
   else
    {p=p->right;
     while(p->lflag==0)
      p=p->left;
    }
  }while(p!=NULL);
}


