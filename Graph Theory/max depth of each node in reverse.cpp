//leaves has deep[]=0
// root has the deep[] = actula height of the tree
//1 rooted tree
/* Input - 
1
7
1 2
1 3
2 4
2 5
4 6
4 7
Output -
3 2 0 1 0 0 0
Sample Problem - https://www.codechef.com/EXPP2019/problems/EXUND
Solution - https://www.codechef.com/viewsolution/27354447
*/
 
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

const int N=5e5 + 5;
const int M=1e9 + 7;

vector<int> g[N];
int deep[N];
int n;
int k;

void dfs(int child,int par)
{
	for(auto it: g[child])
	{
		if(it==par)
		{
			continue;
		}
		dfs(it,child);
		deep[child] = max(deep[child],deep[it]+1);
	}
}

int32_t main()
{
	//IOS;
	//memset(dp,-1,sizeof(dp));
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		memset(deep,0,sizeof(deep));
		rep(i,1,n)
		{
			g[i].clear();
		}
		rep(i,1,n-1)
		{
			int x,y;
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}
		dfs(1,0);
		rep(i,1,n)
		{
			cout << deep[i] << " ";
		}
		cout << endl;
	}

}

