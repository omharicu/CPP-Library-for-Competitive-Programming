/*Input- 
7 9
1 6 10
6 5 25
5 7 24
7 2 14
2 1 28
5 4 22
4 7 18
4 3 12
3 2 16


Output - 99
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const int N=1e5 + 5;

struct edge
{
	int u;
	int v;
	int w;
};

int parent[N],sz[N];
vector<pair<int,int>> g[N]; // no need of this if you just want ot find the cost
vector<edge> v;// where the edges of the MST will be placed
int n,m;
edge a[N];

void initi()
{
	int i;
	for(i=1;i<=n;i++)
	{
		parent[i] =i;
		sz[i]=1;
	}
}

int find(int k)
{
	while(k!=parent[k])
	{
		parent[k]= parent[parent[k]];
		k= parent[k];
	}
	return k;
}

void merge(int u,int v)
{
	int r1= find(u);
	int r2 = find(v);
	if(r1==r2)
		return;
		
	if(sz[r1]>sz[r2])
	{
		swap(r1,r2);
	}
	parent[r1] = parent[r2];
	sz[r2] += sz[r1];
	sz[r1]=0;
}

bool comp(edge a,edge b)
{
	return a.w < b.w;
}

int kruskalMST()
{
	int mincost = 0;
	initi();
	sort(a+1,a+m+1,comp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			merge(a[i].u,a[i].v);
			mincost += a[i].w;
			v.push_back(a[i]);
		}
	}
	cout << "The cost of minimum spanning tree is - " << mincost << endl;
	cout << "The MST is -" << endl;
	for(int i=0;i<v.size();i++)
	{
		cout << v[i].v << "---" << v[i].u << "  Weight-" << v[i].w << endl;
	}
	return mincost;
}

int32_t main()
{
	cin >> n >> m;
	int i;
	for(i=1;i<=m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
		a[i].u=x;
		a[i].v=y;
		a[i].w=z;
	}
	kruskalMST();
}
