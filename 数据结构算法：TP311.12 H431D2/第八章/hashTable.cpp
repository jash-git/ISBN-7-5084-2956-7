//��ϣ��hashtable.cpp
#include <iostream.h>
#include <iomanip.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//user data stored in hash table
typedef struct
{int stuff;                  //optional related data
}recType;
typedef int hashIndexType;   //index into hash table
#define compEQ(a,b) (a == b)
//implementation independent declarations
typedef enum {
    STATUS_OK,
    STATUS_MEM_EXHAUSTED,
    STATUS_KEY_NOT_FOUND
}statusEnum;
typedef struct nodeTag {
    struct nodeTag *next;   // next node
    int key;                // key
    recType rec;            // user data
}nodeType;
nodeType **hashTable;
int hashTableSize;
//��ϣ��Ĳ���
statusEnum insert(int key, recType *rec) {
    nodeType *p,*p0;
    hashIndexType bucket;
    //insert node at beginning of list
    bucket=key%hashTableSize;
    if((p=new nodeType )==0)
        return STATUS_MEM_EXHAUSTED;
    p0 = hashTable[bucket];
    hashTable[bucket] = p;
    p->next = p0;
    p->key = key;
    p->rec = *rec;
    return STATUS_OK;
}
//��ϣ���ɾ��
statusEnum Delete(int key) {
    nodeType *p0, *p;
    hashIndexType bucket;
    p0 = 0;//find node
    bucket=key%hashTableSize;
    p = hashTable[bucket];
    while (p&&!compEQ(p->key,key))
     {p0 = p;
      p = p->next;}
    if (!p) return STATUS_KEY_NOT_FOUND;
    //p designates node to delete,remove it from list
    if(p0)
     //not first node,p0 points to previous node
     p0->next=p->next;
    else
     //first node on chain
     hashTable[bucket] = p->next;
    free (p);
    return STATUS_OK;
}
//��ϣ��Ĳ���
statusEnum find(int key, recType *rec)
{   nodeType *p;
    p = hashTable[key%hashTableSize];
    while (p && !compEQ(p->key, key))
        p = p->next;
    *rec = p->rec;
    return STATUS_OK;
}
//��ϣ�����ز����Ĳ���
void main()
{cout<<"hashtable.cpp���н��:\n";
 int i, maxnum,k=0;
 recType *rec;
 int *key;
 statusEnum err;
 maxnum = 10;
 hashTableSize =10;
 srand(time(0));
 if((rec =new recType [maxnum*sizeof(recType)])==0) {
   fprintf (stderr, "out of memory (rec)\n");exit(1);}
   if((key =new int [maxnum*sizeof(int)])==0)
    {fprintf (stderr, "out of memory (key)\n");exit(1);}
 if((hashTable=new nodeType *[hashTableSize*sizeof(nodeType)])==0)
  {fprintf(stderr,"out of memory (hashTable)\n");exit(1);}
   if(rand()) {//fill "key" with unique rand numbers
    for(i=0;i<maxnum;i++) key[i]=rand()%100;
     cout<<" ran ht,"<<maxnum<<" items,"<<hashTableSize<<" hashTable\n";
   }else{
     for(i=0;i<maxnum;i++) key[i]=i;
	  cout<<" seq ht,"<<maxnum<<" items,"<<hashTableSize<<" hashTable\n";
    }
 cout<<"������\n";
 for(i = 0,k=1; i < maxnum; i++,k++) {
   err=insert(key[i],&rec[i]);
   if(!err)//����ɹ�
     cout<<" key["<<setw(2)<<i<<"]="<<setw(3)<<key[i];
     if(k%5==0) cout<<endl;
 }
 cout<<endl<<"���ҽ��\n";
 for(k=1,i = maxnum-1;i>=0;i--,k++) {
   err=find(key[i],&rec[i]);
   if(!err)//���ҳɹ�
     cout<<" key["<<setw(2)<<i<<"]="<<setw(3)<<key[i];
     if(k%5==0) cout<<endl;
 }
 cout<<endl<<"ɾ�����\n";
 for(k=1,i=maxnum-1;i>=0;i--,k++) {
   err=Delete(key[i]);
 if(!err)//ɾ���ɹ�
   cout<<" key["<<setw(2)<<i<<"]="<<setw(3)<<key[i];
   if(k%5==0) cout<<endl;
 }
 cin.get();}
