//˳��ѭ�����е��ඨ��queue2.h
//�����г���
#define QueueSize 10
typedef int datatype;
class cirqueue{
 private:
//����ͷָ��,�����в�����ָ�����ͷԪ��
  int front;
//����βָ��,�����в�����ָ�����βԪ�ص���һ��λ��
  int rear;
  int count;
//��ʼ���Ķ�̬����洢�ռ��׵�ַ
  datatype *data;
 public:
//���캯��
 cirqueue();
//��������
 ~cirqueue(){delete []data;}
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

