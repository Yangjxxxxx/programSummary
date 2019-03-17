#include<iostream>
using namespace std;
int main()
{
	float n;
	cin>>n;
	if(100<n&&n<=300)
	{
	float w=(n-100)*0.9;
	printf("%.1f",w); 
    }
    return 0;  
} 
