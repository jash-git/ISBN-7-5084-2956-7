//���·��(���������㷨)FloydP.h
//���ж���֮������·��
void Floyd(AdjMatrix &G,int dist[6][6],int path[6][6])
//��ͼG��ÿ�Զ���֮�����̾���dist�����·���Ķ������path
{int i,j,k;
 int n=G.NumV();
 for(i=0;i<n;i++)//��ʼ��
  for(j=0;j<n;j++)
  {dist[i][j]=G.GetWeight(i,j);
   if(i!=j&&dist[i][j]!=MaxValue) path[i][j]=i;
   else
    if(i==j) path[i][j]=0;
    else path[i][j]=-1;
  }
  for(k=0;k<n;k++)
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {if(dist[i][j]>(dist[i][k]+dist[k][j]))
      {dist[i][j]=dist[i][k]+dist[k][j];
       path[i][j]=path[k][j];
}}}