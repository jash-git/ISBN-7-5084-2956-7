//���·��(�ҿ�˹�����㷨)PshortP.h
//��һ�����㵽�������������·��
void PShortPath(AdjMatrix &G,int v0,int dist[],int path[])
//��G���±�v0�������������̾���dist�����·���±�path
{int n=G.NumV();
 int *s=new int[n];
 int mindis,i,j,u;
 for(i=0;i<n;i++)
 {dist[i]=G.GetWeight(v0,i);
  s[i]=0;
  if(i!=v0&&dist[i]<MaxValue) path[i]=v0;
  else path[i]=-1;
 }
 s[v0]=1;//��Ƕ���v0�ѴӼ���T���뵽����S��
 //�ڵ�ǰ��δ�ҵ����·���Ķ��㼯��ѡȡ������̾���Ķ���u
 for(i=1;i<n;i++)
 {mindis=MaxValue;
  for(j=0;j<n;j++)
   if(s[j]==0&&dist[j]<mindis)
    {u=j;
     mindis=dist[j];
    }
  //���Ѳ��ٴ���·��ʱ�㷨����;�����Է���ͨͼ�Ǳ����
  if(mindis==MaxValue) return;
  s[u]=1;//��Ƕ���u�ѴӼ���T���뵽����S��
  //�޸Ĵ�v0�������������̾�������·��
  for(j=0;j<n;j++)
   if(s[j]==0&&G.GetWeight(u,j)<MaxValue&&
    dist[u]+G.GetWeight(u,j)<dist[j])
   {//����v0������u�������������̾�������·��
    dist[j]=dist[u]+G.GetWeight(u,j);
    path[j]=u;
   }
 }
}
