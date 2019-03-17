#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int main(void)
{
	int n,mi;
	vector<double> w,p,m;
	cin>>n>>mi;
	for(int i=0;i<n;i++)
	{
		double _w;
		cin>>_w;
		w.push_back(_w);
	}
	for(int i=0;i<n;i++)
	{
		double _p;
		cin>>_p;
		p.push_back(_p);
	}
	for(int i=0;i<n;i++)
	{
		m.push_back(p[i]/w[i]);
	}
	vector<pair<double,double> > _s(n);
	for(int i=0;i<n;i++)
	{
		_s[i]=make_pair(m[i],w[i]);
	}
	sort(_s.begin(),_s.end());
	double sum=0;
	for(int k=n-1;k>=0;k--)
	{
		if(_s[k].second<=mi)
		{
			sum+=_s[k].second*_s[k].first;
			mi=mi-_s[k].second;
		}
		else if(_s[k].second>mi)
		{
			sum+=mi*_s[k].first;
			mi=0;
		}
		if(mi==0)
		break;
	}
	printf("%.2lf",sum);
}
