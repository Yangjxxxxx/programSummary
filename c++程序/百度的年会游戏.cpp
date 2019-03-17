#include<iostream>
using namespace std;
int Min(int x,int y)
{
	if(x<y)
	return x;
	else return y;
}
int main(void)
{
	int k,d,per,n,n1,answer=0;
	int num[5];
	num[0]=0;
	cin>>num[1]>>num[2]>>num[3]>>num[4]>>k>>d;
	if(k==1)
	n=num[1]-d+1;
	else if(k==2)
	n=num[1]+num[2]-d+1;
	else if(k==3)
	n=num[1]+num[2]+num[3]-d+1;
	else if(k==4)
	n=num[1]+num[2]+num[3]+num[4]-d+1;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			if((i+j)%4==0)
			per=4;
			else per=(i+j)%4;
			if(per==1)
        	n1=num[1]-Min(i,j);
	        else if(per==2)
	        n1=num[1]+num[2]-Min(i,j);
	        else if(per==3)
	        n1=num[1]+num[2]+num[3]-Min(i,j);
	        else if(per==4)
	        n1=num[1]+num[2]+num[3]+num[4]-Min(i,j);
	        if(n1-16<=0&&n==54-16+n1)
	        answer++;
	        else if(n1-16>0&&n1-16==n)
	        answer++;
	        else if(n1-8<=0&&n==54-8+n1)
	        answer++;
	        else if(n1-8>0&&n1-8==n)
	        answer++;
	        else if(n1==n)
	        answer++;
		}
	}
	cout<<(answer+1)/2;
}
