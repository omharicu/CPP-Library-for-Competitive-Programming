// Watch this for quick explanation-
//https://www.youtube.com/watch?v=aZXi1unBdJA
// Check the discuss for alternate  solutions -- https://leetcode.com/problems/critical-connections-in-a-network/
// Also try and understand articulation points through Ashishgup's code
#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define pb          push_back
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5 + 5; // N is max number of vertices
const int M=1e5 + 5; // M is max number of edges

int n,m;
vector<pair<int, int>> g[N]; // vertex , edge number 
int u[N],v[N],vis[N]; // u,v to store edges, needed to print the bridges
int dis[N],minAncestor[N],isBridge[M]; //dis is discovery time,minAncestor is what the name suuggests,isBridge is array for edges

void dfs(int cur,int par,int val)
{
	vis[cur]=1;
	dis[cur] = val;
	minAncestor[cur] = val;
	for(auto it : g[cur])
	{
		if(it.first==par)
			continue;
		if(vis[it.first]==1)
		{
			minAncestor[cur] = min(minAncestor[cur],dis[it.first]);
			continue;
		}
		dfs(it.first,cur,val+1);
		minAncestor[cur] = min(minAncestor[cur],minAncestor[it.first]);
		if(minAncestor[it.first]>dis[cur]) // most imp condition
			isBridge[it.second] = 1;
	}
}

int32_t main()
{
	IOS;
	int T;
	cin >> T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));	
		memset(isBridge,0,sizeof(isBridge));
		cin >> n >> m;
		//done considering i is the smallest node. 
		// If questions says 0 as samllest node, add +1 during input and substract during ans.
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			cin >> u[i] >> v[i];
			g[u[i]].push_back({v[i],i}); // i is stored to note the edge number
			g[v[i]].push_back({u[i],i});
//			if(u[i]>v[i]) // to this if answer has to be in increasing order of edges
//				swap(u[i],v[i]);
		}
		dfs(1,0,1); // 1 is assumed to have parent 0
		vector<pair<int, int>> ans;
		for(int i=1;i<=m;i++)
		{
			if(isBridge[i]==1)
				ans.push_back({u[i], v[i]});
		}
		//sort(ans.begin(), ans.end());
		cout<<ans.size()<<endl;
		for(auto it:ans)
			cout<<it.first<<" "<<it.second<<endl;
		
	}
}

