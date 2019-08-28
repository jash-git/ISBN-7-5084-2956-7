//�������������ඨ����ʵ��BSTREE1.h
template<class T> class BSTree;
template<class T> struct TNode
{private:
  TNode<T>  *left;//������ָ��
  TNode<T> *right;//������ָ��
 public:
  friend class BSTree<T>;
  T data;//������
  //���캯��
  TNode():left(NULL),right(NULL){ }
  TNode(T item,TNode<T> *left1,TNode<T> *right1)
   :data(item),left(left1),right(right1){ }
};
template<class T> class BSTree
{private:
  int size;
 public:
  //���캯��,������ָ���ÿ�
  BSTree(TNode<T> *&root){root=NULL;size=0;}
  //��ClearBST()�����õĺ���
  void DeleteTree(TNode<T> *&root);
  //�ͷſռ�
  void FreeBST(TNode<T> *&root);
  //����������������н����
  int BSTSize();
  //�ж϶����������Ƿ�Ϊ��
  int BSTEmpty(TNode<T> *&root);
  //ȡ��ָ��
  TNode<T> *GetRoot(TNode<T> *&root);
  //�Ӷ����������в���Ԫ��
  TNode<T> *BSTLocate(TNode<T> *&root,T item);
  //������������в���Ԫ��
  void BSTInsert(TNode<T> *&root,T item);
  //�Ӷ�����������ɾ��Ԫ��
  void BSTDelete(TNode<T> *&root,T item);
  //���������������������е����н��
  void Inorder(TNode<T> *&root);
  //����������������
  int BSTreeDepth(TNode<T> *&root);
  //����������������н����
  int BSTreeCount(TNode<T> *&root);
  //�����������������Ҷ�ӽ����
  int BSTreeLeafCount(TNode<T> *&root);
  //���������������ʹ֮��Ϊһ�ÿ���
  void ClearBSTree(TNode<T> *&root);
};
//�������������ʵ��
template<class T>
void BSTree<T>::DeleteTree(TNode<T> *&root)
{if(root==NULL)	return;
 if(root->left!=NULL)
   DeleteTree(root->left);
 if(root->right!=NULL)
   DeleteTree(root->right);
 free(root);
}
template<class T>
void BSTree<T>::FreeBST(TNode<T> *&root)
	{DeleteTree(root);
	}
template<class T>
int BSTree<T>::BSTSize()
{return(size);}

template<class T>
int BSTree<T>::BSTEmpty(TNode<T> *&root)
{if(root==NULL)
   return(1);
 else
   return(0);
}
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
      if(item<t->data)
	t=t->left;
      else
	t=t->right;
   }
 return(t);
}
template<class T>
void BSTree<T>::BSTInsert(TNode<T> *&root,T item)
{TNode<T> *t,*p,*newN;
 newN=new TNode<T>;
 newN->data=item;
 if(root==NULL)
   {root=newN;
    size++;
    return;
   }
 t=root;
 p=NULL;
 while(t!=NULL)
   {p=t;
    if(item<t->data)
      t=t->left;
    else
      t=t->right;
   }
 if(item<p->data)
   p->left=newN;
 else
   p->right=newN;
 size++;
}
template<class T>
void BSTree<T>::BSTDelete(TNode<T> *&root,T item)
{TNode<T> *t,*p,*r,*pr;
 t=root;
 p=NULL;
 while(t!=NULL)
   {if(item==t->data)
      break;
    else
      {p=t;
       if(item<t->data)
	 t=t->left;
       else
	 t=t->right;
      }
   }
 if(t==NULL)
   return;
 if(t->left==NULL)
   {if(p==NULL)
      root=t->right;
    else if(p->left==t)
	   p->left=t->right;
	 else
	   p->right=t->right;
    free(t);
   }
 else
   {pr=t;
    r=t->left;
    while(r->right!=NULL)
      {pr=r;
       r=r->right;
      }
    t->data=r->data;
    if(pr==t)
      pr->left=r->left;
    else
      pr->right=r->left;
    free(r);
   }
  size--;
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
{if(root==NULL) return 0;//���ڿ���,����0�������ݹ�
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
void BSTree<T>::ClearBSTree(TNode<T> *&root)
{DeleteTree(root);
 root=NULL;
 size=0;
}
