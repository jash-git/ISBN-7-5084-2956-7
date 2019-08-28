//�������������ඨ��BSTreeF.h
//����ѧ����¼����
//����������������ֵ������Ϊѧ����¼����
typedef struct student
{char num[6];//ѧ��
 int grade; //�ɼ�
}ElemType;
template<class T>class BSTree {
 private:
  BSTree<T> *left;//������ָ��
  BSTree<T> *right;//������ָ��
 public:
  T data;//������
  //���캯��
  BSTree():left(NULL),right(NULL) { }
  BSTree(T item,BSTree<T> *left1=NULL,
    BSTree<T> *right1=NULL):data(item),
    left(left1),right(right1){ }
  BSTree<T> *&Left(){return left;}
  BSTree<T> *&Right(){return right;}
//��ʼ����������������������ָ���ÿ�
  void InitBSTree(BSTree<T> *&BST);
//�ж϶����������Ƿ�Ϊ��
  bool BSTreeEmpty(BSTree<T> *&BST);
//�Ӷ����������в���Ԫ��
  bool Find(BSTree<T> *&BST,T item);
//���¶����������еĽ��ֵ
  bool Update(BSTree<T> *&BST,const T item,T newc);
//������������в���Ԫ��
  void Insert(BSTree<T> *&BST,const T &item);
//�Ӷ�����������ɾ��Ԫ��
  bool Delete(BSTree<T> *&BST,T item);
//�������齨��һ�ö���������
  void CreateBSTree(BSTree<T> *&BST,T a[],int n);
//���������������������е����н��
  void Inorder(BSTree<T> *&BST);
//����������������
  int BSTreeDepth(BSTree<T> *&BST);
//����������������н����
  int BSTreeCount(BSTree<T> *&BST);
//�����������������Ҷ�ӽ����
  int BSTreeLeafCount(BSTree<T> *&BST);
//���ն����������Ĺ�����ʾ�������������
  void PrintBSTree(BSTree<T> *&BT);
//���������������ʹ֮��Ϊһ�ÿ���
  void ClearBSTree(BSTree<T> *&BT);
//��BST���������������ȸ������Ĵ���洢���ļ�fn��
  void WriteFile(char* fn, BSTree *BST);
//��fn�ļ��а��ȸ������洢�Ķ����������ָ����ڴ���
  void ReadFile(char* fn, BSTree* &BST);
  void PreorderWrite(ofstream& ofs, BSTree* BST);
  void PreorderRead(ifstream& ifs, BSTree* BST, int& b);
  friend ostream& operator<<(ostream& ostr, const ElemType& x)
   {ostr<<x.num<<':'<<x.grade;return ostr;}
};  
