//ɢ�б��ඨ��LHashL.h
typedef int ElemType;
struct LNode
{ElemType data;
 LNode* next;
};
template<class T>
class LHList
{LNode** HT;
 int m;
 //��һ��Ԫ�ص�ɢ�е�ַ
 int HashAddress(T item, int m)
   {return item%m;}
 public:
  //���캯��,��ʼ��ɢ�б�
  LHList(int MaxSize);
  //��������,���һ��ɢ�б�
  ~LHList();
  //���ڿ��ŵ�ַ���Ľ�ɢ�б�
  void CreateHashTable(T A[],int n);
  //��ɢ�б����һ��Ԫ��
  void Insert(T item);
  //��ɢ�б��в���һ��Ԫ��
  T *Search(T item);
  //��ɢ�б���ɾ��һ��Ԫ��
  bool Delete(T item);
  //��ʾ���ɢ�б��е�����Ԫ��
  void PrintHashList();
};
