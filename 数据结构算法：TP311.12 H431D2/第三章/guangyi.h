//�������ඨ��guangyi.h
#include<string.h>
#include<stdio.h>
#include<math.h>
typedef enum{INTGR,CH,LST}ElemTag;
class GList
{public:
  ElemTag utype;
  GList *first;
  union
  { int intinfo;
    char charinfo;
    GList *hlink;
  };
//���캯��
  GList(){}
//������elemָʾ�ı�Ԫ�ص�ֵ
  GList &Info(GList *&elem);
//���ر�Ԫ��elem��Ԫ��ֵ����������
  int nodetype(GList *elem) {return elem->utype;}
//����elemָʾ�ı�Ԫ�ص�ֵ�޸�Ϊx
  GList &setInfo(GList *&elem,GList &x);
//�жϹ�����Ƿ���ȵ����غ���
  int operator ==(GList &m);
//�жϹ�����Ƿ����
  int equal(GList *s,GList *t);
//������lsָʾ�Ĺ����ĵ�һ��Ԫ�ص�ֵ
  GList &Head(GList *&ls);
//���ع�������һ��Ԫ����������Ԫ����ɵı�
  GList *Tail();
//���ع����ĵ�һ��Ԫ��
  GList *First();
//������elemָʾ�ı�Ԫ�ص�ֱ�Ӻ��Ԫ��
  GList *Next(GList *elem);
//����һ����xΪͷ,��lsָʾ�Ĺ����Ϊβ���±�
  GList *Addon(GList *ls,GList &x);
//��lsָʾ�Ĺ����ĸ���
  GList *Copy(GList *ls);  
//����lsָʾ�ķǵݹ������
  int depth(GList *&ls);
//�жϹ�����Ƿ�Ϊ��
  bool GlistEmpty() {return first==NULL;}
//��������ͷԪ������Ϊx
  void setHead(GList *&ls,GList &x);
//��elem2�嵽����Ԫ��elem1��
  void setNext(GList *elem1,GList *elem2);
//��x����Ϊ��lsָʾ�Ĺ�����β
  void setTail(GList *&ls,GList &x);
//����Ԫ��x��Ϊ��lsָʾ�Ĺ����ĵ�һԪ��
  GList *InsertGL(GList *&ls,GList &x);
//ɾ��������к���x����x�Ĳ���
  GList *delvalue(GList *&ls,int x);
//ɾ��������к���x����x�Ĳ���
  GList *delvalue(GList *&ls,char x);
//S�ǹ�������д��ʽ��,��S���������GL
  GList *CreateGList(char *&s);
//���������ʱ���õĹ���
  int sever(char *&str1,char *&hstr1);
//���������
  void prtGlist(GList *h);
};
