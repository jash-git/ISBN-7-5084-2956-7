//��ʽ���е��ඨ��linqueue.h
//�����г���
#define QueueSize 10
typedef int datatype;
//�����е����Ͷ���Ϊһ���ṹ���ͣ�
typedef struct QueueNode{
  datatype  data;
  struct QueueNode *next;
}queuenode;
class linkqueue{
 private:
  queuenode  *front;//����ͷָ��.
  queuenode  *rear; //����βָ��.
  int count;// ���н�����
 public:
//���캯��
 linkqueue()
 { front=rear=NULL;count=0; }
//��������
 ~linkqueue(){front=rear=NULL;}
// �ж϶ӿ�
 int queueempty();
// �ж϶���
 int queuefull();
// ���(���еĲ���)
 void enqueue(datatype);
// ����(���е�ɾ��)
 datatype dequeue();
// ȡ���е�ͷԪ��
 datatype queuefront();
//����еĳ���(�����е�Ԫ�ظ���)
 int QueueLength();
};


