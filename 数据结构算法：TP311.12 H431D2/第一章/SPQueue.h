//SPQueue.h
//�������ȼ���ͬԪ�ص��Ƚ��ȳ�
//�����˳�����ȼ������ඨ��
#include<fstream.h>
#define MaxSize 6
typedef struct Datatype
{int taskNo;
 int priority;
}datatype;
class SqPqueue
{private:
  datatype data[MaxSize];
  int count;
 public:
//���캯��
 SqPqueue(){count=0;}
//��������
 ~SqPqueue(){}
//��ն���
 void ClearPq(){count=0;}
// �ж϶ӿ�
 int PQueueEmpty();
// �ж϶���
 int PQueuefull();
//���ع�ϵ�����С��<
 friend int operator <(datatype &,datatype &); 
// ���еĲ���
 void InsertPQ(datatype);
// ���е�ɾ��
 datatype DeQueue();
// ȡ���е�ͷԪ��
 datatype PQueuefront();
//����е�Ԫ�ظ���
 int PQueueSize();
};

 