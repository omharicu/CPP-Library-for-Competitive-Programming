/*Input 1 - 
7
1 2 
2 3 
1 4 
4 5 
1 6 
6 7 
Output 1 -
4

Input 2-
4
1 2 
1 3 
3 4 
Output 2-
3
*/



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
#define clr(x) 			memset(x, 0, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N=1e5 + 5;
const int MOD=1e9 + 7;

int n;
vector<int> g[N];
int vis[N];

int maxDistance , maxNode;

void dfs(int u,int d)
{
	vis[u]=1;
	if(d > maxDistance)
	{
		maxDistance = d;
		maxNode = u;
	}
	for(int v:g[u])
	{
		if(vis[v]==0)
			dfs(v,d+1);
	}
}

int find_diameter()
{
	maxDistance = -1;
	memset(vis,0,sizeof(vis));
	dfs(1,0); // finding the farthest node form node 1, stored in maxNode.
	
	memset(vis,0,sizeof(vis)); // finding the distance of the farthest node form maxNode. This is the diameter, stored in maxDistance.
	dfs(maxNode,0);
	return maxDistance;
}

int32_t main()
{
	IOS;
	int T;
	T = 1;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		cin >> n;
		pii t1,t2;
		rep(i,1,n-1)
		{
			int x,y,c;
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}	
		cout << find_diameter() << endl;
	}
}


