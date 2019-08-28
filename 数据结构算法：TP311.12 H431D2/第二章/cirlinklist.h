//��ѭ��������ඨ��cirlinklist.h
#define LEN 20
typedef int ElemType;
//��ѭ�������н�������
typedef struct Lnode {
 ElemType data;   //ֵ��
 Lnode* next;     //ָ����
}LNode;
class cirlinklist
{private:
  LNode *head;//ָ���ͷ��ָ��
  LNode *curr;//��ǰ���ָ��
  int count;// ��ѭ������Ľ�����
 public:
//���캯��
  cirlinklist();
//��������
  ~cirlinklist(){delete head;}
//�������������Ĵ�ͷ���ĵ�ѭ������
  LNode *CreateCLinkL(int,int,int mark=0);
//��յ�ѭ������
  void ClearCList();
//��ѭ��������
  int CListSize();
//��鵥ѭ�������Ƿ�Ϊ��
  bool CListEmpty();
//����ָ���pos������ָ��
  LNode *Index(int pos);
//���ص�ѭ��������ָ����ŵĽ��ֵ
  ElemType GetElem(int pos);
//������ѭ������
  LNode *TraverseCList();
//��ǰָ��currָ��pos��㲢����curr
  LNode *Reset(int pos=0);
//��ǰָ��currָ����һ��㲢����
  LNode *Next();
// �е�ѭ������ǰָ��curr==head ��
  bool EndOCList();
//�е�ѭ������ǰָ��curr->next�Ƿ񵽴��β
  bool EndCList();
//ɾ����ѭ������ǰָ��curr->next��ָ��㲢������ֵ
  ElemType DeleteNext();
//�ӵ�ѭ�������в���Ԫ��
  bool FindCList(ElemType& item);
//���µ�ѭ�������еĸ���Ԫ��
  bool UpdateCList(const ElemType &item,ElemType &e);
//�������е�pos�����������ֵΪitem���½��
  void InsertCList(const ElemType& item,int pos);
//��������ɾ����pos����㲢���ر�ɾ����data
  ElemType DeleteCList(int pos);
};
