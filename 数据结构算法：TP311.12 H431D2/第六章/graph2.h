//��������ķ�㷨������ڽ�
//�����ʾ��ͼ����С������
//ͼ������������͵Ķ���graph2.h
//��ඥ����
const int MaxV=10;
//���Ȩֵ
const int MaxValue=99;
//����߼������е�Ԫ������
struct RCW
{int row,col;
 int weight;
}; 
//�ඨ��
class adjMList
{private:
  int numE;//��ǰ����
  int GA[MaxV][MaxV];//�����ڽӾ���
 public:
  //���캯��,��ʼ��ͼ���ڽӾ�����߼�����
  adjMList(RCW GE[],int n,int e);
  //���������Ȩͼ���ڽӾ���
  void CreateMatrix(int n,int &e,RCW r[]);
  //����߼������е�ÿ����
  void OutputEdgeSet(RCW ge[],int e);
  //����ͼ���ڽӾ�������ͼ�ı߼�����
  void ChangeEdgeSet(RCW GE[],int n,int e);
  //����������ͼ�ı߼�����
  void SortEdgeSet(RCW GE[],int e);
  //��������ķ�㷨�Ӷ���v0����������ڽӾ���GA��
  //ʾ��ͼ����С������,��С�������ı߼���������CT��
  void Prim(RCW CT[],int n);
  //�������ı�����Ƿ�Խ��,��Խ��������
  void Check(int n, int& i, int& j);
};
