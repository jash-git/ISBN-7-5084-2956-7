//ʹ�û��ݷ�����Թ�����migong.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<fstream.h>
//·�ڵĽṹ�嶨��
typedef struct
{int left;
 int forward;
 int right;
}InterS;
//�Թ��ඨ����ʵ��
class Maze
{private:
  int mazeSize;//·�ڸ���
  int Exit;    //����
  InterS *intSec;//·�ڼ���
 public:
 //���캯��
  Maze(char *filename);
 //��������
  int TravMaze(int intSecV);
};
Maze::Maze(char *filename)
{ifstream fin;
 fin.open(".\\Maze1.dat",ios::in);//���ļ�
 if(!fin)
 {cerr<<"�����ļ��޷���!\n";exit(1);}
 fin>>mazeSize;//����·�ڸ���
 intSec=new InterS[mazeSize+1];//����·�ڼ�������
 for(int i=1;i<=mazeSize;i++)//��������·�ڵĽṹ����ֵ
  fin>>intSec[i].left>>intSec[i].forward>>intSec[i].right;
 fin>>Exit; //������ں���
 fin.close();//�ر��ļ�
}
int Maze::TravMaze(int intSecV)
{if(intSecV>0)
  {if(intSecV==Exit)//�������
    {cout<<intSecV<<"<==";//���·�ں���
     return 1;}
   else if(TravMaze(intSec[intSecV].left))//��������
    {cout<<intSecV<<"<==";//���·�ں���
     return 1;}
   else if(TravMaze(intSec[intSecV].forward))//��ǰ����
    {cout<<intSecV<<"<==";
     return 1;}
   else if(TravMaze(intSec[intSecV].right))//��������
    {cout<<intSecV<<"<==";
     return 1;}
  }
  return 0;
}
//�Թ���Ĳ���
void main()
{cout<<"migong.cpp���н��:\n";
 cout<<"����Թ�����:\n";
 char fileName[20]={".\\Maze1.dat"};
 Maze m(fileName);
 int start=1;
 if(m.TravMaze(start))
  cout<<endl<<"���Թ���һ��ͨ·���������ʾ!\n";
 else cout<<"���Թ���ͨ·!\n";
 cin.get();
}






