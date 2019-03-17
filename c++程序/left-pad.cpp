#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	char c;
	cin>>n>>c;
	cin.get();
	string str;
	getline(cin,str);
	int len=str.size();
    if(n<=10^4)
	{
		if(n>len)
		{
			for(int i=0;i<n-len;i++)
			{
				cout<<c;
			}
			cout<<str;
		}

		 if(n==len)
		{
			cout<<str;
		}
		if (n<len)
		{
			for(int k=len-n;k<len;k++)
			{
				cout<<str[k];
			}
		}
	}
	return 0;
}
