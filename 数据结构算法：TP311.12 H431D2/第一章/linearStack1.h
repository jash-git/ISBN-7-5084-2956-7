//˳���ջ���ඨ��linearStack1.h
const int LEN=40;
class Stack
{private:
  ElemType stack[LEN];
  int top;
 public:
//���캯��
  Stack(){top=0;}
//��������
  ~Stack(){}
//�������������ջ
  void CreateStack(int,int m=LEN,int mark=0);
//���ջ
  void ClearStack();
//���ջ�Ƿ�Ϊ��
  bool StackEmpty();
//��ȡջ��Ԫ��
  ElemType Peek();
//��ջ�в���Ԫ��
  void Push(const ElemType&,int m=LEN);
//��ջ��ɾ��Ԫ��
  ElemType Pop();
//���ջ�Ƿ�����
  bool StackFull(int m=LEN);
//ջ�����
  void StackPrint(int m=LEN);
};
