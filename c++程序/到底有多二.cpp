#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	float b,a=1;
	float n=str.size();
	if(str[0]=='-')
	a=1.5;
	if(str[n-1]!='1'&&str[n-1]!='3'&&str[n-1]!='5'&&str[n-1]!='7'&&str[n-1]!='9')
	b=2;
	else
	b=1;
	float count=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='2')
		count++;
		else
		continue;
	}
	float r;
	if(a==1.5)
	n=n-1;
	r=count/n*a*b*100;
	printf("%.2f",r);
	cout<<"%"<<endl;
	return 0;
}
