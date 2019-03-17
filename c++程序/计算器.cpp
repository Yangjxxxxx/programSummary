#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int t(string s)
{
	if(s[0]<48||s[0]>57)
	return 0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='/'&&s[i+1]=='0')
		return 0;
	}
	return 1;
}
class Caculate
{
	private:
	string s;
	long answer;
	public:
		Caculate(){
			this->s="";
			this->answer=0;
		};
		~Caculate(){
		};
		void get_s(string exp){
			this->s=exp;
		};
		long getanswer(){
			return this->answer;
		};
		void eval();
};
void Caculate::eval()
{
	map<char,int> sign;
    sign['(']=1;
    sign[')']=1;
    sign['+']=2;
    sign['-']=2;
    sign['*']=3;
    sign['/']=3;
    string signs="()+-*/";
	stack<string> a;
	stack<char> b;
	while(this->s.size()>0)
	{
		if(signs.find(this->s[0])!=string::npos)
		{
			if(b.empty()||this->s[0]=='('||b.top()=='('||sign[this->s[0]]>sign[b.top()])
			{
				b.push(this->s[0]);
			}
			else if(this->s[0]==')'){
				while(!b.empty())
				{
					if(b.top()!='(')
					{
						string t=" ";
						t[0]=b.top();
						b.pop();
						a.push(t);
					}
					else{
						b.pop();
						break;
					}
				}
			}
			else{
				while(!b.empty()&&sign[this->s[0]]<=sign[b.top()])
				{
					string t=" ";
					t[0]=b.top();
					b.pop();
					a.push(t);
				}
				b.push(this->s[0]);
			}
			this->s.erase(this->s.begin());
		}
		else{
			long x=stoll(this->s);
			string sx=to_string(x);
			int n=sx.size();
			a.push(sx);
			this->s.erase(0,n);
		}
	}
	while(!b.empty())
	{
		string t=" ";
		t[0]=b.top();
		a.push(t);
		b.pop();
	}
	vector<string> op;
	while(!a.empty())
	{
		string t=a.top();
		op.push_back(t);
		a.pop();
	}
	reverse(op.begin(),op.end());
	stack<string> ca;
	int index=2;
	ca.push(op[0]);
	ca.push(op[1]);
	while(index<op.size())
	{
		if(signs.find(op[index][0])!=string::npos){
			string n1=ca.top();
			long n=stoll(n1);
			ca.pop();
			string m1=ca.top();
			long m=stoll(m1);
			ca.pop();
			if(op[index]=="+")
			ca.push(to_string(m+n));
			else if(op[index]=="-")
			ca.push(to_string(m-n));
			else if(op[index]=="*")
			ca.push(to_string(m*n));
			else if(op[index]=="/")
			ca.push(to_string(m/n));
			++index;
		}
		else{
			ca.push(op[index]);
			++index;
		}
	}
	string ans1=ca.top();
	this->answer=stoll(ans1);
}
int main(void)
{
	Caculate ans;
	string exp;
	while(1){
	cout<<"请输入要计算的表达式："<<endl;
	cin>>exp;
    if(t(exp)==0)
    {
    	cout<<"非法输入，请重新输入："<<endl;
	}
	else{
	ans.get_s(exp);
	ans.eval();
	cout<<ans.getanswer()<<endl;
    }
    }
}
