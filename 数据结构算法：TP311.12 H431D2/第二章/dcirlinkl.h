//˫��ѭ��������ඨ��dcirlinkl.h
typedef int ElemType;
//˫������������Ͷ���
typedef struct DuLNode {
  ElemType  data;
  struct DuLNode *prior;//��ָ��
  struct DuLNode *next;//��ָ��
}DuLNode;
#define LEN 20

class DuLinkList
{private:
  DuLNode *head;//ָ���ͷ��ָ��
  DuLNode *curr;//��ǰ���ָ��
  int count;// ˫��ѭ������Ľ�����
 public:
//���캯��
  DuLinkList();
//��������
  ~DuLinkList(){delete head;}
//�������������Ĵ�ͷ����˫��ѭ������
  DuLNode *CreateCLinkL(int,int,int mark=0);
//��յ�ѭ������
  void ClearCList();
//��˫��ѭ��������
  int CListSize();
//���˫��ѭ�������Ƿ�Ϊ��
  bool CListEmpty();
//����ָ���pos������ָ��
  DuLNode *Index(int pos);
//����˫��ѭ��������ָ����ŵĽ��ֵ
  ElemType GetElem(int pos);
//����˫��ѭ������
  void TraverseCList();
//��ǰָ��currָ��pos��㲢����curr
  DuLNode *Reset(int pos=0);
//��ǰָ��currָ����һ��㲢����
  DuLNode *Next();
//��ǰָ��currָ����һ��㲢����
  DuLNode *Prior();
// ��˫��ѭ������ǰָ��curr==head ��
  bool EndOCList();
//��˫��ѭ������ǰָ��curr->next�Ƿ񵽴��β
  bool EndCList();
//��˫��ѭ������ǰָ��curr->prior�Ƿ񵽴��β
  bool PEndCList();
//ɾ��curr->next��ָ���,��������ɾ����data
  ElemType DeleteNt();
//��˫��ѭ�������в���Ԫ��
  bool FindCList(ElemType& item);
//����˫��ѭ�������еĸ���Ԫ��
  bool UpdateCList(const ElemType &item,ElemType &e);
//�������е�pos�����ǰ������ֵΪitem���½��
  void InsertCLfront(const ElemType& item,int pos);
//�������е�pos�����������ֵΪitem���½��
  void InsertCLafter(const ElemType& item,int pos);
//��������ɾ����pos����㲢���ر�ɾ����data
  ElemType DeleteCList(int pos);
};
