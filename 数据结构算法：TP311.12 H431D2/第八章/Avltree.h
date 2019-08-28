//ƽ������������ඨ����ʵ��AVLTREE.h
template<class T> class BSTree;
//ƽ������������Ľ�����Ͷ���
template<class T> struct TNode
{private:
  TNode<T>  *left;//������ָ��
  TNode<T> *right;//������ָ��
 public:
  int balance;//ƽ������
  T data;//������
  friend class BSTree<T>;
  //���캯��
  TNode():left(NULL),right(NULL),balance(0){ }
  TNode(T item,TNode<T> *left1,TNode<T> *right1)
   :balance(0),data(item),left(left1),right(right1){ }
};
template<class T> class BSTree
{private:
  int size;
 public:
  //���캯��
  BSTree(TNode<T> *&root):size(0){root=NULL;}
  //��ClearBST()�����õĺ���
  void DeleteTree(TNode<T> *&root);
  //LL�͵�������
  void LL(TNode<T> **a,TNode<T> **b);
  //RR�͵�������
  void RR(TNode<T> **a,TNode<T> **b);
  //LR�͵�������
  void LR(TNode<T> **a,TNode<T> **b);
  //RL�͵�������
  void RL(TNode<T> **a,TNode<T> **b);
  //�ͷſռ�
  void FreeBST(TNode<T> *&root);
  //��ƽ����������������н����
  int BSTSize();
  //�ж�ƽ������������Ƿ�Ϊ��
  int BSTEmpty(TNode<T> *&root);
  //ȡ��ָ��
  TNode<T> *GetRoot(TNode<T> *&root);
  //��ƽ������������в���Ԫ��
  TNode<T> *BSTLocate(TNode<T> *&root,T item);
  //��ƽ������������в���Ԫ��
  void BSTInsert(TNode<T> *&root,T item);
  //�������ƽ������������е����н��
  void Inorder(TNode<T> *&root);
  //��ƽ����������������
  int BSTreeDepth(TNode<T> *&root);
  //��ƽ����������������н����
  int BSTreeCount(TNode<T> *&root);
  //��ƽ�����������������Ҷ�ӽ����
  int BSTreeLeafCount(TNode<T> *&root);
  //���ƽ�������������ʹ֮��Ϊһ�ÿ���
  void ClearBST(TNode<T> *&root);
  //��ʼ��ƽ�����������
  void SetTNode(TNode<T> *&root,T item);
  //��ȡ���õ�ƽ�������������һ�����
  TNode<T> *GetTNode(T item,TNode<T> *left,TNode<T> *right);
};
//ƽ���������������ʵ��
template<class T>
void BSTree<T>::DeleteTree(TNode<T> *&root)
{if(root==NULL) return;
 if(root->left!=NULL)
  DeleteTree(root->left);
 if(root->right!=NULL)
  DeleteTree(root->right);
 free(root);
}
template<class T>
void BSTree<T>::LL(TNode<T> **a,TNode<T> **b)
{(*a)->balance=0;
 (*a)->left=(*b)->right;
 (*b)->balance=0;
 (*b)->right=(*a);
}
template<class T>
void BSTree<T>::RR(TNode<T> **a,TNode<T> **b)
{(*a)->balance=0;
 (*a)->right=(*b)->left;
 (*b)->balance=0;
 (*b)->left=(*a);
}
template<class T>
void BSTree<T>::LR(TNode<T> **a,TNode<T> **b)
{TNode<T> *c;
 c=(*b)->right;//c�ǲ�����
 (*a)->left=c->right;
 (*b)->right=c->left;
 c->left=(*b);
 c->right=(*a);
 switch(c->balance)
  {case 0:(*a)->balance=0;
          (*b)->balance=0;
          break;
   case 1:(*a)->balance=-1;//����Ľ����c��������
          (*b)->balance=0;
          break;
   case -1:(*a)->balance=0;//����Ľ����c��������
          (*b)->balance=1;
          break;}
 c->balance=0;
 (*b)=c;//ʹbָ�������������ĸ�
}
template<class T>
void BSTree<T>::RL(TNode<T> **a,TNode<T> **b)
{TNode<T> *c;
 c=(*b)->left; //c�ǲ�����
 (*a)->right=c->left;
 (*b)->left=c->right;
 c->right=(*b);
 c->left=(*a);
 switch(c->balance)
  {case 0:(*a)->balance=0;
          (*b)->balance=0;
          break;
   case 1:(*a)->balance=0;//����Ľ����c��������
          (*b)->balance=-1;
          break;
   case -1:(*a)->balance=1;//����Ľ����c��������
           (*b)->balance=0;
          break;}
 c->balance=0;
 (*b)=c;//ʹbָ�������������ĸ�
}
template<class T>
void BSTree<T>::FreeBST(TNode<T> *&root)
{DeleteTree(root);}
template<class T>
int BSTree<T>::BSTSize()
{return(size);}
template<class T>
int BSTree<T>::BSTEmpty(TNode<T> *&root)
{if(root==NULL) return(1);
 else return(0);}
template<class T>
TNode<T> *BSTree<T>::GetRoot(TNode<T> *&root)
{return(root);}
template<class T>
TNode<T> *BSTree<T>::BSTLocate(TNode<T> *&root,T item)
{TNode<T> *t;
 t=root;
 while(t!=NULL)
  {if(item==t->data) break;
   else
    if(item<t->data) t=t->left;
    else t=t->right;}
 return(t);
}
template<class T>
void BSTree<T>::BSTInsert(TNode<T> *&root,T item)
{TNode<T> *t,*p,*newN,*a,*b,*f;
 newN=new TNode<T>;
 newN->data=item;
 if(root==NULL)
  {root=newN;
   size++;
   return;}
 t=root;p=NULL;
 a=t;f=p;
 while(t!=NULL)
  {if(t->balance!=0)
    {a=t;f=p;}
   p=t;
   if(item<t->data) t=t->left;
   else t=t->right;}
 if(item<p->data) p->left=newN;
 else p->right=newN;
  size++;
 if(item<a->data)
  {b=t=a->left;}
 else {b=t=a->right;}
 while(t!=NULL&&t->data!=item)
  {if(item<t->data)
    {t->balance=1;
     t=t->left;}
   else {t->balance=-1;t=t->right;}}
 if(a->balance==0)
  {if(item<a->data) a->balance=1;
   else a->balance=-1;
   return;}
 else
  if(item<a->data&&a->balance==-1||
    item>a->data&&a->balance==1)
   {a->balance=0;return;}
  else
   {if(a->balance==1)
     if(b->balance==1)
      LL(&a,&b);
     else LR(&a,&b);
    else
     if(b->balance==-1) RR(&a,&b);
     else RL(&a,&b);}
    if(f==NULL) root=b;
    else
     {if(f->left==a) f->left=b;
      else f->right=b;}
}
template<class T>
void BSTree<T>::Inorder(TNode<T> *&root)
{if(root!=NULL) {
  Inorder(root->left);
  cout<<setw(2)<<root->data;
  Inorder(root->right);}
}
template<class T>
int BSTree<T>::BSTreeDepth(TNode<T> *&root)
{if(root==NULL) return 0;
 else
  {  //���������������
   int dep1=BSTreeDepth(root->left);
     //���������������
   int dep2=BSTreeDepth(root->right);
     //�����������
   if(dep1>dep2) return dep1+1;
   else return dep2+1;}
}
template<class T>
int BSTree<T>::BSTreeCount(TNode<T> *&root)
{if(root==NULL) return 0;
 else 
  return BSTreeCount(root->left)+BSTreeCount(root->right)+1;
}
template<class T>
int BSTree<T>::BSTreeLeafCount(TNode<T> *&root)
{if(root==NULL) return 0;
 else
  if(root->left==NULL && root->right==NULL) return 1;
  else
   return BSTreeLeafCount(root->left)+BSTreeLeafCount(root->right);
}
template<class T>
void BSTree<T>::ClearBST(TNode<T> *&root)
{DeleteTree(root);
 root=NULL;
 size=0;
}
template<class T>
void BSTree<T>::SetTNode(TNode<T> *&root,T item)
{root->data=item;
 root->balance=0;
 root->left=NULL;
 root->right=NULL;
}
template<class T>
TNode<T>* BSTree<T>::GetTNode(T item,TNode<T> *left,TNode<T> *right)
{TNode<T> *ptr;
 ptr=new TNode<T>;
 ptr->data=item;
 ptr->balance=0;
 ptr->left=left;
 ptr->right=right;
 return(ptr);
}
