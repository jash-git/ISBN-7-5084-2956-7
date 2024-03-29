//索引文件的相关操作
//IndexF.cpp
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
//定义一次读写文件的逻辑块的大小
const int m=5;
//设主文件记录的逻辑删除标记
const int DMark=-10;
//设关键字的类型为整型
typedef int KeyType;
//主文件中的记录类型
struct ElemType {
  KeyType key;  //关键字域
  char rest[10];//其他域,暂用字符数组表示
};
//索引文件中的记录类型
struct IndexItem {
  KeyType key;  //关键字域
  int next;  //保存对应记录的存储位置域
};
//索引文件的类定义
template<class T,class T1>
class InFile
{public:
  //顺序打印出主文件fn1中的每个记录
  void PrintMainFile(char* fn1);
  //顺序打印出索引有序文件fn2中的每个索引项
  void PrintIndexFile(char* fn2);
  //向物理文件名为fn1指针所指主文件中追加n个记录
  void MFAppend(char* fn1,char* fn2,T1 a[],int n);
  //从物理文件名为fn1指针所指主文件中删除n个记录
  void MFDelete(char* fn1,char* fn2,KeyType a[],int n);
  //从物理文件名为fn1指针所指主文件中查找n个记录
  void MFSearch(char* fn1,char* fn2,KeyType a[],int n);
  //把一个记录的索引项插入到有序数组A中
  void SeqInsert(T A[], int mm, T x);
  //向由fn2指针所表示的索引有序文件中插入x索引项
  void IFInsert(char *fn2, T x);
  //从有序数组A中删除一个关键字为x.key的索引项
  bool SeqDelete(T A[],int mm,T& x);
  //从由fn2指针所表示的索引有序文件中删除
  //关键字为x.key的索引项,并由x带回被删除的索引项
  bool IFDelete(char *fn2, T& x);
  //从由fn2指针所表示的索引有序文件中
  //查找关键字为x.key的索引项并由x带回
  bool IFSearch(char* fn2, T& x);
};
//索引文件的类实现
//顺序打印出主文件fn1中的每个记录
template<class T,class T1>
void InFile<T,T1>::PrintMainFile(char* fn1)
{ifstream fin(fn1,ios::in|ios::binary);
 if(!fin)
  {cerr<<fn1<<' '<<"not find!"<<endl;exit(1);}
 T1 x;
 fin.seekg(0,ios::end);       //将文件指针移至文件未
 int b1=sizeof(T1);
 int n=fin.tellg()/b1;        //用n表示文件所含的记录数
 fin.seekg(0);                //将文件指针移至文件首
 for(int i=0;i<n;i++) {
    fin.read((char*) &x, b1); //从文件中读出一条记录
    if(i%4==0)  cout<<endl;   //每行显示4个数据
    cout<<setw(5)<<x.key<<setw(10)<<x.rest;}
    cout<<endl;
    fin.close();}
//顺序打印出索引有序文件fn2中的每个索引项
template<class T,class T1>
void InFile<T,T1>::PrintIndexFile(char* fn2)
{ifstream fin(fn2,ios::in|ios::binary);
 if(!fin)
  {cerr<<fn2<<' '<<"not find!"<<endl;exit(1);}
 T x;
 fin.seekg(0,ios::end);     //将文件指针移至文件未
 int b2=sizeof(T);
 int n=fin.tellg()/b2;      //用n表示文件所含的记录数
 fin.seekg(0);              //将文件指针移至文件首
 for(int i=0;i<n;i++) {
 fin.read((char*) &x, b2);  //从文件中读出一个索引项
 if(i%8==0)  cout<<endl;    //每行显示8个数据
 cout<<setw(4)<<x.key<<setw(3)<<x.next;}
  cout<<endl;
 fin.close();}
//向物理文件名为fn1指针所指主文件中追加n个记录
template<class T,class T1>
void InFile<T,T1>::MFAppend(char* fn1,char* fn2,T1 a[],int n)
{//定义一个输出文件流对象ofs,与主文件相联系
 ofstream ofs(fn1,ios::out|ios::binary);
 if(!ofs)
  {cerr<<fn1<<' '<<"not open!"<<endl;exit(1);}
 int i;
 //求出T1记录类型的长度
 int b1=sizeof(T1);
 //把文件指针移到文件尾
 ofs.seekp(0, ios::end);
 //求出当前主文件长度
 int flen=ofs.tellp()/b1;
 //把a数组中的n个记录写入到主文件中
 for(i=0; i<n; i++)
   ofs.write((char*) &a[i],b1);
 //关闭逻辑文件ofs
 ofs.close();
 //把a中n个记录的索引项依次插入到索引文件fn2中
 T x;
 for(i=0; i<n; i++) {
  x.key=a[i].key;
  x.next=flen+i;
  IFInsert(fn2,x);}
}
//从物理文件名为fn1指针所指主文件中删除n个记录
template<class T,class T1>
void InFile<T,T1>::MFDelete(char* fn1,char* fn2,KeyType a[],int n)
{//定义一个输入输出文件流对象fio,与主文件相联系
 fstream fio(fn1,ios::in|ios::out|ios::binary);
 if(!fio)
  {cerr<<fn1<<' '<<"not open!"<<endl;exit(1);}
 int b1=sizeof(T1);
 T x;
 T1 y;
 int i;
 //依次删除每条记录
  for(i=0; i<n; i++) {
    x.key=a[i];
    bool k=IFDelete(fn2,x);
    if(!k)
     {cout<<"关键字为"<<x.key<<"的记录不存在"<<endl;continue;}
    fio.seekg(x.next*b1);
    fio.read((char*) &y, b1);
    y.key=DMark;
    fio.seekg(-b1, ios::cur);
    fio.write((char*) &y, b1);
    cout<<"关键字为"<<x.key<<"的记录被删除"<<endl;}
    fio.close();
}
//从物理文件名为fn1指针所指主文件中查找n个记录
template<class T,class T1>
void InFile<T,T1>::MFSearch(char* fn1,char* fn2,KeyType a[],int n)
{//定义一个输入输出文件流对象ifs,与主文件相联系
 ifstream ifs(fn1,ios::in|ios::binary);
 if(!ifs)
  {cerr<<fn1<<' '<<"not open!"<<endl;exit(1);}
 int b1=sizeof(T1);
 T x;
 T1 y;
 int i;
 //依次查找每条记录
 for(i=0; i<n; i++) {
   x.key=a[i];
   bool k=IFSearch(fn2,x);
   if(!k)
    {cout<<"查找关键字为"<<x.key<<"的记录失败!"<<endl;continue;}
   ifs.seekg(x.next*b1);
   ifs.read((char*) &y, b1);
   cout<<"查找关键字为"<<x.key<<"的记录成功!"<<endl;
   cout<<"该记录内容为:"<<y.key<<' '<<y.rest<<endl;}
 ifs.close();
}
//把一个记录的索引项插入到有序数组A中
template<class T,class T1>
void InFile<T,T1>::SeqInsert(T A[],int mm,T x)
{int i;
 for(i=mm-1;i>=0;i--)
  {//从尾部向前为寻找插入位置进行顺序比较和移动
   if(A[i].key>x.key) A[i+1]=A[i];
   else {A[i+1]=x; break;}}
 if(i<0) A[0]=x;
}
//向由fn2指针所表示的索引有序文件中插入x索引项
template<class T,class T1>
void InFile<T,T1>::IFInsert(char *fn2, T x)
{//以输入方式打开由fn2指针所表示的索引有序文件
 fstream ifs(fn2,ios::in|ios::binary);
 if(!ifs)
  {cerr<<fn2<<' '<<"not open!"<<endl;exit(1);}
 //以输出方式打开temp文件
 ofstream ofs(".\\temp",ios::out|ios::binary);
 if(!ofs)
  {cerr<<"temp"<<' '<<"not open!"<<endl;exit(1);}
 //动态定义一个具有m+1个元素的数组A
 T* A=new T[m+1];
 //将原文件指针指向文件开始位置，此语句可省略
 ifs.seekg(0);
 //通过while循环完成插入操作
 int b2=sizeof(T);
 while(1)
  {ifs.read((char*)A, m*b2);
   int s=ifs.gcount()/b2;
   //读入数组A的实际索引项数被存入s中
   if(s==m)
    {if(A[m-1].key<x.key) {
      ofs.write((char*)A,m*b2);}
     else {
      SeqInsert(A, m, x);//将x索引项插入到有序数组A中
      ofs.write((char*)A,(m+1)*b2);
      while(!ifs.eof())
      { //把原文件中剩余的所有记录写入到结果文件中
       ifs.read((char*)A, m*b2);
       s=ifs.gcount()/b2;
       ofs.write((char*)A, s*b2);}
     break;  //退出while(1)循环
   }}
   else
     {SeqInsert(A, s, x);
      ofs.write((char*)A, (s+1)*b2);
      break;//处理完最后一个数据块时退出while(1)循环
   }}
   delete [] A;
   ifs.close();
   ofs.close();
   remove(fn2);
   rename("temp",fn2);
}
//从有序数组A中删除一个关键字为x.key的索引项
template<class T,class T1>
bool InFile<T,T1>::SeqDelete(T A[], int mm, T& x)
{//从数组A的首元素开始顺序查找关键字为x.key的索引项
 int i=0;
 while(i<mm && A[i].key<x.key) i++;
 //若不存在待删除的索引项则返回假
 if(i==mm || A[i].key!=x.key) return false;
 //被删除的索引项赋给x带回
 x=A[i];
 //使i+1至mm-1的所有元素前移一个位置
 for(int j=i+1; j<mm; j++) A[j-1]=A[j];
 //返回真表示删除成功
 return true;
}
//从由fn2指针所表示的索引有序文件中删除
//关键字为x.key的索引项,并由x带回被删除的索引项
template<class T,class T1>
bool InFile<T,T1>::IFDelete(char *fn2, T& x)
{//以输入方式打开由fn2指针所表示的索引有序文件
 ifstream ifs(fn2, ios::in|ios::binary);
 if(!ifs) {
   cerr<<fn2<<' '<<"not found!"<<endl;exit(1);}
 //以输出方式打开temp文件
 ofstream ofs("temp",ios::out|ios::binary);
 if(!ofs) {
   cerr<<"temp"<<' '<<"not open!"<<endl;exit(1);}
 int b2=sizeof(T);
 //动态定义一个具有m个元素的数组A
 T* A=new T[m];
 //用d等于true或false表示删除是否成功
 bool d;
 //通过while完成删除操作
 while(1)
  {ifs.read((char*)A, m*b2);
   int s=ifs.gcount()/b2;
   //读入数组A的实际索引项数被存入s中
   if(s==m)
   {if(A[m-1].key<x.key) {
     ofs.write((char*)A, m*b2);}
    else {d=SeqDelete(A, m, x);
     if(d) ofs.write((char*)A,(m-1)*b2);
     else ofs.write((char*)A,m*b2);
  while(!ifs.eof())
   { //把原文件中剩余的所有记录写入到结果文件中
    ifs.read((char*)A, m*b2);
    s=ifs.gcount()/b2;
    ofs.write((char*)A, s*b2);}
    break;  //退出while(1)循环
   }}
   else
   {d=SeqDelete(A, s, x);
    if(d)
     ofs.write((char*)A, (s-1)*b2);
    else
     ofs.write((char*)A,s*b2);
    break;//处理完最后一个数据块时退出while(1)循环
 }}
 delete [] A;
 ifs.close();
 ofs.close();
 remove(fn2);
 rename("temp", fn2);
 if(d) return true; else return false;
}
//从由fn2指针所表示的索引有序文件中
//查找关键字为x.key的索引项并由x带回
template<class T,class T1>
bool InFile<T,T1>::IFSearch(char* fn2, T& x)
{ifstream ifs(fn2,ios::in|ios::binary);
 //以输入方式打开由fn2指针所表示的索引有序文件
 if(!ifs)
  {cerr<<fn2<<' '<<"not found!"<<endl;exit(1);}
 ifs.seekg(0,ios::end);
 int b2=sizeof(T);
 int n=ifs.tellg()/b2;
 ifs.seekg(0);
 int low=0, high=n-1;
 while(low<=high)
   { //计算区间中点元素的下标
    int mid=(low+high)/2;
    //从文件中读入区间中点元素并赋给tm
    T tm;
    ifs.seekg(mid*b2);
    ifs.read((char*)&tm,b2);
    //查找成功后由x带回查找到的索引项并返回真
    if(x.key==tm.key) {x=tm;
     ifs.close();
     return true;}
    //在左子表中继续查找
    else if(x.key<tm.key)
      high=mid-1;
    //在右子表中继续查找
    else  low=mid+1;}
    ifs.close();
    return false;}//查找失败返回假

