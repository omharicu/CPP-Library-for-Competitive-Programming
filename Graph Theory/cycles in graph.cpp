// problem - https://codeforces.com/problemset/problem/1027/D
// read editorial for explanation and try and find the logic as to why this works
// non intersecting cycles
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

#define double      	long double
#define int         	long long
#define pb          	push_back
#define pii         	pair<int,int>
#define vi          	vector<int>
#define vii         	vector<pii>
#define mi          	map<int,int>
#define mii         	map<pii,int>
#define all(a)      	(a).begin(),(a).end()
#define sz(x)       	(int)x.size()
#define endl        	"\n"
#define repp(i,a,b) 	for(int i=a;i<b;i++)
#define rep(i,a,b) 		for(int i=a;i<=b;i++)
#define brep(i,a,b)     for(int i=a;i>=b;i--)
#define deb1(x)      	cout << #x << "=" << x << endl
#define deb2(x, y)  	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)  	cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define trace(v) 		for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
#define tracearr(a,l,r) for(int iii=l;iii<=r;iii++)cout << a[iii] << " ";cout << endl;
#define PI          	3.1415926535897932384626
#define F 				first
#define S 				second
#define clr(x,y) 		memset(x, y, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N=2e5 + 5;
const int MOD=1e9 + 7;

vector<int> g[N];
int vis[N] , par[N] , c[N];
int ans= 0;
int n;


void dfs(int u,int p)
{
	vis[u] = 1;
	par[u] = p;
	for(int v: g[u])
	{
		if(vis[v]==0)
			dfs(v,u);
		else if(vis[v]==1)
		{
			int cur = u;
			int best = c[v];
			while(cur!=v)
			{
				best = min(best,c[cur]);
				cur = par[cur];
			} 
			ans += best;
		}
	}
	vis[u] = 2;
}

int32_t main()
{
	IOS;
	int T=1;
	//cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		cin >> n;
		rep(i,1,n)
			cin >> c[i];
		rep(i,1,n)
		{
			int x;
			cin >> x;
			g[i].pb(x);
		}
		rep(i,1,n)
		{
			if(vis[i]==0)
				dfs(i,-1);
		}
		cout << ans << endl;
	}
}
