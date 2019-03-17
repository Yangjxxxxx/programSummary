#include<iostream>
#include <iomanip>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	char a[n];
	float b[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int k=0;k<n;k++)
	{
			if(a[k]=='M')
		{
			cout<<setiosflags(ios::fixed)<<setprecision(2)<<b[k]/1.09<<endl;
		}
		else if(a[k]=='F')
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<b[k]*1.09<<endl;
	}
}
