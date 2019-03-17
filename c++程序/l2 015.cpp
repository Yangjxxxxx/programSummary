#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(void)
{
	int n,k,m;
	cin>>n>>k>>m;
	vector<double> ans(n,0);
	for(int i=0;i<n;i++)
	{
		vector<double> score(k);
		double a;
		for(int j=0;j<k;j++)
		{
			cin>>a;
			score[j]=a;
		}
		sort(score.begin(),score.end());
		score.erase(score.begin());
		vector<double>::iterator it=score.end();
		score.erase(it-1);
		for(int j=0;j<k-2;j++)
		ans[i]+=score[j];
		ans[i]/=(k-2);
	}
	sort(ans.begin(),ans.end());
	for(int i=n-m;i<n;i++)
	{
		if(i==n-m)
		printf("%.3lf",ans[i]);
		else
		printf(" %.3lf",ans[i]);
	}
}
 
