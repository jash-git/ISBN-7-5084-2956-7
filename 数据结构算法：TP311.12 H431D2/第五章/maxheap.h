//���ѵ��ඨ��maxheap.h
#define HeapSIZE 15
#define MaxHeapSize 100

class maxheap
{private:
  ElemType *heapArray;
  int maxheapSize;
  int heapsize;
 public:
//����һ���ն�S
  maxheap(int);
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
// �����Ķѵ���,ʹ֮�������ѵĶ���
  void FilterUp();
//ɾ����Ķѵ���,ʹ֮�������ѵĶ���
  void FilterDown();
//�Ѳ���
  void heapInsert(ElemType item);
//��ɾ��
  ElemType heapDelete();
};

