//�����ʵ��Tree.cpp
template<class T>
void Tree<T>::DeleteSubTree(TreeNode<T> *&t)
{if(t==NULL) return;
 TreeNode<T> *q=t->firstChild,*p;
 while(q!=NULL)
 {p=q->nextSibling;
  DeleteSubTree(q);
  q=p;}
  printf("�ͷ�:%2c",t->data);
  delete t;
}
template<class T>
int Tree<T>::Current(TreeNode<T> *&t)
{if(t==NULL) return 0;
 curr=t;
 return 1;
}
template<class T>
int Tree<T>::Root()
{if(root==NULL)
  {curr=NULL;
   return 0;}
 return Current(root);
}
template<class T>
int Tree<T>::FirstChild()
{if(curr!=NULL&&curr->firstChild!=NULL)
  return Current(curr->firstChild);
 else return 0;
}
template<class T>
int Tree<T>::NextSibling()
{if(curr!=NULL&&curr->nextSibling!=NULL)
  return Current(curr->nextSibling);
 else return 0;
}
template<class T>
int Tree<T>::Parent()
{if(curr==NULL)
  {curr=root;
   return 0;}
 TreeNode<T> *p=SearchParent(root,curr);
 if(p==NULL) return 0;
 else return Current(p);
}
template<class T>
TreeNode<T> *Tree<T>::SearchParent(TreeNode<T> *&root,TreeNode<T> *&s)
{if(root==NULL) return NULL;
 if(root->FirstChild()==s||root->NextSibling()==s)
  return root;
 TreeNode<T> *p;
 if((p=SearchParent(root->FirstChild(),s))!=NULL) return p;
 if((p=SearchParent(root->NextSibling(),s))!=NULL) return p;
 return NULL;
}
template<class T>
void Tree<T>::InsertChild(T value)
{TreeNode<T> *newNode=new TreeNode<T> (value);
 if(root==NULL)  //��Ϊ����ʱ
  {root=curr=newNode;
   return;}
 if(curr->firstChild==NULL)//����ǰ����޺���ʱ
  curr->firstChild=newNode;
 else                     //����ǰ����к���ʱ
  {TreeNode<T> *p=curr->firstChild;
   while(p->nextSibling!=NULL) p=p->nextSibling;
   p->nextSibling=newNode;
  }
  Current(newNode);//ʹ�½����Ľ���Ϊ��ǰ���
}      
template<class T>
int Tree<T>::DeleteChild(int i)
{TreeNode<T> *r=NULL;
 if(i==1)         //��ɾ����ǰ���ĵ�һ������ʱ
 {r=curr->firstChild;
  if(r==NULL) return 0;//Ҫɾ������Ϊ��ʱ����
  curr->firstChild=r->nextSibling;//����Ҫɾ��������
 }
 else {          //��ɾ����ǰ������������ʱ
  int k=1;
  TreeNode<T> *p=curr->firstChild;
  while(p!=NULL&&k<=i-1)//Ѱ��Ҫɾ��������ָ��
  {p=p->nextSibling;
   k++;}
  if(p!=NULL)//Ѱ�ҵ�Ҫɾ����������ָ��
  {r=p->nextSibling;
   if(r!=NULL)
    p->nextSibling=r->nextSibling;
   else return 0;
  }
  else return 0;
 }
 DeleteSubTree(r);
 return 1;
}
template<class T>
int Tree<T>::DeleteChild1(int i)
{if(root==NULL) return 0;//��Ϊ����ʱ
 TreeNode<T> *r=NULL,*q=root->firstChild;
 if(i==1&&q!=NULL) //����һ����к���ʱ
  {r=root->firstChild;
   root->firstChild=r->nextSibling;//����Ҫɾ��������
  }
 else             //Ҫɾ����һ��������������ʱ
  {int k=1;
   TreeNode<T> *p=root->firstChild;
   while(p!=NULL&&k<=i-1)//Ѱ��Ҫɾ��������ָ��
   {p=p->nextSibling;
    k++;
   }
  if(p!=NULL)    //Ѱ�ҵ�Ҫɾ����������ָ��
   {r=p->nextSibling;
    if(r!=NULL)
     p->nextSibling=r->nextSibling;//����Ҫɾ��������
    else return 0;}
  else return 0;
 }
 DeleteSubTree(r);//���ú���ִ��ɾ��
 return 1;    
}
template<class T>
void Tree<T>::PreOrderTree(TreeNode<T> *&t)
{if(t==NULL) return;
 cout<<setw(2)<<t->data;//��ʾ���������
 if(t->firstChild!=NULL)//�ȸ���������
  PreOrderTree(t->firstChild);
 if(t->nextSibling!=NULL)
  PreOrderTree(t->nextSibling);
}
template<class T>
void Tree<T>::DisplayTree()
{PreOrderTree(root);}

template<class T>
void Tree<T>::DisplayTree1()
{PosOrderTree(root);}

template<class T>
void Tree<T>::PosOrderTree(TreeNode<T> *&t)
{if(t==NULL) return;
 if(t->firstChild!=NULL)//�����������
  PosOrderTree(t->firstChild);
 printf("%2c",t->data);//��ʾ���������
 if(t->nextSibling!=NULL)
  PosOrderTree(t->nextSibling);
}

