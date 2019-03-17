#include<iostream>
using namespace std;
struct stu
{
	long long num;
	int test;
	int seat;
};
int main()
{
	int i;
	cin>>i;
	if(i<=1000)
	{
	    stu passage[i];
	    for(int n=0;n<i;n++)
	    cin>>passage[n].num>>passage[n].test>>passage[n].seat;
	    int j;
	    cin>>j;
	    for(int k=0;k<j;k++)
	    {
		    int t;
		    cin>>t;
		    for(int a=0;a<i;a++)
		    {
		        if(t==passage[a].test)
		        cout<<passage[a].num<<" "<<passage[a].seat<<endl;
	        }
	    }
    }
	return 0;
}
