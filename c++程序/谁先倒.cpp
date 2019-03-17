#include<iostream>
using namespace std;
int main()
{
	unsigned int a,b;
	cin>>a>>b;
	if(a<=100&&b<=100)
	{
		int n;
		cin>>n;
		unsigned int ab[n][4];
		for(int k=0;k<n;k++)
		    cin>>ab[k][0]>>ab[k][1]>>ab[k][2]>>ab[k][3];
		int ca=0,cb=0;
		for(int j=0;j<n;j++)
		{
			if(ab[j][0]+ab[j][2]==ab[j][1]&&ab[j][0]+ab[j][2]==ab[j][3])
			{
				continue;
	     	}
	     	else
	        {
			    if(ab[j][0]+ab[j][2]==ab[j][1]&&ca<=a)
			    {
				    ca++;
			    }
			    if(ca>a)
			    {
				    cout<<"A"<<endl<<cb;
				    break;
			    }
			    if(ab[j][0]+ab[j][2]==ab[j][3]&&cb<=b)
			    {
				    cb++;
			    }
			    if(cb>b)
			    {
				    cout<<"B"<<endl<<ca;
				    break;
			    } 
			}
		}
    }
    return 0;
}
