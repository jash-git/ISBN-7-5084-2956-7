//ѭ��˫�˶���˳���ʾduilie.cpp
#include <iostream.h>
#include <iomanip.h>
#include <assert.h>
template <class T> class DoubleQueue
{ int end1,end2;//end1��end2Ϊ�˵�
  T *data;
  int size;
 public:
  DoubleQueue(int sz=10);
  ~DoubleQueue(){delete[] data;}
  void Enqueue(T item,int end);
  void Dequeue(int end);
  int IsEmpty(){return end1==end2;}
  int IsFull(){return (end1+1)%size==end2;}
  void list(int end);
};
//ѭ��˫�˶��в���
template <class T>
DoubleQueue <T>::DoubleQueue(int sz):
  end1(0),end2(0),size(sz){
    data=new T[size];assert(data!=0);
}
//ѭ��˫�˶��в�����Ԫ�ز���
template <class T>
void DoubleQueue <T>::Enqueue(T item,int end)
{ assert(!IsFull());
  if(end==1){
    end1=(end1+1)%size;
    data[end1]=item;}
  else{
    data[end2]=item;
    end2=(end2-1+size)%size;}
}
// ѭ��˫�˶���ɾ������
template <class T>
void DoubleQueue <T>::Dequeue(int end)
{ assert(!IsEmpty());
  if(end==1){
    end1=(end1+size-1)%size;}
  else{
    end2=(end2+1)%size;}
}
// ѭ��˫�˶����������
template <class T>
void DoubleQueue <T>::list(int end)
{ if(end==1){
    for(T p=(end2+1)%size;p<=end1;p=(p+1)%size)
     cout<<setw(3)<<data[p];
    cout<<endl;}
  else{
    for(T p=end1;p!=end2;p=(p+size-1)%size)
      cout<<setw(3)<<data[p];
    cout<<endl;}
}
//ѭ��˫�˶��еĲ���
void main()
{DoubleQueue <int> Q;
 cout<<"duilie.cpp���н��:\n";
//�����end1����4,5,6 ����Ԫ��
 Q.Enqueue(4,1);
 Q.Enqueue(5,1);
 Q.Enqueue(6,1);
 cout<<"��������end1����4,5,6����Ԫ�غ����:\n";
 Q.list(1);
// ɾ���������һ��Ԫ��
 Q.Dequeue(1);
 cout<<"���ɾ�����һ��Ԫ�غ�Ķ���end1�����:\n";
 Q.list(1);
//�����end2����7,8,9 ����Ԫ��
 Q.Enqueue(7,2);
 Q.Enqueue(8,2);
 Q.Enqueue(9,2);
 cout<<"��������end2����7,8,9����Ԫ�غ����:\n";
 Q.list(2);cin.get();}

