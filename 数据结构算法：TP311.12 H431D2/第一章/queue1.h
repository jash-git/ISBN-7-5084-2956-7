//˳��ѭ�����е��ඨ��queue1.h
#define QueueSize 10
typedef int datatype;
class cirqueue{
 private:
  int front;
  int rear;
  int count;
  datatype data[QueueSize];
 public:
//���캯��
 cirqueue();
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

