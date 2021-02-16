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


const int N=1e2 + 5;
const int MOD=1e9 + 7;


int n,m;
char grid[N][N];
int vis[N][N];



// for up,down,right,left loop from to k=0 to k<4
// for all 8 directions, like a king move in chess loop from k=0 to k<8.
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

// to check if the position is within the grid
// grid is from (0,0) to (n-1,m-1)
bool ok(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }


void dfs(int i,int j)
{
	vis[i][j] = 1;
	for(int k=0;k<4;k++)
	{
		int newX = i + dx[k];
		int newY = j + dy[k];
		if(ok(newX,newY)==1 && vis[newX][newY]==0 && grid[newX][newY]=='0')
			dfs(newX,newY);
	}
}

int32_t main()
{
	IOS;
	int T=1;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		clr(vis,0);
		cin >> n >> m;
		rep(i,0,n-1)
		{
			rep(j,0,m-1)
				cin >> grid[i][j];
		}
		rep(i,0,n-1)
		{
			rep(j,0,m-1)
			{
				if(grid[i][j]=='0' &&  vis[i][j]==0)
					dfs(i,j);
			}
		}
		rep(i,0,n-1)
		{
			rep(j,0,m-1)
				cout << vis[i][j] << " ";
			cout << endl;
		}
	}
}

/* 
This prpgram visits all cells in grid with '0'. Hence vis[i][j] = 1 if grid[i][j]=='0'. Rest vis[i][j] = 0.
Input - 
3 4
1 1 0 0 
0 0 1 1
1 1 1 0


Output- 
0 0 1 1
1 1 0 0
0 0 0 1
*/


