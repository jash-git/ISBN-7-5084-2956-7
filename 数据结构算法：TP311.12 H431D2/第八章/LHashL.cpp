//ɢ�б����ʵ��LHashL.cpp
#include"LHashL.h"
//���캯��,��ʼ��ɢ�б�
template<class T>
LHList<T>::LHList(int MaxSize)
{m=MaxSize;
 HT=new LNode*[m];
 for(int i=0; i<m; i++) HT[i]=NULL;
}
//��������,���һ��ɢ�б�
template<class T>
LHList<T>::~LHList()
{LNode* p;
 for(int i=0; i<m; i++) {
   p=HT[i];
 while(p!=NULL) {
   HT[i]=p->next;
   delete p;
   p=HT[i];}}
 delete []HT;
}
//���ڿ��ŵ�ַ���Ľ�ɢ�б�
template<class T>
void LHList<T>::CreateHashTable(T A[],int n)
{//����A[0..n-1]�н�㽨��ɢ�б�T[0..m-1]
 int i;
 if(n>m) //�ÿ��Ŷ�ַ�������ͻʱ,װ�����Ӧ��벻����1
  {cerr<<"Load factor>1:\n";return;}
 for(i=0;i<n;i++) //���ν�A[0..n-1]���뵽ɢ�б�T[0..m-1]��
   Insert(A[i]);
}
//��ɢ�б����һ��Ԫ��
template<class T>
void LHList<T>::Insert(T item)
{//����item��ɢ�е�ַ
 int d=HashAddress(item,m);
 //Ϊ��Ԫ�ط���洢���
 LNode* p=new LNode;
 //���½����뵽d������ı�ͷ
 p->data=item;
 p->next=HT[d];
 HT[d]=p;
}
//��ɢ�б��в���һ��Ԫ��
template<class T>
T *LHList<T>::Search(T item)
{//����item��ɢ�е�ַ
 int d=HashAddress(item,m);
//�õ���Ӧ������ı�ͷָ��
 LNode* p=HT[d];
//�Ӹõ�������˳�����ƥ���Ԫ��,
//�����ҳɹ����ظ�Ԫ�صĵ�ַ
 while(p!=NULL) {
  if(p->data==item) return &(p->data);
  else p=p->next;}
  //����ʧ�ܷ��ؿ�ָ��
 return NULL;
}
//��ɢ�б���ɾ��һ��Ԫ��
template<class T>
bool LHList<T>::Delete(T item)
{//����item��ɢ�е�ַ
 int d=HashAddress(item,m);
 //pָ���Ӧ������ı�ͷָ��
 LNode* p=HT[d];
 //��������Ϊ�գ���ɾ��ʧ�ܷ��ؼ�
 if(p==NULL) return false;
 //����ͷ���Ϊ��ɾ���Ľ��,��ɾ�����󷵻���
 if(p->data==item) {
   HT[d]=p->next;
   delete p;
   return true;}
 //�ӵڶ����������ұ�ɾ����Ԫ��,
 //�����ҳɹ���ɾ������������
  LNode* q=p->next;
  while(q!=NULL)
   {if(q->data==item) {
     p->next=q->next;
     delete q;
     return true;}
    else { p=q;q=q->next;}}
 //û�п�ɾ����Ԫ��,�򷵻ؼ�
 return false;
}
//��ʾ���ɢ�б��е�����Ԫ��
template<class T>
void LHList<T>::PrintHashList()
{LNode* p;int n=0;
 for(int i=0; i<m; i++) {
   p=HT[i];n++;
   cout<<setw(3)<<i<<':';
   while(p) {n++;
    cout<<setw(3)<<p->data;
    if(n%5==0) cout<<endl;
      p=p->next;}
 }
}

