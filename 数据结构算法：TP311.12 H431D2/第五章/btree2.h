//�������ඨ��btree2.h
//����������������
template<class T>class BinaryTree;
template<class T> struct BTreeNode {
 private:
  BTreeNode<T> *left;//������ָ��
  BTreeNode<T> *right;//������ָ��
 public:
  T data;//������
  //���캯��
  BTreeNode():left(NULL),right(NULL) { }
  BTreeNode(T item,BTreeNode<T> *left1=NULL,
    BTreeNode<T> *right1=NULL):data(item),
    left(left1),right(right1){ }
  BTreeNode<T> *&Left(){return left;}
  BTreeNode<T> *&Right(){return right;}
  friend class BinaryTree<T>;
};
//�������ඨ��
template<class T>class BinaryTree {
 private:
  BTreeNode<T> *root;
 public:
//���캯��,��ʼ��������Ϊ��
  BinaryTree() {root=NULL;}
//�����ַ�����a�Ķ��������������Ӧ�Ķ������洢�ṹ
  void CreateBTree(char* a);
//�ж϶������Ƿ�Ϊ��
  bool BTreeEmpty() {return root==NULL;}
//����һ�ֱ�����������������е����н��
  void TraverseBTree(int mark);
//���ڱ����ĵݹ麯��
  void Traverse(BTreeNode<T> *&BT,int mark);
//������������
  int BTreeDepth();
//�������������ȵĵݹ麯��
  int Depth(BTreeNode<T> *&BT);
//������������н����
  int BTreeCount();
//����������������н�����ĵݹ麯��
  int Count(BTreeNode<T> *&BT);
//�������������Ҷ�ӽ����
  int BTreeLeafCount();
//�����������������Ҷ�ӽ�����ĵݹ麯��
  int LeafCount(BTreeNode<T> *&BT);
//���ն�������һ�ֱ�ʾ�����������������
  void PrintBTree();
//������������������ĵݹ麯��
  void Print(BTreeNode<T> *&BT);
//��������������ĵݹ麯��
  void Clear(BTreeNode<T> *&BT);
//�������������������
  ~BinaryTree();
};

