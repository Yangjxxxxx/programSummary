#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long int n,len;
	while(cin>>n>>len){
	queue<long long int> q;
	long long int sum=0;
	long long int ans=200001*n;
	for(int i=0;i<n;i++)
	{
		long long int temp;
		cin>>temp;
		sum+=temp;
		q.push(temp);
		if(q.size()==len){
			if(sum<ans)
			ans=sum;
			sum=sum-q.front();
			q.pop();
		}
	}
	cout<<ans<<endl;}
	return 0;
} 
