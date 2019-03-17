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
	void insertlist();    //插入函数，未带形参。  完成 
	void deletelist();   //链表结点删除函数，未带形参。             完成 
	void outputlist();    //排序打印，未带形参。                      完成 
	void searchlist();   //查询函数，未带形参     完成
	void loadlist();     //加载文件   完成 
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
		cout<<"没有学生信息"<<endl;
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
    for(i=1;i<count;i++)               //冒泡 
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
void list::insertlist()    //结点a之前插入b 
{
	long long int anum,bnum;
	string bname;
	cout<<"请输入要插入的位置："<<endl;
	cin>>anum;
	cout<<"请输入要插入的学号和姓名："<<endl;
	cin>>bnum;
	cin>>bname;
	student *p,*q,*s,*a,*b;
	s=(student*)new(student);
	s->data._stu(bnum,bname);
	p=head;
	if(head==NULL)   //插入前链表是一个空表 
	{
		head=s;
		s->next=NULL;
	}
	else if(p->data.getnum()==anum)     // a是链表的第一个节点，插入后b为第一个节点 
	{
		s->next=p;
		head=s;
	}
	else                              //插入前a不是第一个结点，首先找出a的上一个结点a-1，然后令a-1的指针域指向b，b的指针域指向a 
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
		else     //若链表中不存在a点，则插在最后 
		{
			p->next=s;
			s->next=NULL; 
		}
	}
	cout<<"插入后："<<endl;
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
	ifstream fin("D:\\110信息.txt");
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
void list::deletelist()    //删除结点a 
{
	long long int dnum;
	cout<<"请输入要删除学生的学号："<<endl;
	cin>>dnum;
	student *p,*q; 
	p=head;
	if(p==NULL)
	return;
	if(p->data.num==dnum)    //若a是第一个结点 
	{
		head=p->next;
		delete p;
	}
	else     //若a不是第一个结点 
	{
		while(p->data.num!=dnum&&p->next!=NULL)      //查找结点a，a不是最后一个结点 
		{
			q=p;
			p=p->next;
		}
		if(p->data.num==dnum)     //若a结点存在
		{
		q->next=p->next;
		delete p;
		} 
	}
}
void list::searchlist()          //查询结点a 
{
	cout<<"请输入要查询的学号："<<endl;
	long long int anum;
	cin>>anum;
	student *p;    //p指向a，q指向a的前一个结点
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
		cout<<"无该学生信息"<<endl;
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
					 }                 //查询学号a_num
			case 2 : {
			         A.insertlist();
			         break;
					 }            //在a之前插入b
			case 3 : {
			          A.loadlist();
		              break;
	                  }                         //读取文件并存入链表
			case 4 : {
	                 A.deletelist(); 
					 break;
					 }             //删除信息 
			case 5 : A.outputlist();break;                    //排序打印 
		}
		showmenu();
		cin>>choice;
	 } 
	cout<<"输入错误"<<endl;
	return 0; 
 } 
 void showmenu()
 {
 	cout<<"*******************************************************************************************"<<endl;
	cout<<"                       请输入你说需要的操作：                                              "<<endl;
	cout<<"                       1查询                                                               "<<endl;
	cout<<"                       2插入                                                               "<<endl;
	cout<<"                       3录入                                                               "<<endl;
	cout<<"                       4删除                                                               "<<endl;
	cout<<"                       5排序打印                                                           "<<endl;
	cout<<"*******************************************************************************************"<<endl;
 }
 
