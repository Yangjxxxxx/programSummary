#include<iostream>
#include<cmath>
using namespace std;
long long int extgcd(long long int a, long long int b, long long int& x, long long int& y)
{
    long long int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}
long long int mod_inverse(long long int a, long long int m)
{
    long long int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}
int main()
{
	std::ios::sync_with_stdio(false);
	long long int n,p;
	while(cin>>n>>p)
	{
		if(p>6){
		long long int _r=mod_inverse(6,p);
		long long int ans=(n%p*(n+1)%p*(2*n+1)%p*_r%p)%p;
		cout<<ans<<endl;}
		else
		{
			long long int ans=(((n%p)*((n+1)%p)*((2*n+1)%p))%(6*p))/6;
			cout<<ans<<endl;
		}
	}
	return 0;
}
