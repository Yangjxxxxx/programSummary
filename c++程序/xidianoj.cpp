#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct node{
	int id;
	int cnt=0;
};
int n,num=0;
int father[5000];
int finds(int x)
{
	while(x!=father[x])
	x=father[x];
	return x;
}
void Union(int a,int b)
{
	int fa=finds(a);
	int fb=finds(b);
	if(fa>fb)
	father[a]=b;
	else if(fa<fb)
	father[b]=a;
}
bool cmp1(node a,node b)
{
	if(a.cnt!=b.cnt)
	return a.cnt>b.cnt;
	else 
	return a.id<b.id;
}
bool cmp2(int a[26],int b[26])
{
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		if(a[i]==b[i])
		cnt++;
	}
	if(cnt==26)
	return true;
	else
	return false;
}
bool cmp(string a,string b)
{
	int a1[26]={0};
	int b1[26]={0};
	set<char> _a;
	set<char> _b; 
	for(int i=0;i<a.size();i++)
	{
	_a.insert(a[i]);
	a1[a[i]-97]++;}
	for(int i=0;i<b.size();i++)
	{
	_b.insert(b[i]);
	b1[b[i]-97]++;}
	if(_a==_b&&a.size()==b.size()&&cmp2(a1,b1))
	return true;
	else
	return false;
}
bool cmp3(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	while(cin>>n){
	vector<bool> vis(n,false);
	vector<node> tag(n);
	int index[n];
	string str[n];
	for(int i=0;i<n;i++)
	{
		tag[i].id=i;
		father[i]=i;
		cin>>str[i];
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i])
		continue;
		vis[i]=true;
		for(int j=i+1;j<n;j++)
		{
			if(cmp(str[i],str[j]))
			{
				vis[j]=true;
				Union(i,j);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		tag[finds(i)].cnt++;
		index[i]=finds(i);
		if(tag[i].cnt>0)
		num++;
	}
	sort(tag.begin(),tag.end(),cmp1);
	int k=0;
	for(;k<n;k++)
	{
		if(tag[k].cnt==0)
		break;
	}
	tag.erase(tag.begin()+k,tag.end());
	sort(tag.begin(),tag.end(),cmp3);
	for(int i=0;i<num;i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(index[j]==tag[i].id)
			{
				if(flag==0)
				{
					cout<<str[j];
					flag=1;
				}
				else
				cout<<" "<<str[j];
			}
		}
		cout<<endl;
	}}
	return 0;
}
