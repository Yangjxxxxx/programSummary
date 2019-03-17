#include<iostream>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	int a[1001];
	for(int i=0;i<1001;i++)
	{
		a[i]=0;
	}
	for(int i=0;i<n;i++)
	{
	    int _n;
	    cin>>_n;
	    int b[_n];
	    for(int j=0;j<_n;j++)
	    {
	    	cin>>b[j];
	    	a[b[j]]++;
		}
	}
	int temp=a[1000];
	int c=1000;
	for(int k=1000;k>=0;k--)
	{
		if(temp<a[k])
		{
			temp=a[k];
			c=k;
		}
		else
		continue;
	}
	cout<<c<<" "<<temp;
}
