//�����׺���ʽֵ���ļ�Evaluate.cpp
const int SM=40;
#include"linearStack2.cpp"
float Evaluate(char* str)
//������str�ַ�������ʾ�ĺ�׺���ʽ��ֵ,
//���ʽҪ��'@'�ַ�����.
{LinStack S;//��������S
 S.InitStack(SM);//��ʼ��ջ
 istrstream ins(str);//��str����Ϊ�����ַ���������ins
 char ch;            //���������ַ�
 float x;   //�������븡����
 ins>>ch;   //��ins������(��str�ַ���)��˳�����һ���ַ�
 while(ch!='@')
  {//ɨ��ÿһ���ַ���������Ӧ����
   switch(ch)
    {case '+':x=S.Pop()+S.Pop();break;
     case '-':x=S.Pop();   // Pop(S)��������
	      x=S.Pop()-x; //Pop(S)�������Ǳ�����
	      break;
     case '*':x=S.Pop()*S.Pop();break;
     case '/':x=S.Pop();   // Pop(S)��������
	      if(x!=0.0)
	       x=S.Pop()/x;//Pop(S)�������Ǳ�����
	      else { //����Ϊ0ʱ��ֹ����
		cerr<<"����Ϊ0!"<<endl;exit(1);}
	        break;
     default://����ı�Ϊһ�������������λ����
     ins.putback(ch); //�������»��͵���������
     ins>>x;} //���ַ����������ж���һ��������
   //�Ѷ����һ���������������Ӧ����Ľ��ѹ�뵽Sջ��
   S.Push(x);
   ins>>ch; //������һ���ַ�,�Ա������һ��ѭ������
  }
  if(!S.StackEmpty())
   {//��ջ�н���һ��Ԫ��,�����Ǻ�׺���ʽ��ֵ,����Ϊ����
    x=S.Pop();
    if(S.StackEmpty()) return x;
    else {cerr<<"���ʽ����!"<<endl;exit(1);}
   }
  else {//�����ջΪ��,����ֹ����
    cerr<<"ջΪ��!"<<endl;exit(1);}
return x;}

