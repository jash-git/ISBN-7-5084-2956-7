//�������ඨ��btree.h
template<class T>class BTree {
 private:
  BTree<T> *left;//������ָ��
  BTree<T> *right;//������ָ��
 public:
  T data;//������
//���캯��,��ʼ��������Ϊ��
  BTree() {left=right=NULL;}
  BTree(T item,BTree<T> *left1=NULL,
    BTree<T> *right1=NULL):data(item),
    left(left1),right(right1){ }
  BTree<T> *&Left(){return left;}
  BTree<T> *&Right(){return right;}
//�����ַ�����a�Ķ��������������Ӧ�Ķ������洢�ṹ
  void CreateBTree(char* a);
//�ж϶������Ƿ�Ϊ��
  bool BTreeEmpty() {return left==NULL;}
//����һ�ֱ�����������������е����н��
  void TraverseBTree(int mark);
//���ڱ����ĵݹ麯��
  void Traverse(BTree<T> *&BT,int mark);
//������������
  int BTreeDepth();
//�������������ȵĵݹ麯��
  int Depth(BTree<T> *&BT);
//������������н����
  int BTreeCount();
//����������������н�����ĵݹ麯��
  int Count(BTree<T> *&BT);
//�������������Ҷ�ӽ����
  int BTreeLeafCount();
//�����������������Ҷ�ӽ�����ĵݹ麯��
  int LeafCount(BTree<T> *&BT);
//���ն�������һ�ֱ�ʾ�����������������
  void PrintBTree();
//������������������ĵݹ麯��
  void Print(BTree<T> *&BT);
//��������������ĵݹ麯��
  void Clear(BTree<T> *&BT);
//�������������������
  ~BTree();
};


