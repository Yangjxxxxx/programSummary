#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int main(void)
{
	cout<<"����18λ���֤���룺"<<endl;
	string num;
	cin>>num;
	while (1){                       //�ж������Ƿ�18λ 
		if (num.size()==18){
			break;
		}
		else{
			cout<<"����������������룺"<<endl;
			cin>>num; 
		}
	} 
	int k[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};  //ϵ�� 
	int sum=0;
	for (int i=0;i<17;++i){
		char a=num[i];
		int key=(int)a-48;
		sum=sum+key*k[i];
	}
	int ans=sum%11;
	string identify="10X98765432";
	if (identify[ans]==num[17]){
		cout<<"�Ϸ�"<<endl;
	}
	else
	cout<<"���Ϸ�"<<endl;
} 
