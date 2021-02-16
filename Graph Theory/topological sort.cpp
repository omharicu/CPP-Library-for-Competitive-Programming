#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define sz(x)       (int)x.size()
#define endl        "\n"
#define repp(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) 	for(int i=a;i<=b;i++)
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5 + 5;

int n,m;
vector<int> g[N];
vector<int> topo;

bool toposort() //Returns 1 if there exists a toposort, 0 if there is a cycle
{	
	int indeg[n+5];
	memset(indeg,0,sizeof(indeg));
	topo.clear();
	priority_queue<int, vector<int>, greater<int> > pq;// Simple queue will also work
	for(int i=1;i<=n;i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i=1;i<=n;i++)
	{
		if(!indeg[i])
			pq.push(i);
	}
	while(!pq.empty())
	{
		int u=pq.top();
		pq.pop();
		topo.push_back(u);// you can simply have a count instead of push if you want to check there is a cycle or not
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])//if indegree of v is zero
				pq.push(v);
		}
	}
	if(topo.size()<n)
		return 0;
	return 1;
}


int32_t main()
{
	IOS;
	cin >> n >> m;
	rep(i,1,m)
	{
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
	}
	int x= toposort();
	if(x==1)
	{
		cout << "YES" << endl;
		for(int x: topo)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "There is a cycle\n";
	}
}

