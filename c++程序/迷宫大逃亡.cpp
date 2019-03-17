#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <queue>
using namespace std;
vector<vector<char> > g;
vector<vector<bool> > s;
vector<int> ans;
int n,m,z;
void dfs(int x,int y,int p,int q)
{
	s[x][y]=true;
	if(x==p&&y==q){
	ans[z]=1;
	return;
    }
    if(y+1<n+1&&g[x][y+1]!='X'&&s[x][y+1]==false)
    dfs(x,y+1,p,q);
    if(y-1>0&&g[x][y-1]!='X'&&s[x][y-1]==false)
    dfs(x,y-1,p,q);
    if(x-1>0&&g[x-1][y]!='X'&&s[x-1][y]==false)
    dfs(x-1,y,p,q);
    if(x+1<n+1&&g[x+1][y]!='X'&&s[x+1][y]==false)
    dfs(x+1,y,p,q);
    return;
}
int main(void)
{
	cin>>m;
	for(int i=0;i<m;++i)
	ans.push_back(0);
	for( z=0;z<m;++z){
	char a;
	int x,y,p,q;
	cin>>n;
	cin>>x>>y;
	cin>>p>>q;
	for(int i=0;i<n+1;++i){
	g.push_back(vector<char>('O',n+1));
	s.push_back(vector<bool>(false,n+1));
    }
    for(int i=1;i<n+1;++i)
	for(int j=1;j<n+1;++j){
		cin>>a;
		g[i][j]=a;
		s[i][j]=false;
	}
	dfs(x,y,p,q); }
	for(int i=0;i<m;++i)
	cout<<ans[i];
}
