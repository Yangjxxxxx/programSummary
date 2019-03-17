#include<iostream>
#include<string>
using namespace std;
struct grade
{
	int sex;
	string name;
};
int main()
{
	int n;
	cin>>n;
	grade ranking[n];
	for(int i=0;i<n;i++)
	{
		cin>>ranking[i].sex>>ranking[i].name;
	}
	for(int j=0;j<n;j++)
	{
		for(int k=n-1;k>=0;k--)
		{
			if(ranking[j].sex+ranking[k].sex==1)
			{
				cout<<ranking[j].name<<" "<<ranking[k].name<<endl;
				ranking[k].sex=2;
				break; 
			}
			else
			continue;
		}
	}
	return 0;
}
