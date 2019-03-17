#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string str;
	getline(cin,str,'\n');
	int len=str.size();
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		int temp=1;
		for(int j=1;j<len;j++)
		{
			if(str[i-j]!=str[i+j]||i-j<0||i+j>len-1)
			break;
			temp+=2;
		}
		if(temp>cnt)
		cnt=temp;
		int _temp=0;
		for(int j=1;j<len;j++)
		{
			if(str[i-j]!=str[i+j-1]||i-j<0||i+j>len)
			break;
			_temp+=2;
		}
		if(_temp>cnt)
		cnt=_temp;
	}
	cout<<cnt;
}
