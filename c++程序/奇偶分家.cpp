#include<iostream>
using namespace std;
int main()
{
	int n,q=0,o=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	for (int j=0;j<n;j++)
	{
		if(a[j]%2==0)
		q++;
		else
		o++;
	}
	cout<<o<<" "<<q;
	return 0;
}
