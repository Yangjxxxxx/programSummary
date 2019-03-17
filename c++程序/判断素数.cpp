#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	unsigned int n,k;
	cin>>n;
	unsigned int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=sqrt(a[i]);
	}
	for(int j=0;j<n;j++)
	{
		for(k=2;k<=b[j];k++)
		{
			if(a[j]%k==0)
			break;
		}
		if(a[j]==1)
		cout<<"No"<<endl;
		else if(k>b[j])
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;;
	}
	return 0;
}
