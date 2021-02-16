//Distance stores levels, and ways stores the number of ways to get from kth vertex 
//to any other vertex with the shortest path taken
#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define pb push_back

#define f(i,n) for(i=0;i<n;i++)
#define ALL(v) v.begin(),v.end()
#define mod 1000000007
int N= 10+5;

vector<int> g[100];	
int vis[100];
int ways[100];
int dist[100];

void bfs(int k)
{
	queue<int> q;
	q.push(k);
	ways[k]=1;
	vis[k]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:g[node])
		{
			if(vis[it]==0)
			{
				dist[it]=dist[node]+1;
				vis[it]=1;
				ways[it]+=ways[node];
				q.push(it);
			}
			else
			{
				if(dist[node]+1==dist[it])
				{
					ways[it]+=ways[node];
				}
			}
		}
	}
}

int32_t main()
{
	int n,e;
	cin >> n >> e;
	int i;
	for(i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
	}
	bfs(0);// start from parent otherwise code fails
	for(i=1;i<=n;i++)
	{
		cout << dist[i] << " " << ways[i] << endl;
	}
	
	
}
