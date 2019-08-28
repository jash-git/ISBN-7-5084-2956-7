//��������ʵ��guangyi.cpp
//������elemָʾ�ı�Ԫ�ص�ֵ
GList &GList::Info(GList *&elem)
{static GList *pitem=new GList;
 pitem->utype=elem->utype;
 if(elem->utype==LST)
  pitem->hlink=elem->hlink;
 if(elem->utype==INTGR)
  pitem->intinfo=elem->intinfo;
 if(elem->utype==CH&&elem->charinfo!=')')
  pitem->charinfo=elem->charinfo;
 pitem->first=elem->first;
 return *pitem;
}
//����elemָʾ�ı�Ԫ�ص�ֵ�޸�Ϊx
GList &GList::setInfo(GList *&elem,GList &x)
{elem->utype=x.utype;
 if(x.utype==INTGR)
  elem->intinfo=elem->intinfo;
 if(x.utype==CH&&x.charinfo!=')')
  elem->charinfo=x.charinfo;
 return *elem;
}
//������lsָʾ�Ĺ����ĵ�һ��Ԫ�ص�ֵ
GList &GList::Head(GList *&ls)
{static GList *temp;
 if(ls==NULL)
  {cout<<"Illegal head operation.\n";exit(1);}
 else {
  temp=new GList;
  ls=ls->first;
  temp=ls;
  if(ls->utype==INTGR)
    temp->intinfo=ls->intinfo;
  if(ls->utype==CH)
    temp->charinfo=ls->charinfo;}
 temp->first=ls;
 return *temp;
}
//���ع�������һ��Ԫ����������Ԫ����ɵı�
GList *GList::Tail()
{if(first==NULL)
  {cout<<"Illegal head operation.\n";exit(1);}
 return first->first;
}
//���ع����ĵ�һ��Ԫ��
GList *GList::First()
{if(hlink==NULL) return NULL;
 else return hlink;
}
//������elemָʾ�ı�Ԫ�ص�ֱ�Ӻ��Ԫ��
GList *GList::Next(GList *elem)
{if(elem->first==NULL) return NULL;
 else return elem->first;
}
//����Ԫ��x��Ϊ��lsָʾ�Ĺ����ĵ�һԪ��
GList *GList::InsertGL(GList *&ls,GList &x)
{if(ls->hlink==NULL) ls->hlink=&x;
 else {
   static GList *temp=new GList;
   temp->utype=x.utype;
   temp->first=ls->first;
   temp->intinfo=x.intinfo;
   ls->hlink=temp;
   ls->first=temp;}
 return ls;  
}
//����һ����xΪͷ,��lsָʾ�Ĺ����Ϊβ���±�
GList *GList::Addon(GList *ls,GList &x)
{static GList *p=new GList;
 p->utype=x.utype;
 if(x.utype==INTGR) p->intinfo=x.intinfo;
 if(x.utype==CH) p->charinfo=x.charinfo;
 p->first=Copy(ls);
 ls=p;
 return ls;
}
//��������ͷԪ������Ϊx
void GList::setHead(GList *&ls,GList &x)
{static GList *temp=new GList;
 temp->utype=x.utype;
 if(x.utype==INTGR) temp->intinfo=x.intinfo;
 if(x.utype==CH&&x.charinfo!=')') temp->charinfo=x.charinfo;
 temp->first=ls->first->first;
 ls->first=temp;
 ls->hlink=temp;
}
//��elem2�嵽����Ԫ��elem1��
void GList::setNext(GList *elem1,GList *elem2)
{GList *temp;
 while(elem1->first!=NULL)
 {temp=elem1->first;
  elem2->first=temp->first;
  delete temp;}
 elem1->first=elem2;
}
//��x����Ϊ��lsָʾ�Ĺ�����β
void GList::setTail(GList *&ls,GList &x)
{static GList *r,*q,*p,*temp=new GList;
 temp->utype=x.utype;
 if(x.utype==INTGR) temp->intinfo=x.intinfo;
 if(x.utype==CH&&x.charinfo!=')') temp->charinfo=x.charinfo;
 r=ls;
 while(!(r->charinfo!=')'&&r->first->first->first==NULL))
  {p=r->first;r=r->first;}
 q=p->first;
 p->first=temp;
 temp->first=q;
}
//��lsָʾ�Ĺ����ĸ���
GList *GList::Copy(GList *ls)
{static GList *gh,*q,*p=new GList;
 q=p;
 if(ls)
  do {
   gh=new GList;
   p->utype=ls->utype;
   switch(ls->utype)
   {case INTGR:p->intinfo=ls->intinfo;break;
    case CH:p->charinfo=ls->charinfo;break;
    case LST:p->hlink=ls->hlink;break;
   }
   p->first=ls->first;
   ls=ls->first;
   p=gh;
  }while(ls->first!=NULL);
 p->first=NULL; 
 return q;
}
//����lsָʾ�ķǵݹ������
int GList::depth(GList *&ls)
{GList *temp=ls;
 int m=0;
 if(temp->first==NULL) return 0;
 do
 {if(temp->utype==LST) m++;
   temp=temp->first;
 }while(temp!=NULL);
 return m;
}
//�жϹ�����Ƿ���ȵ����غ���
int GList::operator ==(GList &m)
{int k=equal(first,m.first);
 return k;
}
//�жϹ�����Ƿ����
int GList::equal(GList *s,GList *t)
{int x;
 if(s->first==NULL&&t->first==NULL) return 1;
 if(s->first==NULL&&t->first==NULL&&
  s->first->utype==t->first->utype)
 {if(s->first->utype==INTGR)
   if(s->first->intinfo==t->first->intinfo) x=1;
   else x=0;
  else if(s->first->utype==CH)
   if(s->first->charinfo==t->first->charinfo) x=1;
   else x=0;
  else x=equal(s->first->first,t->first->first);
  if(x) return equal(s->first,t->first);
 }
 return 0;
}
//ɾ��������к���x����x�Ĳ���
GList *GList::delvalue(GList *&ls,int x)
{static GList *r,*p,*q=ls;
 p=ls;
 while(ls!=NULL)
 {p=ls->first;
  while(p!=NULL&&p->utype==INTGR&&p->intinfo==x)
   {r=p->first;
    delete p;
    p=r;break;}
  if(p==r){ls->first=r;break;}
  ls=ls->first;
 }
 return q;
}
//ɾ��������к���x����x�Ĳ���
GList *GList::delvalue(GList *&ls,char x)
{static GList *r,*p,*q=ls;
 p=ls;
 while(ls!=NULL)
 {p=ls->first;
  while(p!=NULL&&p->utype==CH&&p->charinfo==x)
   {r=p->first;
    delete p;
    p=r;break;}
  if(p==r){ls->first=r;break;}
  ls=ls->first;
 }
 return q;
}
//S�ǹ�������д��ʽ��,��S���������GL
GList *GList::CreateGList(char *&s)
{GList *r,*q,*p;
 p=q=new GList;
 p->first=NULL;
 char *sub=new char[30];
 char *hsub=new char[30];
 for(int i=0;i<30;i++) hsub[i]=sub[i]='\0';
 strncpy(sub,s,strlen(s));
 sub[strlen(s)]='\0';
 cout<<"�������Ĺ����="<<s<<endl;
 cout<<"�����ĳ���="<<strlen(s)<<endl;
 if(strlen(sub)==0||!strcmp(sub,"()")) p->first=NULL;
 else
 {do
  {sever(sub,hsub);
   if(strlen(hsub)==1)
    {if(48<=hsub[0]&&hsub[0]<=57)
      {r=new GList;r->first=NULL;
       p->utype=INTGR;p->intinfo=atoi(hsub);
       p->first=r;p=r;}
     else
     {if((65<=hsub[0]&&hsub[0]<91)||(hsub[0]>=97&&hsub[0]<123)||hsub[0]==')')
       {r=new GList;r->first=NULL;
        p->utype=CH;p->charinfo=hsub[0];
        p->first=r;p=r;}
      else
      {if(hsub[0]=='(')
        {r=new GList;r->first=NULL;
         p->utype=LST;p->hlink=r;
         p->first=r;p=r;
   }}}}
  }while(*sub!='\0');
  p->first=NULL;
 }
 return q;
}
//���������ʱ���õĹ���
int GList::sever(char *&str1,char *&hstr1)
{char ch;int i=0,k=0,j=0;
 int n=strlen(str1);
 static int m=1;
 if(m==1)
  while(j<n||k!=0)
  {ch=str1[j];j++;m++;
   if(ch=='\0') break;
   if(ch=='(') k++;
   else if(ch==')') k--;}
 if(k!=0) return 0;
 for(i=0;i<n;++i)
 {ch=str1[i];
  if(ch=='\0') break;
  if(ch==',')
   {for(int i0=i;i0<n;i0++)
     str1[i0]=str1[i0+1];
    break;}}
 if(n>1) {
  strncpy(hstr1,str1,1);
  strncpy(str1,str1+1,n-1);str1[n-1]='\0';
  return 1;}
 else if(n==1)
   {strncpy(hstr1,str1,1);
    str1[0]='\0';return 1;}
 else return 0;  
}
//���������
void GList::prtGlist(GList *h)
{GList *q,*p=h;
 if(h)
  do
  {if(p->utype==INTGR)
    {q=p->first;
     if(q->charinfo==')'||q->first==NULL)
      cout<<p->intinfo;
     else cout<<p->intinfo<<',';
     p=p->first;}
   else
    {if(p->utype==CH)
      {q=p->first;
       if(q->charinfo==')'||q->first==NULL)
        cout<<p->charinfo;
       else cout<<p->charinfo<<',';
       p=p->first;}
     else
      if(p->utype==LST)
       {cout<<'(';p=p->first;}
    }
 }while(p->first!=NULL);
}

