//���������ʵ��btree.cpp
//�����ַ�����a�Ķ��������������Ӧ�Ķ������洢�ṹ
template<class T>
void BTree<T>::CreateBTree(char *a)
{BTree<T> *s[80];//s������Ϊ�洢�������и����ָ���ջ
 int top=-1;      //top��Ϊsջ��ջ��ָ��
 left=NULL;       //�Ƚ�left��Ϊ����ָ������ÿ�
 BTree<T> *p=NULL;//����pΪָ�����������ָ��
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
     default:p=new BTree<T>;
       p->data=ch;p->left=p->right=NULL;
       cout<<setw(2)<<p->data;
       if(left==NULL) left=p;
       else {
	if(k==1) s[top]->left=p;
        else s[top]->right=p;}
    }
  ins>>ch;
 }
}
//����һ�ֱ�����������������е����н��
template<class T>
void BTree<T>::TraverseBTree(int mark)
{Traverse(left,mark);}

//���ڱ����ĵݹ麯��
template<class T>
void BTree<T>::Traverse(BTree<T> *&BT,int mark)
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
     BTree<T> *Q[MaxLength];
    //����洢���������ָ�������ռ���Ϊ����ʹ��
     int front=0, rear=0;
    //�������ָ��Ͷ�βָ��,��ʼ����0��ʾ�ն�
    BTree<T> *p;
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
int BTree<T>::BTreeDepth()
{return Depth(left);}

//�������������ȵĵݹ麯��
template<class T>
int BTree<T>::Depth(BTree<T> *&BT)
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
int BTree<T>::BTreeCount()
{return Count(left);}

//����������������н�����ĵݹ麯��
template<class T>
int BTree<T>::Count(BTree<T> *&BT)
{if(BT==NULL) return 0;
 else
  return Count(BT->left)+Count(BT->right)+1;
}
//�������������Ҷ�ӽ����
template<class T>
int BTree<T>::BTreeLeafCount()
{return LeafCount(left);}

//�����������������Ҷ�ӽ�����ĵݹ麯��
template<class T>
int BTree<T>::LeafCount(BTree<T> *&BT)
{if(BT==NULL) return 0;
 else if(BT->left==NULL && BT->right==NULL) return 1;
  else return LeafCount(BT->left)+LeafCount(BT->right);
}
//���ն������Ĺ�����ʾ�������������
template<class T>
void BTree<T>::PrintBTree()
{Print(left);}

//������������������ĵݹ麯��
template<class T>
void BTree<T>::Print(BTree<T> *&BT)
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
BTree<T>::~BTree()
{Clear(left);}
//��������������ĵݹ麯��
template<class T>
void BTree<T>::Clear(BTree<T> *&BT)
{if(BT!=NULL)
   { //���������ǿ�ʱ�������²���
    Clear(BT->left); //ɾ��������
    Clear(BT->right);//ɾ��������
    delete BT;       //ɾ�������
    BT=NULL;}        //�ø�ָ��Ϊ��
}

