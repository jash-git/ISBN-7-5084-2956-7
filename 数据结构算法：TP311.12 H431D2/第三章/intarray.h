//����һά,��ά������ඨ��intarray.h
class IntArray1{
    int size;//�������
    int *data;//����ָ��
    void init(int n);
    IntArray1():size(0),data(0){}
    friend class IntArray2;
public:
    //���캯��
    IntArray1(int n){ init(n);}
    //��������
    ~IntArray1(){ delete []data;}
    //�±����������
    //����Ϊ�����Ա�֤�ȿ�ȡֵҲ�ɸ�ֵ
    int &operator[](int i);
    //�������鳤��
    int size1()const{ return size;}
    //���¶�������
    void ReArray(int si);
};
class IntArray2{
    int size;
    IntArray1 *data;
public:
    //���캯��
    IntArray2(int,int);
    //��������
    ~IntArray2(){ delete []data;}
    //�±����������
    //����Ϊ�����Ա�֤�ȿ�ȡֵҲ�ɸ�ֵ
    IntArray1 &operator[](int i);
    //���ض�ά��������
    int size1()const{ return size;}
    //���ض�ά��������
    int size2()const{ return data->size1();}
};


