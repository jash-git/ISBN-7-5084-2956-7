//�Դ����ļ���������Ĳ���WSortM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include<time.h>
#include "WSort.h"
void main()
{cout<<"WSortM.cpp���н��:\n";
 int m=10;
 char *fa=".\\fa1.dat";
 ElemType d[10];
 srand(time(0));
 fstream fna(fa,ios::out|ios::in|ios::dec|ios::trunc);
 cout<<"�ļ�δ����ǰ�Ľ��:\n";
 LoadFile myfile(fa,m);
 myfile.Print(fna);
 cout<<"�ļ������Ľ��:\n";
 myfile.FMergeSort(fna,d,m);
 myfile.Print(fna);
 fna.close();cin.get();}