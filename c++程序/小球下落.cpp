#include<iostream>
#include<cmath>
using namespace std;
struct node{
	bool flag;
};
node tree[65536];
int change(int x)
{
	if(x>=65535/2)
	return x;
	if(tree[x].flag==false){
	tree[x].flag=true;
	x=x*2;}
	else {
	tree[x].flag=false;
	x=x*2+1;}
	return change(x);
}
int main(void)
{
	for (int i=0;i<=65535;++i)
	tree[i].flag=false;
	int ans;
	for(int i=1;i<=12345;++i)
	{
		ans=change(1);
	}
	cout<<ans;
}

