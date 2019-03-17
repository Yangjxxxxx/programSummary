#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int main(void)
{
	cout<<"输入18位身份证号码："<<endl;
	string num;
	cin>>num;
	while (1){                       //判断输入是否18位 
		if (num.size()==18){
			break;
		}
		else{
			cout<<"输入错误请重新输入："<<endl;
			cin>>num; 
		}
	} 
	int k[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};  //系数 
	int sum=0;
	for (int i=0;i<17;++i){
		char a=num[i];
		int key=(int)a-48;
		sum=sum+key*k[i];
	}
	int ans=sum%11;
	string identify="10X98765432";
	if (identify[ans]==num[17]){
		cout<<"合法"<<endl;
	}
	else
	cout<<"不合法"<<endl;
} 
