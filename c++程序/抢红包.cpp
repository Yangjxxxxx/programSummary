#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct answer{
	int id;
	int num;
	double sum;
};
bool cmp1(answer a,answer b)
{
	if(a.sum!=b.sum)
	return a.sum>b.sum;
	else if(a.num!=b.num)
	return a.num>b.num;
	else 
	return a.id<b.id;
}
int main(void)
{
	int n;
	cin>>n;
	vector<answer> ans(n+1);
	for(int i=0;i<n+1;i++)
	{
		ans[i].id=i;
		ans[i].num=0;
		ans[i].sum=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k,n,sum=0;
		cin>>k;
		double p[k];
		for(int j=0;j<k;j++)
		{
			cin>>n>>p[j];
			sum+=p[j];
			ans[n].num++;
			ans[n].sum+=p[j];
		}
		ans[i].sum-=sum;
	}
	sort(ans.begin()+1,ans.end(),cmp1);
	for(int i=1;i<=n;i++)
		printf("%d %.2lf\n",ans[i].id,ans[i].sum/100);
}
