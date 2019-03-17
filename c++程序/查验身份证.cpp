#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,count=0;
	cin>>n;
	string id1[n]="";
	if(n<=100)
	{
		string id[n];
		for(int i=0;i<n;i++)
		   cin>>id[i];
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<17;k++)
			{
				if(id[i][k]!='0'&&id[i][k]!='1'&&id[i][k]!='2'&&id[i][k]!='3'&&id[i][k]!='4'&&id[i][k]!='5'&&id[i][k]!='6'&&id[i][k]!='7'&&id[i][k]!='8'&&id[i][k]!='9')
				{
					id1[i]=id[i];
					count++;
					id[i]="";
					break;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
		    int a[17];
			if(id[i]!="")
			{
				for(int k=0;k<17;k++)
				{
				a[k]=(int)id[i][k];
				a[k]=a[k]-48;}
			}
			else
			continue;
			int sum=a[0]*7+a[1]*9+a[2]*10+a[3]*5+a[4]*8+a[5]*4+a[6]*2+a[7]*1+a[8]*6+a[9]*3+a[10]*7+a[11]*9+a[12]*10+a[13]*5+a[14]*8+a[15]*4+a[16]*2;
			int z=sum%11;
			int m;
			switch(z)
			{
				case 0:m=1;break;
				case 1:m=0;break;
				case 2:char c; c='X';int t;t=(int)c;m=t-48;break;
				case 3:m=9;break;
				case 4:m=8;break;
				case 5:m=7;break;
				case 6:m=6;break;
				case 7:m=5;break;
				case 8:m=4;break;
				case 9:m=3;break;
				case 10:m=2;break;
			}
			char q=id[i][17];
			int p=(int)q;
			int temp=p-48;
			if(m!=temp)
			{
			id1[i]=id[i];
			count++;}
		}   
	}
	if(count==0)
	cout<<"All passed";
	else{
		for(int v=0;v<n;v++)
		{
			if(id1[v]!="")
		cout<<id1[v]<<endl;}
	}
	return 0;
}
