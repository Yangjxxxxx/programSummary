#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int n=str.size();
	if(n<=10000)
	{
		int g=0,p=0,l=0,t=0;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='g'||str[i]=='G')
			g++;
			else if(str[i]=='p'||str[i]=='P')
			p++;
			else if(str[i]=='l'||str[i]=='L')
			l++;
			else if(str[i]=='t'||str[i]=='T')
			t++;
		}
		int sum=g+p+l+t;
		for(int k=0;k<sum;k++)
		{
			if(g>0)
			{
				cout<<"G";
				g--;
			}
			if(p>0)
			{
				cout<<"P";
				p--;
			}
			if(l>0)
			{
				cout<<"L";
				l--;
			}
			if(t>0)
			{
				cout<<"T";
				t--;
			}
		}
	}
	return 0;
}
