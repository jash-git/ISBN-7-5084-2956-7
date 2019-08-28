//�������������ʵ��BSTreeF.cpp
//��ʼ��������,��������ָ���ÿ�
template<class T>
void BSTree<T>::InitBSTree(BSTree<T> *&BST)
{BST=NULL;}

//�ж϶������Ƿ�Ϊ��
template<class T>
bool BSTree<T>::BSTreeEmpty(BSTree<T> *&BST)
{return BST==NULL;}

//�Ӷ����������в���Ԫ��
template<class T>
bool BSTree<T>::Find(BSTree<T> *&BST,T item)
{if(BST==NULL) return false;
 else {if(item.grade==BST->data.grade) {
       	item=BST->data;
	return true;}
       	else if(item.grade<BST->data.grade)//�ݹ����������
	  return Find(BST->left,item);
	else                  //�ݹ����������
       return Find(BST->right,item);
}}
//���¶����������еĽ��ֵ
template<class T>
bool BSTree<T>::Update(BSTree<T> *&BST,const T item,T newc)
{if(BST==NULL) return false;
 else {
   if(item.grade==BST->data.grade) {
     Insert(BST,newc);Delete(BST,item);
     return true;}
   else if(item.grade<BST->data.grade)
	  return Update(BST->left,item,newc);
	else
	  return Update(BST->right,item,newc);}
}
//������������в���Ԫ��
template<class T>
void BSTree<T>::Insert(BSTree<T> *&BST,const T &item)
{if(BST==NULL)
  {BSTree<T> *p=new BSTree;
   p->data=item;
   p->left=p->right=NULL;
   BST=p;}
 else if(item.grade<BST->data.grade)
       Insert(BST->left,item);  //���������в���Ԫ��
      else
       Insert(BST->right,item);//���������в���Ԫ��
}
//�Ӷ�����������ɾ��Ԫ��
template<class T>
bool BSTree<T>::Delete(BSTree<T> *&BST,T item)
{//�Ӷ����������в���ֵΪitem�Ľ��,ָ��tָ����ȽϵĽ�㣬
 //ָ��sָ��t��˫�׽��,��������㿪ʼ�Ƚ�
  BSTree<T> *t=BST,*s=NULL;
  while(t!=NULL) {
     if(item.grade==t->data.grade) break;
     else if(item.grade<t->data.grade) {
	  s=t; t=t->left;}
	  else {s=t; t=t->right;}
  }
 //��û���ҵ���ɾ���Ľ�㣬�򷵻ؼ�
  if(t==NULL) return false;
 //�����ֲ�ͬ���ɾ���Ѳ��ҵ���t���
  if(t->left==NULL && t->right==NULL)
   { //��t���(����ɾ���Ľ��)ΪҶ�ӽ���������д���
    if(t==BST) BST=NULL;
    else if(t==s->left) s->left=NULL;
        else  s->right=NULL;
    delete t;}
  else if(t->left==NULL || t->right==NULL)
	{ //��t���Ϊ����֧����������д���
	 if(t==BST) {  //ɾ���������
	 if(t->left==NULL) BST=t->right;
	 else  BST=t->left;}
       else {//ɾ�����������ʱ,������������д���
	 if(t==s->left && t->left!=NULL)
            s->left=t->left;
	 else if(t==s->left && t->right!=NULL)
	         s->left=t->right;
	       else if(t==s->right && t->left!=NULL)
                s->right=t->left;
	 else if(t==s->right && t->right!=NULL)
	        s->right=t->right;}
	 delete t;  //����t���,��tָ����ָ��Ľ��
       }
   else if(t->left!=NULL && t->right!=NULL)
    { //��t���Ϊ˫��֧����������д���
      //p��ʼָ��t���,q��ʼָ��p�����������ĸ����
     BSTree<T> *p=t,*q=t->left;
      //����t��������ǰ����㣬���ҽ�����q���Ϊt���
      //������ǰ�����,p���Ϊq����˫�׽��
     while(q->right!=NULL) {p=q;q=q->right;}
      //q����ֵ����t���
       t->data=q->data;
      //ɾ��������Ϊ�յ�q���,ʹ�������������ӵ������ڵ�����λ��
       if(p==t) t->left=q->left;
       else p->right=q->left;
    //����q���
       delete q;}
  //ɾ�������󷵻���
    return true;
}
//�������齨��һ�ö���������
template<class T>
void BSTree<T>::CreateBSTree(BSTree<T> *&BST,T a[],int n)
{BST=NULL;
 for(int i=0;i<n;i++)
   Insert(BST,a[i]);
}
//���������������������е����н��
template<class T>
void BSTree<T>::Inorder(BSTree<T> *&BST)
{if(BST!=NULL) {
  Inorder(BST->left);
  cout<<BST->data.grade<<' ';
  Inorder(BST->right);}
}
//����������������
template<class T>
int BSTree<T>::BSTreeDepth(BSTree<T> *&BST)
{if(BST==NULL) return 0;//���ڿ���,����0�������ݹ�
 else
  {  //���������������
   int dep1=BSTreeDepth(BST->left);
     //���������������
   int dep2=BSTreeDepth(BST->right);
     //�����������
   if(dep1>dep2) return dep1+1;
   else return dep2+1;}
}
//����������������н����
template<class T>
int BSTree<T>::BSTreeCount(BSTree<T> *&BST)
{if(BST==NULL) return 0;
 else 
  return BSTreeCount(BST->left)+BSTreeCount(BST->right)+1;
}
//�����������������Ҷ�ӽ����
template<class T>
int BSTree<T>::BSTreeLeafCount(BSTree<T> *&BST)
{if(BST==NULL) return 0;
 else if(BST->left==NULL && BST->right==NULL) return 1;
 else return BSTreeLeafCount(BST->left)+BSTreeLeafCount(BST->right);
}
//���ն������Ĺ�����ʾ�������������
template<class T>
void BSTree<T>::PrintBSTree(BSTree<T> *&BST)
{if(BST==NULL) return;  //��Ϊ��ʱ����
 else {//����ִ�����²���
       cout<<BST->data.grade;  //���������ֵ
       if(BST->left!=NULL||BST->right!=NULL)
	   {if(BST->left!=NULL)
		 cout<<'(';  //���������
	    PrintBSTree(BST->left);  //���������
	    if(BST->right!=NULL)
	     cout<<',';  //����������Ϊ����������ŷָ���
        PrintBSTree(BST->right);  //���������
        if(BST->left!=NULL&&BST->right!=NULL)
	     cout<<')';} //���������
}}
//�������������,ʹ֮��Ϊһ�ÿ���
template<class T>
void BSTree<T>::ClearBSTree(BSTree<T> *&BST)
{if(BST!=NULL)
  {//���������ǿ�ʱ�������²���
   ClearBSTree(BST->left);  //ɾ��������
   ClearBSTree(BST->right); //ɾ��������
   delete BST;              //ɾ�������
   BST=NULL;}               //�ø�ָ��Ϊ��
}
//��BST���������������ȸ������Ĵ���洢���ļ�fn��
template<class T>
void BSTree<T>::WriteFile(char* fn, BSTree<T>* BST)
{//����fn��ָ�ַ�����Ϊ�ļ������ļ�����
 //Ϊ����ļ���ofs,���������Ʒ�ʽ��
 ofstream ofs(fn,ios::out|ios::binary);
 if(!ofs) {cout<<"File not open!"<<endl; exit(1);}
  //����PreorderWrite�������ļ��������������
 PreorderWrite(ofs, BST);
  //�ر��ļ�����������Ӧ���ļ�
  ofs.close();}
//��ofs�ļ�������Ӧ���ļ��а��ȸ���������д��
//һ�ö���������BST�ĵݹ��㷨,����WriteFile��������
template<class T>
void BSTree<T>::PreorderWrite(ofstream& ofs,BSTree<T>* BST)
{if(BST!=NULL) {
   ofs.write((char*)BST,sizeof(*BST));
   PreorderWrite(ofs, BST->left);
   PreorderWrite(ofs, BST->right);}
}
//��fn�ļ��а��ȸ������洢�Ķ����������ָ����ڴ���
template<class T>
void BSTree<T>::ReadFile(char* fn, BSTree<T>*& BST)
{//��fn�ļ�����Ϊ�����ļ���ifs�����������Ʒ�ʽ��
 ifstream ifs(fn,ios::in|ios::binary);
 if(!ifs) {cout<<"File not open!"<<endl; exit(1);}
 //���ļ�ָ���Ƶ�����λ��
 ifs.seekg(0,ios::end);
 //���������������ÿ�����Ĵ�С
 int b=sizeof(BSTree);
 //����ļ�������������Ľ����������n
 int n=ifs.tellg()/b;
 //����ļ�Ϊ�գ����BST�ÿպ󷵻�
 if(n==0) {ifs.close(); BST=NULL; return;}
 //���ļ�ָ���Ƶ��ļ���ʼλ��,�Ա��ͷ��ʼ��ȡÿ�����
 ifs.seekg(0);
 //���ļ��еĵ�һ����㹹���������
 BST=new BSTree<T>;
 ifs.read((char*)BST, b);
 cout<<setw(4)<<BST->data.grade;
 //�ֱ���ļ��ж�ȡ��������
 PreorderRead(ifs, BST->left, b);
 PreorderRead(ifs, BST->right, b);
 //�ر�ifs��Ӧ�Ĵ����ļ�
 ifs.close();}
//��ifs�ļ�������Ӧ���ļ��а��ȸ������������
//һ�ö����������ĵݹ��㷨,����ReadFile��������
template<class T>
void BSTree<T>::PreorderRead(ifstream& ifs,BSTree<T>* BST,int& b)
{if(BST!=NULL) {
  BST=new BSTree<T>;
  ifs.read((char*)BST, b);
  cout<<setw(4)<<BST->data.grade;
  PreorderRead(ifs, BST->left, b);
  PreorderRead(ifs, BST->right, b);}
}

