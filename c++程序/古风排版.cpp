#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	string str;
	cin.get();
	getline(cin,str);
	int len=str.size();
	int size=0;
	if (len%n==0)
	size=len/n;
	else
	size=len/n+1;
	for(int i=0;i<n;i++)
	{
		int a=i;
		char a1[size];
		for(int k=size-1;k>=0;k--)
		{
			if(a<len){
			a1[k]=str[a];
			a+=n;}
			else
			a1[k]=' ';
		}
		cout<<a1<<endl;
	}
}
