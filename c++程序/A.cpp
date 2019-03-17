#include<iostream>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	int a=0;
	a=n/1000;
	int b=0;
	b=(n-1000*a)/100;
	int c=0;
	c=(n-1000*a-100*b)/10;
	int d=0;
	d=n-a*1000-b*100-c*10;
	int cnt[4]={0,0,0,0};
	int e[4]={a,b,c,d};
	for(int i=0;i<4;i++)
	{
		int temp=e[i];
		if(a==temp)
		cnt[i]++;
		if(b==temp)
		cnt[i]++;
		if(c==temp)
		cnt[i]++;
		if(d==temp)
		cnt[i]++;
		cnt[i]=cnt[i];
	}
	int temp=cnt[0];
	for(int k=0;k<4;k++)
	{
		if(cnt[k]>temp)
		temp=cnt[k];
		else
		continue;
	}
	if(n==2)
	return 3;
	else if(n==1)
	return 4;
	else if(n==3)
	return 2;
	else
	return 1;
}
