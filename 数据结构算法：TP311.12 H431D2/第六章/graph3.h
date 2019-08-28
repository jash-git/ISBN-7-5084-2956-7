//���ÿ�³˹����������߼�������ʾͼ����С������
//ͼ������������͵Ķ���graph3.h
//��ඥ����
const int MaxV=10;
//���Ȩֵ
const int MaxValue=99;
//�����ڽӱ��еı߽������
struct edgenode {
  int adjvex;     //�ڽӵ���
  int weight;     //Ȩֵ��
  edgenode* next; //ָ����һ���߽�������
};
//�����ڽӱ�����
typedef edgenode** adjlist;
//����߼������е�Ԫ������
struct RCW
{int row,col;//���к�
 int weight;//Ȩֵ
};
//�ඨ��
class adjMList
{private:
  int numE;//��ǰ����
  int GA[MaxV][MaxV];//�����ڽӾ���
 public:
  //���캯��,��ʼ��ͼ���ڽӾ�����߼�����
  adjMList(RCW GE[],int n,int e);
  //��ʼ��ͼ���ڽӱ�
  void InitGAdjoin(adjlist& GL,int n);
  //ɾ��ͼ���ڽӱ�
  void DeleteAdjoin(adjlist GL,int n);
  //������Ȩͼ���ڽӾ���
  void CreateMatrix(int n,int &e,RCW r[]);
  //����߼������е�ÿ����
  void OutputEdgeSet(RCW ge[],int e);
  //����ͼ���ڽӾ�������ͼ�ı߼�����
  void ChangeEdgeSet(RCW GE[],int n,int e);
  //���ÿ�³˹����������߼�����GE��ʾͼ
  //����С������,����ÿ�������δ�������C��
  void Kruskal(RCW GE[],RCW C[],int n,int e);
  //�������ı�����Ƿ�Խ��,��Խ��������
  void Check(int n, int& i, int& j);
};
