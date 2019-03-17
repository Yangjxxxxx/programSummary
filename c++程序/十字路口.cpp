#include<iostream>
using namespace std;
int main()
{
	int t,ans;
	cin>>t;
	if(t<3)
	t=t+24;
	if(t>2&&t<8)
	{
		ans=(t-2)*180;
	}
	else if(t>7&&t<23)
	{
		ans=(7-2)*180+(t-7)*216;
	}
	else if(t>22)
	{
		ans=(7-2)*180+(22-7)*216+(t-22)*180; 
	}
	cout<<ans;
	return 0;
} 
