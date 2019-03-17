#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,s,d;
int path[502];
void prev(int v)
{
	if(v==s)
	{
		cout<<s;
		return;
	}
	prev(path[v]);
	printf(" %d",v);
}
int main(void)
{
	cin>>n>>m>>s>>d;
	int dis[n][n];
	fill(dis[0],dis[0]+n*n,503);
    vector<int> weight;
	vector<int> num(n,0);
	vector<int> w(n,0);
	vector<int> di(n,503);
    vector<bool> S(n,false);  
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		weight.push_back(a);
	}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		dis[a][b]=c;
		dis[b][a]=c;
	}
	di[s]=0;
	num[s]=1;
	w[s]=weight[s];
	path[s]=s;
	di[s]=0;
	for(int i=0;i<n;i++)
	{
		int k=-1,min=503;
		for(int q=0;q<n;q++)
		{
			if(S[q]==false&&di[q]<min)
			{
				k=q;
				min=di[q];
			}
		}
		if(k==-1)
		break;
		S[k]=true;
		for(int q=0;q<n;q++)
		{
			if(S[q]==false&&min+dis[k][q]<di[q])
			{
				di[q]=min+dis[s][q];
				num[q]=num[k];
				w[q]=weight[q]+w[k];
				path[q]=k;
			}
			else if(S[q]==false&&min+dis[k][q]==di[q])
			{
				num[q]=num[k]+num[q];
				if(w[k]+weight[q]>w[q])
				{
					w[q]=w[k]+weight[q];
					path[q]=k;
				}
			}
		}
	} 
	cout<<num[d]<<" "<<w[d]<<endl;
	prev(d);
}
