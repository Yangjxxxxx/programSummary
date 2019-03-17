#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int j=str.size();
	int z=0,o=0,t=0,th=0,f=0,fi=0,s=0,se=0,e=0,n=0;
	for(int i=0;i<j;i++)
	{
		
		switch(str[i])
		{
			case '0':z++;break;
			case '1':o++;break;
			case '2':t++;break;
			case '3':th++;break;
			case '4':f++;break;
			case '5':fi++;break;
			case '6':s++;break;
			case '7':se++;break;
			case '8':e++;break;
			case '9':n++;break;
		}
    }
    	if(z>0)
		cout<<"0:"<<z<<endl;
		if(o>0)
		cout<<"1:"<<o<<endl;
		if(t>0)
		cout<<"2:"<<t<<endl;
		if(th>0)
		cout<<"3:"<<th<<endl;
		if(f>0)
		cout<<"4:"<<f<<endl;
		if(fi>0)
		cout<<"5:"<<fi<<endl;
		if(s>0)
		cout<<"6:"<<s<<endl;
		if(se>0)
		cout<<"7:"<<se<<endl;
		if(e>0)
		cout<<"8:"<<e<<endl;
		if(n>0)
		cout<<"9:"<<n<<endl;
    return 0;
}
