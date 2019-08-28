//���������ʵ��btree2.cpp
//�����ַ�����a�Ķ��������������Ӧ�Ķ������洢�ṹ
template<class T>
void BinaryTree<T>::CreateBTree(char *a)
{BTreeNode<T> *s[80];//s������Ϊ�洢�������и����ָ���ջ
 int top=-1;      //top��Ϊsջ��ջ��ָ��
 root=NULL;       //������ָ���ÿ�
 BTreeNode<T> *p=NULL;//����pΪָ�����������ָ��
 //��k��Ϊ����������������������ı��,k=1����������,k=2����������
 int k;
 istrstream ins(a);//���ַ���a����Ϊ�����ַ���������ins
 char ch;
 ins>>ch;//��ins������˳�����һ���ַ���
 while (ch!='@')
 {//ÿѭ��һ�δ���һ��������ַ�,ֱ��ɨ�赽'@'�ַ�Ϊֹ
  switch(ch)
    {case '(':top++;s[top]=p;k=1;break;
     case ')':top--;break;
     case ',':top++;k=2;break;
     default:p=new BTreeNode<T>;
       p->data=ch;p->left=p->right=NULL;
       cout<<setw(2)<<p->data;
       if(root==NULL) root=p;
       else {
	if(k==1) s[top]->left=p;
        else s[top]->right=p;}}
  ins>>ch;
 }
}
//����һ�ֱ�����������������е����н��
template<class T>
void BinaryTree<T>::TraverseBTree(int mark)
{Traverse(root,mark);}

//���ڱ����ĵݹ麯��
template<class T>
void BinaryTree<T>::Traverse(BTreeNode<T> *&BT,int mark)
{if(mark==1){ //�������
  if(BT!=NULL)
   {cout<<BT->data<<' ';
    Traverse(BT->left,mark);
    Traverse(BT->right,mark);
   }}
 else
  if(mark==2)//�������
   {if(BT!=NULL)
     {Traverse(BT->left,mark);
      cout<<BT->data<<' ';
      Traverse(BT->right,mark);
    }}
  else
   if(mark==3) {//�������
     if(BT!=NULL) {
      Traverse(BT->left,mark);
      Traverse(BT->right,mark);
      cout<<BT->data<<' ';
    }}
  else
   if(mark==4) //�������
    {const MaxLength=80;
     BTreeNode<T> *Q[MaxLength];
    //����洢���������ָ�������ռ���Ϊ����ʹ��
     int front=0, rear=0;
    //�������ָ��Ͷ�βָ��,��ʼ����0��ʾ�ն�
    BTreeNode<T> *p;
    if(BT!=NULL) {
     rear=(rear+1)%MaxLength;  //���ƶ�βָ��
     Q[rear]=BT;}              //���������ָ�����
    while(front!=rear)
     {//�����зǿ�ʱִ��ѭ��
      front=(front+1)%MaxLength;
      //���ƶ���ָ��
      p=Q[front];
      //ɾ�����׽��
      cout<<p->data<<' ';
      //������׽���ֵ
      if(p->left!=NULL)
       {//�����������ӣ������ӽ��ָ�����
	rear=(rear+1)%MaxLength;
        Q[rear]=p->left;
       }
      if(p->right!=NULL)
       {//���������Һ���,���Һ��ӽ��ָ�����
	rear=(rear+1)%MaxLength;
	Q[rear]=p->right;
       }
      }
     }
   else
    {cerr<<"mark��ֵ��Ч!����ʧ��!"<<endl;exit(1);
}}
//������������
template<class T>
int BinaryTree<T>::BTreeDepth()
{return Depth(root);}

//�������������ȵĵݹ麯��
template<class T>
int BinaryTree<T>::Depth(BTreeNode<T> *&BT)
{if(BT==NULL) return 0;//���ڿ���,����0�������ݹ�
 else
   {//���������������
    int dep1=Depth(BT->left);
    //���������������
    int dep2=Depth(BT->right);
    //�����������
    if(dep1>dep2) return dep1+1;
    else return dep2+1;
   }
}
//������������н����
template<class T>
int BinaryTree<T>::BTreeCount()
{return Count(root);}

//����������������н�����ĵݹ麯��
template<class T>
int BinaryTree<T>::Count(BTreeNode<T> *&BT)
{if(BT==NULL) return 0;
 else
  return Count(BT->left)+Count(BT->right)+1;
}
//�������������Ҷ�ӽ����
template<class T>
int BinaryTree<T>::BTreeLeafCount()
{return LeafCount(root);}

//�����������������Ҷ�ӽ�����ĵݹ麯��
template<class T>
int BinaryTree<T>::LeafCount(BTreeNode<T> *&BT)
{if(BT==NULL) return 0;
 else if(BT->left==NULL && BT->right==NULL) return 1;
  else return LeafCount(BT->left)+LeafCount(BT->right);
}
//���ն������Ĺ�����ʾ�������������
template<class T>
void BinaryTree<T>::PrintBTree()
{Print(root);}

//������������������ĵݹ麯��
template<class T>
void BinaryTree<T>::Print(BTreeNode<T> *&BT)
{if(BT==NULL) return;//��Ϊ��ʱ����
 else {//����ִ�����²���
  cout<<BT->data;//���������ֵ
  if(BT->left!=NULL || BT->right!=NULL)
   {if(BT->left!=NULL)
	 cout<<'(';  //���������
    Print(BT->left);//���������
    if(BT->right!=NULL)
     cout<<',';//����������Ϊ����������ŷָ���
    Print(BT->right);//���������
	if(BT->left!=NULL&&BT->right!=NULL)
     cout<<')';} //���������
}}
//��������,���������
template<class T>
BinaryTree<T>::~BinaryTree()
{Clear(root);}
//��������������ĵݹ麯��
template<class T>
void BinaryTree<T>::Clear(BTreeNode<T> *&BT)
{if(BT!=NULL)
   { //���������ǿ�ʱ�������²���
    Clear(BT->left); //ɾ��������
    Clear(BT->right);//ɾ��������
    delete BT;       //ɾ�������
    BT=NULL;}        //�ø�ָ��Ϊ��
}

