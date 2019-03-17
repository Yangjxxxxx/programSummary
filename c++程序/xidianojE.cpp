#include<cstdio>
#include<vector>
#include<queue>
#define N 10001
using namespace std;
struct node{
     long long int x,d;
     node(){}
     node(int a,int b){x=a;d=b;}
     bool operator < (const node & a) const
     {
         if(d==a.d) return x<a.x;
         else return d > a.d;     }
 };
const long long int Max=20000000;
int t,k,s,_t,v,v0,m;
long long int dis[N];
vector<node> eg[N];
priority_queue<node> q;
void dij( int s)
{
	fill(dis,dis+N,Max);
	dis[s]=0;
    q.push(node(s,dis[s]));
     while(!q.empty())
     {
         node x=q.top();q.pop();
        for(int i=0;i<eg[x.x].size();i++)
         {
             node y=eg[x.x][i];
             if(dis[y.x]>x.d+y.d)
             {
                 dis[y.x]=x.d+y.d;
                 q.push(node(y.x,dis[y.x]));
		     }
         }
     }
}
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d %d %d",&s,&_t,&v);
			eg[s].push_back(node(_t,v));
			eg[_t].push_back(node(s,v));
		}
		int v0,m;
		scanf("%d %d",&v0,&m);
		dij(v0);
		printf("%d\n",2*dis[m]);
	}
	return 0;
}

