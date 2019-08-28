//��������ඨ��linklist3.h
#ifndef linklist3H
#define linklist3H
#define LEN 30
//����ElemTypeΪint
typedef int ElemType;
//�������н�������
typedef struct LNode{
  ElemType data;//ֵ��
  LNode *next;  //ָ����
}LNode;
class LinkList{
  LNode *head;
 public:
//�����βι��캯��
  LinkList();
//��һ���βι��캯��
  LinkList(int);
//�������βι��캯��,n�ǳ�ʼ��Ԫ�ظ���,m�ǻ�
//����,mark=0������,mark>0����,mark<0����
  LinkList(int n,int m,int mark=0);
//���ƹ��캯��
  LinkList(LinkList& HL);
//��������
  ~LinkList();
//��յ�����
  void ClearList();
//��������
  int ListSize();
//��鵥�����Ƿ�Ϊ��
  bool ListEmpty();
//���ص�������ָ����ŵĽ��ֵ
  ElemType GetElem(int pos);
//����������
  void TraverseList(void f(ElemType &));
//�ӵ������в���Ԫ��
  bool FindList(ElemType& item);
//���µ������еĸ���Ԫ��
  bool UpdateList(const ElemType& item,ElemType e);
//���������Ԫ��,mark=0���ڱ���,������ڱ�β
  void InsertList(ElemType item,int mark);
//�ӵ�������ɾ��Ԫ�� , markΪҪɾ���ĵڼ���Ԫ��
  bool DeleteList(ElemType& item,int mark);
//�Ե���������������� mark>0����,������
  void pailie(int mark=1);
//������la ��lb ��Ԫ�ذ�ֵ�ǵݼ�����,����������
//�ϲ��������Ҳ��һ�������
  void MergeList_L(LinkList &la,LinkList &lb);
//�Ե���������������,mark=0������,mark>0����,mark<0����
  void OrderOutputList(int mark=0);
};
#endif
