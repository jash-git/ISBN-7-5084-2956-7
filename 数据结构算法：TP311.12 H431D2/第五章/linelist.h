//���Ա���ඨ��linelist.h
#define OVERFLOW -1
#define LIST_INIT_SIZE 30
#define LISTINCREMENT 10
//���Ա�Ķ�̬����˳��洢�ṹ
class List{
 private:
 ElemType *elem;//�洢�ռ��ַ
 int length;   //��ǰ����
 int listsize;
//��ǰ����Ĵ洢������һ����Ԫ�ش洢����Ϊ��λ
 public:
  //��ʼ��˳���
  void init(List *);
  //ɾ��˳���
  void DestroyList(List &L) {free(&L);}
  //��˳�����Ϊ�ձ�
  void ClearList() {length=0;}
  //�ж�˳����Ƿ�Ϊ�ձ�
  bool ListEmpty()
  {if(length==0) return true;
   else return false;}
   //�ж�˳����Ƿ�Ϊ��
  bool ListFull()
   {return length==listsize;}
  //����˳���ĳ���
  int ListLength();
  // ��ȡ˳����е�i ��Ԫ��
   ElemType GetElem(int,ElemType *);
  //˳���Ĳ����㷨
  bool ListInsert(int,ElemType);
};
