// See ashishgup's git code if this fails in some problem
#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5 + 5; // N is max number of vertices

int n,m;
vector<int> g[N]; 
int vis[N],isArticulation[N];
int dis[N],minAncestor[N]; //dis is discovery time,minAncestor is what the name suuggests

void dfs(int cur,int par,int val)
{
	vis[cur]=1;
	dis[cur] = val;
	minAncestor[cur] = val;
	int children=0;
	for(auto it : g[cur])
	{
		if(it==par)
			continue;
		if(vis[it]==1)
		{
			minAncestor[cur] = min(minAncestor[cur],dis[it]);
			continue;
		}
		dfs(it,cur,val+1);
		minAncestor[cur] = min(minAncestor[cur],minAncestor[it]);
		if(minAncestor[it]>=dis[cur] && par!=-1) // most imp condition
			isArticulation[cur] = 1;
		children++;
	}
	if(par == -1 && children > 1)
		isArticulation[cur] = 1;
}

int32_t main()
{
	IOS;
	int T;
	cin >> T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));	
		memset(isArticulation,0,sizeof(isArticulation));
		memset(dis,-1,sizeof(dis));	
		memset(minAncestor,-1,sizeof(minAncestor));		
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]==0) // if the graph is disconnected
				dfs(i, -1,1);
		}
		vector<int> ans;
		for(int i=1;i<=n;i++)
		{
			if(isArticulation[i]==1)
				ans.push_back(i);
		}
		cout<<ans.size()<<endl;
		for(auto it:ans)
			cout<<it << " ";
		cout << endl;
		
	}
}

