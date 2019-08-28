//ͼ������������͵Ķ���graph.h
//��ඥ����
const int MaxV=10;
//���Ȩֵ
const int MaxValue=99;
//�����ڽӱ��еı߽������
struct edgenode {
 int adjvex;   //�ڽӵ���
 int weight;   //Ȩֵ��
 edgenode* next;//ָ����һ���߽�������
};
//�����ڽӱ�����
typedef edgenode** adjlist;
//�ڽӾ����ඨ��
class AdjMatrix
{private:
  char g[MaxV];//������Ϣ����
  int size;//��ǰ������
  int GA[MaxV][MaxV];//�����ڽӾ���GA
  int numE;//��ǰ����
 public:
  //���캯��,��ʼ��ͼ���ڽӾ���
  AdjMatrix(int n,int k2);
  //�ж�ͼ�շ�
  bool GraphEmpty() {return size==0;}
  //ȡ��ǰ������
  int NumV() {return size;}
  //ȡ��ǰ����
  int NumEdges() {return numE;}
  //ȡ����i��ֵ
  char GetValue(const int i);
  //ȡ��<v1,v2>��Ȩ
  int GetWeight(const int v1,const int v2);
  //��λ��pos�����붥��V
  void InsertV(const char &V,int pos);
  //���뻡<v1,v2>,ȨΪweight
  void InsertEdge(const int v1,const int v2,int weight);
  //ɾ������i�붥��i��ص����б�
  char DeleteVE(const int i);
  //ɾ����<v1,v2>
  void DeleteEdge(const int v1,const int v2);
  //����ͼ���ڽӾ���
  void CreateMatrix(int n, int k1,int k2);
  //k1Ϊ0���������Ϊ����,k2Ϊ0����Ȩ����Ϊ��Ȩ
  //�ӳ�ʼ��vi������������������ڽӾ����ʾ��ͼ
  void dfsMatrix(bool*& visited,int i,int n,int k2);
  //�ӳ�ʼ��vi������������������ڽӾ����ʾ��ͼ
  void bfsMatrix(bool*& visited,int i,int n,int k2);
  //��ͼ���ڽӾ���õ�ͼ���ڽӱ�
  void graphChange(adjlist &GL,int n,int k2);
  //�������ı�����Ƿ�Խ��,��Խ��������
  void Check(int n,int& i,int& j);
  //��ͼ���ڽӾ�����ͼ
  void Creatgraph(int n,int k2);
  //�Է���ͨͼ���������������
  void dfsMatrix(int n,int k2);
  //�Է���ͨͼ���й����������
  void bfsMatrix(int n,int k2);
};
