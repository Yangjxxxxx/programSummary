#include<iostream>
using namespace std;
long gcd(long a,long b);
struct score{
	int son;
	int dad;
};
int main()
{
		long m,n,v=0;
		cin>>n;
		if(n<=100){
		score a[n];
		for(int i=0;i<n;i++)
		scanf("%d/%d",&a[i].son,&a[i].dad);
		long sumd=1;
		for( int j=0;j<n;j++)
		sumd=sumd*a[j].dad;
		long sums=0;
		for(int k=0;k<n;k++)
		sums+=a[k].son*(sumd/a[k].dad);
		if(sums==0)
		{
			cout<<sums;
			return 0;
		}
		if(sums>sumd||sums<-sumd)
		{
			if(sums%sumd==0)
			{
				v=sums/sumd;
				cout<<v;
				return 0;
			}
			else{
			v=sums/sumd;
			cout<<v<<" ";} 
	    }
		sums=sums-v*sumd;
		m=gcd(sums,sumd);
		sums=sums/m;
		sumd=sumd/m;
		double one=(double)sums/(double)sumd;
		if(one==1)
		cout<<"1";
		else
		cout<<sums<<"/"<<sumd;
		}
		return 0;
}
long gcd(long a,long b)
{return b?gcd(b,a%b):a;}

