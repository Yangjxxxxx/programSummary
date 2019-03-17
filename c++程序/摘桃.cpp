#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int ans=n; 
	for(int i=1;i<m;++i)
	{
		n=2*n+1;
		ans=ans+n;
	}
	cout<<ans;
	return 0;
} 
