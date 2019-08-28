//���ĺ����ֵܱ�ʾ��Ϊ�洢�ṹ�Ľṹ��Tree.h
template<class T> class Tree;
template<class T> struct TreeNode
{friend class Tree<T>;//����Ϊ��Ԫ
 private:
  TreeNode<T> *firstChild;//��һ�����ӽ��ָ����
  TreeNode<T> *nextSibling;//��һ���ֵܽ��ָ����
 public:
  T data;//������
//���캯��
  TreeNode(T value,TreeNode<T> *fc=NULL,
    TreeNode<T> *ns=NULL):data(value),
     firstChild(fc),nextSibling(ns){}
//����ָ����ĳ�Ա����
  TreeNode<T>* &FirstChild()
   {return firstChild;}
  TreeNode<T>* &NextSibling()
   {return nextSibling;}
};
//����
template<class T> class Tree
{private:
  TreeNode<T> *root;//�����ָ��
  TreeNode<T> *curr;//��ǰ���ָ��
  //��ʾ��tΪ�ȸ���������������
  void PreOrderTree(TreeNode<T> *&t);
  //��ʾ��tΪ�����������������
  void PosOrderTree(TreeNode<T> *&t);
  //ʹ��ǰ���Ϊt��ָ���
  int Current(TreeNode<T> *&t);
  //����root�л��ݲ��ҽ��s��˫�׽��
  TreeNode<T> *SearchParent(TreeNode<T> *&root,TreeNode<T> *&s);
 public:
  //���캯������������
  Tree(){root=curr=NULL;}
  ~Tree(){DeleteSubTree(root);}
  //ʹ�����Ϊ��ǰ���
  int Root();
  //ʹ��ǰ����˫�׽��Ϊ��ǰ���
  int Parent();
  //ʹ��ǰ���ĵ�һ�����ӽ��Ϊ��ǰ���
  int FirstChild();
  //ʹ��ǰ�����ֵܽ��Ϊ��ǰ���
  int NextSibling();
  //��valve���뵽��ǰ�������һ�����
  void InsertChild(T value);
  //ɾ����tΪ����������
  void DeleteSubTree(TreeNode<T> *&t);
  //ɾ����ǰ���ĵ�i�����ӽ��
  int DeleteChild(int i);
  //ɾ����rootΪ�����������ĵ�i�����ӽ��
  int DeleteChild1(int i);
  //���ȸ�����������ʾ����������ֵ
  void DisplayTree();
  //���������������ʾ����������ֵ
  void DisplayTree1();
};
  
  
