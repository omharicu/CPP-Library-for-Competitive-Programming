/*
Input 1 -
4 4
1 2
2 3
3 4
4 1

Output 1-
yes bipartite, all okay


Input 2-
4 5
1 2
2 3
3 4
4 1
1 3

Output 2-
not bipartite

*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"

const int N=1e5 +5;
int vis[N];
vector<int> g[N];
int n,e;
int flag=0;

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 0;
    while(!q.empty())
    {
        int cur_node = q.front();
        q.pop();
        int cur_val = vis[cur_node];
        for(int ch : g[cur_node])
        {
            if(vis[ch]==-1)
            {
                vis[ch] = cur_val^1;
                q.push(ch);
            }
            else
            {
                if(vis[ch]!=(cur_val^1))
                {
                	flag = 1;
                	return;
				}
            }
        }
    }
}

int32_t main()
{
	cin >> n >> e;
	int i;
	flag = 0;
	for(int i=0;i<n+2;i++)
	{
		g[i].clear();
		vis[i] = -1;
	}
	for(i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==-1)
		{
			bfs(i);
			if(flag==1)
				break;
		}
	}
	if(flag==1)
		cout << "not bipartite\n";
	else 
		cout << "yes bipartite, all okay\n";
}
