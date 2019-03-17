#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n1;
	cin>>n1;
	int n=sqrt(n1)+1;
	int count=0;
	int i=2,j=2;
	while(i<n)
	{
		if(n%i==0)
		count++;
		i++;
	}
	int a[count];
	for(int i=0;i<count;i++)
	{
		while(j<n)
		{
			if(n%j==0)
			{
				a[i]=j;
				j++;
				break;
			 } 
			 else 
			 {
			 j++;
			 continue;}        //把每个能被整除的都放进数组 
		}
	}
	int temp=0,f=0;
	for(int i=0;i<count;i++)
	{
		for(int k=i+1;k<count;k++)
		{
			if(a[k]-a[i]==k-i&&k-i>temp)
			{
				temp=k-i;
				f=i;
			}
			else
			break;
		}
	}
	cout<<temp<<endl;
	cout<<a[f];
	int c=f;
	while(c<=f+temp)
	cout<<"*"<<a[c];
	return 0;
}
