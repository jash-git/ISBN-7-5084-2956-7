//ͼ������������͵Ķ���graph1.h
//��ඥ����
const int MaxV=10;
//�����ڽӱ��еı߽������
struct edgenode {
 int adjvex;     //�ڽӵ���
 int weight;     //Ȩֵ��
 edgenode* next; //ָ����һ���߽�������
 edgenode(){}
 edgenode(int d,int w):adjvex(d),weight(w),next(NULL){}
};
struct Top //���������Ԫ������
{char data;//��������
 edgenode *adj;//�ڽӱ�ָ��
};
struct RCW
{int row;
 int col;
 int weight;
};
//�ڽӱ���ඨ��
class AdjAdjoin
{private:
  Top g[MaxV];//��������
  int size;   //�������
  int numE;   //��ǰ�ߵ�����
 public:
  edgenode **GL;//�����ڽӱ�
  //���캯��
  AdjAdjoin() {}
  //���캯��,��ʼ��ͼ���ڽӱ�
  AdjAdjoin(edgenode **gl,int n);
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
  void InsertV(const char &V);
  //���뻡<v1,v2>,ȨΪweight
  void InsertEdge(const int v1,const int v2,int weight);
  //ɾ������i�붥��i��ص����б�
  void DeleteVE(const int v);
  //ɾ����<v1,v2>
  void DeleteEdge(const int v1,const int v2);
  //ɾ��ͼ���ڽӱ�
  void DeleteAdjoin(int n);
  //����ͼ
  void CreatGraph(char V[],int n,RCW E[],int e);
  //����ͼ���ڽӱ�
  void CreateAdjoin(int n,int k1,int k2,RCW rcw[]);
  //�ӳ�ʼ��vi������������������ڽӱ�GL��ʾ��ͼ
  void dfsAdjoin(bool*& visited,int i,int n);
  //�ӳ�ʼ��vi������������������ڽӱ�GL��ʾ��ͼ
  void bfsAdjoin(bool*& visited,int i,int n);
  //�������ı�����Ƿ�Խ��,��Խ��������
  void Check(int n,int& i,int& j);
   //�Է���ͨͼ���������������
  void dfsAdjoin(int n);
  //�Է���ͨͼ���й����������
  void bfsAdjoin(int n);
};

