#include<iostream>
using namespace std;
int main()
{
	int N;
	char C;
	cin>>N>>C;
	if(N>=3&&N<=21)
	{
		int b,d;
		double a,c;
		a=N;
		b=N/2;
		c=a/2;
		if(c-b>=0.5)
		d=b+1;
		else
		d=b;
		for(int i=0;i<d;i++)
		{
			for(int j=0;j<N;j++)
			cout<<C;
			cout<<endl;
		}
	}
	return 0;
}
