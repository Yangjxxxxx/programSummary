#include<iostream>
#include<stdio.h> 
using namespace std;
int main()
{
	int A,B,sum;
	cin>>A>>B;
	if(-100<=A&&A<=B&&B<=100)
	{
		sum=(A+B)*(B-A+1)/2;
		int temp,i=0;
		temp=A;
		while(temp<=B)
		{
			printf("%5d",temp); 
			i++;
			temp++;
			if(i%5==0)
			cout<<endl;
		}
		if(i%5==0)
		cout<<"Sum = "<<sum;
		else
		cout<<endl<<"Sum = "<<sum;
	}
	return 0;
}
