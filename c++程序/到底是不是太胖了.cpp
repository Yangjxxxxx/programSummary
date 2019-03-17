#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n<=20)
	{
	double h[n],w[n];
	for(int i=0;i<n;i++)
	{
		cin>>h[i]>>w[i];
		
		w[i]=w[i]/2;
	}
	for(int k=0;k<n;k++)
	{
		double temp=(h[k]-100)*0.9;
		double a;
		if(w[k]-temp<0)
		a=temp-w[k];
		else
		a=w[k]-temp;
		if(a<temp*0.1)
		cout<<"You are wan mei!"<<endl;
		else
		{
			if(w[k]>temp)
			cout<<"You are tai pang le!"<<endl;
			else
			cout<<"You are tai shou le!"<<endl;
		}
	}
    }
	return 0;
}
