//������ITBSTree.h
template<class T>
class ITBSTree:public TBSTree<T>
{private:
  //����������������
  void InThread(THNode<T> *&root,THNode<T> *&pre);
 public:
  //���캯��
  ITBSTree(THNode<T> *&tree):TBSTree<T>(tree) {}
  //����������������
  void CreatInThread();
  //��λ�������µĵ�һ�����
  virtual THNode<T> *First();
  //����ǰָ���Ƶ������µĺ�̽��
  virtual void Next();
  //��λ�������µ����һ�����
  virtual void Last();
  //����ǰָ���Ƶ������µ�ǰ�����
  virtual void Prior();
  //������
  void InsertR(THNode<T> *&s,THNode<T> *&r);
};
template<class T>
void ITBSTree<T>::InThread(THNode<T> *&root,THNode<T> *&pre)
{if(root!=NULL)
 {InThread(root->left,pre);//����������������������
  if(root->left==NULL)//��ǰ�����ָ��Ϊ��ָ��ʱ
  {root->lflag=1; //����������ָ��
   root->left=pre;//������������־
  }
  if(pre->right==NULL)//ǰ�������ָ��Ϊ��ָ��ʱ
  {pre->rflag=1; //������������־
   pre->right=root;//����������ָ��
  }
  pre=root;//ǰ�������ָ����ڵ�ǰ���ָ��
  InThread(root->right,pre);}//����������������������
}
template<class T>
void ITBSTree<T>::CreatInThread()
{THNode<T> *t=root;//����ԭ�����ָ��
 root=new THNode<T>;//����ͷ���
 root->lflag=0;
 root->rflag=1;
 if(t==NULL)//��Ϊ����ʱ
  {root->left=root;
   root->right=root;
  }
 else     //��Ϊ�ǿ���ʱ
  {curr=root->left=t;//��ͷ������ָ��
   root->lflag=0;    //��ͷ�������־
   THNode<T> *pre=root;//������ʱָ��
   InThread(curr,pre);//����������������
   pre->right=root;//�����һ������������
   pre->rflag=1;   //�����һ�������ұ�־
   root->right=pre;//��ͷ����������
   root->rflag=1;//��ͷ�����ұ�־
  }
}
template<class T>
THNode<T> *ITBSTree<T>::First()
{curr=root;//�Ӹ���㿪ʼ
 while(curr->lflag==0)
  curr=curr->left;
 if(curr==root) nextC=1;//��������Ϊ��ʱ
 else nextC=0;//��������Ϊ�ǿ�ʱ
 return curr;
}
template<class T>
void ITBSTree<T>::Next()
{if(nextC==1)
  {cerr<<"�ѵ�������β!\n";exit(1);}
 THNode<T> *p=curr->right;//����ǰָ���Ƶ������µĺ�̽��
 if(curr->rflag==0)
  while(p->lflag==0) p=p->left;
 curr=p;
 if(curr==root) nextC=1;
}
template<class T>
void ITBSTree<T>::Last()
{curr=root->right;//ʹcurr��λ�������µ����һ�����
 if(curr==root) priorC=1;
 else priorC=0;
}
template<class T>
void ITBSTree<T>::Prior()
{if(priorC==1)
  {cerr<<"�ѵ�������ͷ!\n";exit(1);}
 THNode<T> *p=curr->left;
 if(curr->lflag==0)
  while(p->rflag==0) p=p->right;
 curr=p;
 if(curr==root) priorC=1;
}
template<class T>
void ITBSTree<T>::InsertR(THNode<T> *&s,THNode<T> *&r)
{//��r����s������Ů����
 r->right=s->right;//s������Ůָ�������������r
 r->rflag=s->rflag;//���ͱ�־
 r->left=s;r->lflag=1;//r��left��Ϊָ��s��ǰ������
 s->right=r;s->rflag=0;//r��Ϊs������Ů
 if(r->rflag==0)//sԭ��������Ů
 {curr=r->right;
  THNode<T> *temp=First();//��sԭ�������������������µ�һ�����
  temp->left=r;//����ָ��r��ǰ������
 }
}
  
