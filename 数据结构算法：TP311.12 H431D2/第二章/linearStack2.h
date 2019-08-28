//��ʽ��ջ���ඨ��linearStack2.h
const int LEN=40;
typedef struct Stack{
  ElemType data;
  struct Stack *next;
}StackNode;//�����������
class LinStack
{private:
  StackNode *top;//ָ��ջ����ָ��
  int size;// ��ջ�Ľ�����
 public:
//���캯��
  LinStack();
//��ʼ��ջ,����洢�ռ䲢�ÿ�
  void InitStack(int);
//�������������ջ
  void CreateStack(int,int m=LEN,int mark=0);
//���ض�ջ�Ľ�����
  int StackSize();
//���ջ
  void ClearStack();
//ɾ��ջ
  void DeleteStack();
//���ջ�Ƿ�Ϊ��
  bool StackEmpty();
//��ȡջ��Ԫ��
  ElemType Peek();
//��ջ�в���Ԫ��
  void Push(const ElemType&);
//��ջ��ɾ��Ԫ��
  ElemType Pop();
//���ջ�Ƿ�����
  bool StackFull(ElemType m=LEN);
//ջ�����
  void StackPrint(ElemType m=LEN);
};
