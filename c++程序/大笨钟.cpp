#include<iostream>
#include<string>
using namespace std;
int main()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	if(h>=0&&h<=23&&m>=0&&m<=59)
	{
		if(h>=12&&m>0)
		{
			for (int k=0;k<h-11;k++)
			cout<<"Dang";
		}
		else if(h>12&&m==0)
		{
			for (int k=0;k<h-12;k++)
			cout<<"Dang"; 
		}
		else
	    {
	    if(h<10)
		cout<<"Only 0"<<h<<":";
		else
		cout<<"Only "<<h<<":";
		if(m<10)
		cout<<"0"<<m;
		else
		cout<<m;
		cout<<".  Too early to Dang.";
	    }
    }
	return 0;
}
