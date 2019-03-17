#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	vector<set<long long int> > num;
	set<long long int> _a;
	num.push_back(_a);
	for(int i=1;i<=n;i++)
	{
		int temp;
		set<long long int> t;
		cin>>temp;
		for(int j=0;j<temp;j++)
		{
			int a;
			cin>>a;
			t.insert(a);
		}
		num.push_back(t);
	}
	int m;
	cin>>m;
	vector<double> answer;
	for(int i=0;i<m;i++)
	{
		int m1,m2,nc=0;
		cin>>m1>>m2;
		int s1=num[m1].size();
		int s2=num[m2].size();
		set<long long int>::iterator it=num[m1].begin();
		while(it!=num[m1].end())
		{
			if(num[m2].find(*it)!=num[m2].end())
			nc++;
			it++;
		}
		set<long long int> sum(num[m1]);
		set<long long int>::iterator it2=num[m2].begin();
		while(it2!=num[m2].end())
		{
			sum.insert(*it2);
			it2++;
		}
		int nt=sum.size();
		double ans=(double)nc/(double)nt;
		ans*=100;
		answer.push_back(ans);
	}
	for(int i=0;i<m;i++)
	{
		printf("%.2lf",answer[i]);
		cout<<"%"<<endl;
	}
}
