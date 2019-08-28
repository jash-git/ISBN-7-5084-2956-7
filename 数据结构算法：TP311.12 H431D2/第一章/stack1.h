//˳��ջ���ඨ��stack1.h
class Stack
{private:
  DataType *data;
  int maxSize;
  int top;
 public:
//������ջ
  void SetStack(int n);
//ջ������ջ������
  void FreeStack();
//ջ�����򷵻�ջ��Ԫ�ظ���,��ջ�ĳ���
  int StackSize();
//�ж�ջ�Ƿ�Ϊ��
  bool StackEmpty();
//�ж�ջ�Ƿ�Ϊ��
  bool StackFull();
//ջ�����ҷǿ��򷵻�ջ��ջ��Ԫ��
  DataType Peek();
//ջ���������Ԫ��itemΪ�µ�ջ��Ԫ��
  void Push(DataType item);
//ջ�����ҷǿ���ɾ��ջ��ջ��Ԫ�ز���e������ֵ
  DataType Pop(DataType e);
//ջ��������Ϊ��ջ
  void ClearStack();
// ջ�ı���
  void StackTraverse(void (*visit)(DataType *));
};

