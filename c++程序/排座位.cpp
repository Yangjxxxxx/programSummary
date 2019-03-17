#include<iostream>
#include<vector>
#include<string>
using namespace std;
int re[101][101];
int guanxi[101];
int _find(int s)
{
	while(guanxi[s]!=s)
	s=guanxi[s];
	return s;
}
void pre(int p,int q)
{
	int fp=_find(p);
	int fq=_find(q);
	if(fp<fq)
	guanxi[fq]=fp;
	else if(fp>fq)
	guanxi[fp]=fq; 
}
int main(void)
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<101;i++)
	guanxi[i]=i;
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<101;j++)
		{
			if(i==j)
			re[i][j]=1;
			else
			re[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		int p,q,t;
		cin>>p>>q>>t;
		re[p][q]=t;
		re[q][p]=t;
		if(t==1)
		pre(p,q);
	}
	vector<string> ans;
	for(int i=0;i<k;i++)
	{
		int m1,m2;
		cin>>m1>>m2;
		if(re[m1][m2]==-1)
		{
			if(_find(m1)==_find(m2))
			ans.push_back("OK but...");
			else
			ans.push_back("No way");
		}
		else if(re[m1][m2]==0)
		{
			if(_find(m1)==_find(m2))
			ans.push_back("No problem");
			else
			ans.push_back("OK");
		}
		else if(re[m1][m2]==1)
		{
			ans.push_back("No problem");
		}
	}
	for(vector<string>::iterator it=ans.begin();it!=ans.end();it++)
	cout<<*it<<endl;
} 
