//˳��ջ���ඨ��stack2.h
#define ERROR 0
#define EQUAL 1
#define OVERFLOW -1
#define STACKSIZE 100
#define STACKINCREMENT 10

class SqStack
{private:
  SElemType *base;
  SElemType *top;
  int stacksize;
 public:
//���캯��
  SqStack();
//ջ������ջ������
  Status DestroyStack();
//ջ��������Ϊ��ջ
  Status ClearStack();
//ջ�����򷵻�true,����false
  bool StackEmpty();
// ջ�����򷵻�ջ��Ԫ�ظ���,��ջ�ĳ���
  int StackLength();
//ջ�����ҷǿ��򷵻�ջ��ջ��Ԫ��
  SElemType GetTop();
// ջ���������Ԫ��eΪ�µ�ջ��Ԫ��
  Status Push(SElemType e);
// ջ�����ҷǿ���ɾ��ջ��ջ��Ԫ�ز���e������ֵ
  SElemType Pop(SElemType *e);
// ջ�ı���
  void StackTraverse(void (*visit)(SElemType *));
};

