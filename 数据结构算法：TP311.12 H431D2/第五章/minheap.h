//��С�ѵ��ඨ��minheap.h
#define HeapSIZE 10
#define MaxHeapSize 100

class minheap
{private:
  ElemType *heapArray;
  int maxheapSize;
  int heapsize;
 public:
//����һ���ն�S
  minheap(int);
//�Ѵ�����ѱ�����
  void Destroyheap();
//�Ѵ�������Ϊ�ն�
  void Clearheap();
//�ѿ��򷵻�true,����false
  bool heapEmpty();
//�����򷵻�true,����false
  bool heapFull();
// �Ѵ����򷵻ضѵ�Ԫ�ظ���,���ѵĳ���
  int heapLength();
//�Ѵ����ҷǿ��򷵻ضѵĶѶ�Ԫ��
  ElemType GetTop();
// �����Ķѵ���,ʹ֮������С�ѵĶ���
  void FilterUp();
//ɾ����Ķѵ���,ʹ֮������С�ѵĶ���
  void FilterDown();
//�Ѳ���
  void heapInsert(ElemType item);
//��ɾ��
  ElemType heapDelete();
};

