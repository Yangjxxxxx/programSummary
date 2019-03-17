#include<iostream>
#include<string>
using namespace std;
int main()
{
	string c,b;
	getline(cin,c);
	int n=c.size();
	cin>>b;
	int lenb=b.size();
	int visited[1000];
	for(int i=0;i<1000;i++)
	visited[i]=0;
    for(int i=0;i<lenb;i++)
    visited[(int)b[i]]=1;
    for(int k=0;k<n;k++)
    {
    	if(visited[(int)c[k]]==0)
    	cout<<c[k];
    	else
    	continue;
	}
	return 0;
}
