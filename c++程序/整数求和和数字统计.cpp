#include<iostream>
#include<vector>
using namespace std;
int main(){
	int T;
	cin>>T;
	vector<vector<int> > cnt;
	for(int i=0;i<T;++i){
		long long int a,b;
		vector<int> ans(10,0);
		cin>>a>>b;
		long long int answer = a+b;
		string str = to_string(answer);
		for(int k=0;k<str.size();++k){
			ans[(int)str[k]-48] = ans[(int)str[k]-48]+1;
		}
		cnt.push_back(ans);
	} 
	for(int i=0;i<cnt.size();i++){
		int flag=0;
		for(int k=0;k<10;++k){
			if(cnt[i][k]==0)
			continue;
			if(flag!=0)
			cout<<" ";
			cout<<k<<":"<<cnt[i][k];
			flag = flag+1;
		}
		cout<<endl;
	}
	return 0;
}
