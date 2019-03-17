#include<iostream>
#include<string>
#include<fstream> 
using namespace std;
void showmenu();
class stu
{
		long long int num;
		string name;
	public:
		stu(){}
		void _stu(long long int nnum,string nname)
		{
			num=nnum;
			name=nname;
		}
		long long int getnum()
		{
			return num;
		}
		string getname()
		{
			return name;
		}
		friend class list;
};
struct student
{
	stu data;
	student* next;
};
class list
{
	student* head;
	public:
	friend class stu;
	list(){head=NULL;}
	void insertlist();    //���뺯����δ���βΡ�  ��� 
	void deletelist();   //������ɾ��������δ���βΡ�             ��� 
	void outputlist();    //�����ӡ��δ���βΡ�                      ��� 
	void searchlist();   //��ѯ������δ���β�     ���
	void loadlist();     //�����ļ�   ��� 
	student* gethead() 
	{
		return head;
	 } 
}; 
void list::outputlist()
{
	student* current=head;
	if(head==NULL)
	{
		cout<<"û��ѧ����Ϣ"<<endl;
	}
	int count=0;
    int i,j,k,n;
    while(current!=NULL)
    {
      current=current->next;
      count++;
    }
    student *q;
    q=head;
    stu *pt=new stu[count];
    for(k=0;k<count;k++)
    {
     pt[k]._stu(q->data.getnum(),q->data.getname());    
     q=q->next;
    }  
    for(i=1;i<count;i++)               //ð�� 
    {
    for(j=0;j<count-i;j++)
    {
     long long int a;
     string b;
      if(pt[j+1].getnum()<pt[j].getnum())
      {   a=pt[j+1].getnum();
          b=pt[j+1].getname();
          pt[j+1]._stu(pt[j].getnum(),pt[j].getname());
          pt[j]._stu(a,b);
       }
      continue;  
    }
    }
    for(n=0;n<count;n++)
    {
        cout<<pt[n].getnum()<<" "<<pt[n].getname()<<endl;
    }  
}
void list::insertlist()    //���a֮ǰ����b 
{
	long long int anum,bnum;
	string bname;
	cout<<"������Ҫ�����λ�ã�"<<endl;
	cin>>anum;
	cout<<"������Ҫ�����ѧ�ź�������"<<endl;
	cin>>bnum;
	cin>>bname;
	student *p,*q,*s,*a,*b;
	s=(student*)new(student);
	s->data._stu(bnum,bname);
	p=head;
	if(head==NULL)   //����ǰ������һ���ձ� 
	{
		head=s;
		s->next=NULL;
	}
	else if(p->data.getnum()==anum)     // a������ĵ�һ���ڵ㣬�����bΪ��һ���ڵ� 
	{
		s->next=p;
		head=s;
	}
	else                              //����ǰa���ǵ�һ����㣬�����ҳ�a����һ�����a-1��Ȼ����a-1��ָ����ָ��b��b��ָ����ָ��a 
	{
		while(p->data.getnum()!=anum&&p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		if(p->data.getnum()==anum)
		{
			q->next=s;
			s->next=p;
		}
		else     //�������в�����a�㣬�������� 
		{
			p->next=s;
			s->next=NULL; 
		}
	}
	cout<<"�����"<<endl;
	a=head;
	while(a!=NULL)
	{
		cout<<a->data.getnum()<<" "<<a->data.getname()<<endl;
		b=a;
		a=b->next;
	}
}
void list::loadlist()
{
	ifstream fin("D:\\110��Ϣ.txt");
	while(!fin.eof())
	{
		long long int tnum;
		string tname;
		student *q,*p;
		if (head==NULL)
		{
			p=new student();
			fin>>tnum;
			fin>>tname;
			p->data._stu(tnum,tname);
			head=p;
			head->next=NULL;
		}
		else
		{
			q=head;
			p=new student();
			fin>>tnum;
			fin>>tname;
			p->data._stu(tnum,tname);
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=p;
			p->next=NULL;
		}
	}
}
void list::deletelist()    //ɾ�����a 
{
	long long int dnum;
	cout<<"������Ҫɾ��ѧ����ѧ�ţ�"<<endl;
	cin>>dnum;
	student *p,*q; 
	p=head;
	if(p==NULL)
	return;
	if(p->data.num==dnum)    //��a�ǵ�һ����� 
	{
		head=p->next;
		delete p;
	}
	else     //��a���ǵ�һ����� 
	{
		while(p->data.num!=dnum&&p->next!=NULL)      //���ҽ��a��a�������һ����� 
		{
			q=p;
			p=p->next;
		}
		if(p->data.num==dnum)     //��a������
		{
		q->next=p->next;
		delete p;
		} 
	}
}
void list::searchlist()          //��ѯ���a 
{
	cout<<"������Ҫ��ѯ��ѧ�ţ�"<<endl;
	long long int anum;
	cin>>anum;
	student *p;    //pָ��a��qָ��a��ǰһ�����
	p=head;
	if(p==NULL)
	return;
	else
	{
		while(p->data.getnum()!=anum&&p->next!=NULL)
			p=p->next;
		if(p->data.getnum()==anum)
		cout<<p->data.getname()<<endl;
		else 
		cout<<"�޸�ѧ����Ϣ"<<endl;
	}
}
int main()
{
	showmenu();
	list A;
	int choice;
	cin>>choice;
	while(choice>0&&choice<6)
	{
		switch(choice)
		{
			case 1 : {			
			         A.searchlist();
					 break;
					 }                 //��ѯѧ��a_num
			case 2 : {
			         A.insertlist();
			         break;
					 }            //��a֮ǰ����b
			case 3 : {
			          A.loadlist();
		              break;
	                  }                         //��ȡ�ļ�����������
			case 4 : {
	                 A.deletelist(); 
					 break;
					 }             //ɾ����Ϣ 
			case 5 : A.outputlist();break;                    //�����ӡ 
		}
		showmenu();
		cin>>choice;
	 } 
	cout<<"�������"<<endl;
	return 0; 
 } 
 void showmenu()
 {
 	cout<<"*******************************************************************************************"<<endl;
	cout<<"                       ��������˵��Ҫ�Ĳ�����                                              "<<endl;
	cout<<"                       1��ѯ                                                               "<<endl;
	cout<<"                       2����                                                               "<<endl;
	cout<<"                       3¼��                                                               "<<endl;
	cout<<"                       4ɾ��                                                               "<<endl;
	cout<<"                       5�����ӡ                                                           "<<endl;
	cout<<"*******************************************************************************************"<<endl;
 }
 
