//K·ƽ��鲢K_WayBM.cpp
#include<iostream.h>
#include<iomanip.h>
//��ʼ�鲢�θ���
const int k=5;
const int m=4;//��ʼ�鲢�������ؼ��ָ���
const int MAXKEY=999;//�ν�����־
//��ά����b������ļ�����
int b[k][m]={{3,5,13,MAXKEY},{4,6,MAXKEY},
 {2,8,MAXKEY},{1,11,MAXKEY},{9,12,MAXKEY}};
typedef int keyType;
typedef struct
{keyType key;}ExNode;
ExNode buff[k][m];//�ṹ���ά����
int ls[k],st[k];

void Merge(int k);
void Read_Buff(int i);
void CreateLoserTree(int ls[],int k);
void Adjust(int ls[],int j,int k);
//K·ƽ��鲢ʵ���㷨
void Merge(int k)
{int q;
 for(int i=0;i<k;i++) Read_Buff(i);
 CreateLoserTree(ls,k);
 q=ls[0];
 while(buff[q][st[q]].key!=MAXKEY)
  {cout<<setw(3)<<buff[q][st[q]].key;
   ++st[q];
   int w=st[q];
   if(st[w]==m) Read_Buff(w);
   Adjust(ls,q,k);
   q=ls[0];
  }
}
//��ȡ���鲢������,��������ر���st[i]���㷨ʵ��
void Read_Buff(int i)
{for(int j=0;j<m;j++)
   buff[i][j].key=b[i][j];
 st[i]=0;
}
//�ع����������㷨ʵ��
void Adjust(int ls[],int j,int k)
{int t=(j+k)/2;
 while(t>0)
  {if(ls[t]==-1) {ls[t]=j;return;}
   if(buff[j][st[j]].key>buff[ls[t]][st[ls[t]]].key)
    {int y=j;j=ls[t];ls[t]=y;}
   t=t/2;
  }
 ls[0]=j;
}
//�������������㷨ʵ��
void CreateLoserTree(int ls[],int k)
{for(int i=0;i<k;i++) ls[i]=-1;
 for(i=k-1;i>=0;i--) Adjust(ls,i,k);
}
//K·ƽ��鲢��ز�������
void main()
{cout<<"K_WayBM.cpp���н��:\n";
 Merge(5);
 cin.get();
}
 






