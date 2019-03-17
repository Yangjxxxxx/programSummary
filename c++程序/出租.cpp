#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string num;
	set<int> arr;
	vector<int> _arr;
	vector<int> index;
	cin>>num;
	for(int i=0;i<11;i++)
	{
		int temp=num[i]-'0';
		arr.insert(temp);
	} 
	set<int>::reverse_iterator p;
	for(p=arr.rbegin();p!=arr.rend();p++)
	_arr.push_back(*p);
	int n=_arr.size();
	for(int j=0;j<11;j++)
	{
		for(int k=0;k<n;k++)
		{
			if(num[j]-'0'==_arr[k])
			{
				index.push_back(k);
				break;
			}
		}
    } 
    cout<<"int[] arr = new int[]{";
    int tag=0;
    for(int i=0;i<n;i++)
    {
    	if(tag==0)
    	{
    		cout<<_arr[i];
    		tag=1;
		}
		else
		cout<<","<<_arr[i];
	}
	cout<<"};"<<endl<<"int[] index = new int[]{";
	int flag=0;
	for(int j=0;j<11;j++)
	{
		if(flag==0)
		{
			cout<<index[j];
			flag=1;
		}
		else
		cout<<","<<index[j];
	}
	cout<<"};"; 
} 
