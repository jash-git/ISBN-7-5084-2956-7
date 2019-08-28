//���Ա���ඨ��linelist2.h
#define EQUAL 1
#define OVERFLOW -1
#define LIST_INIT_SIZE 30
#define LISTINCREMENT 10

typedef struct STU{
  char name[10];
  char stuno[8];
  int age;
  int score;
}ElemType;
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
  //�������ر���Ԫ��pre_e��ǰ��
  ElemType PriorElem(ElemType cur_e,ElemType &pre_e);
  // �������ر���Ԫ��next_e�ĺ��
  ElemType NextElem(ElemType cur_e,ElemType &next_e);
  //ɾ��˳����е�i ��Ԫ��
  bool ListDelete(int,ElemType &e);
  //����˳���
  void ListTraverse();
  //����˳���ĳ���
  int ListLength();
  // ��ȡ˳����е�i ��Ԫ��
  void GetElem(int,ElemType *);
  // �ж�˳�����Ԫ���Ƿ����
  bool EqualList(ElemType *,ElemType *);
  // �ж�˳�����Ԫ���Ƿ񲻵�
  bool Less_EqualList(ElemType *,ElemType *);
  //˳���Ĳ����㷨
  bool LocateElem(ElemType,int);
  //�������Ա��еĸ���Ԫ��
  bool UpdateList(ElemType& e,ElemType);
  //˳���ĺϲ��㷨
  void MergeList(List *,List *);
  //˳���Ĳ����㷨
  bool ListInsert(int,ElemType);
  //˳���������㷨
  void UnionList(List *,List *);
  //�����Ա�����������
  void printlist(int);
};
