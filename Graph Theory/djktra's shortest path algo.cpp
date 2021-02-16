/*input-
Graph-
9 28
1 2 4
1 8 8
2 1 4
2 3 8
2 8 11
3 2 8
3 4 7
3 6 4
3 9 2
4 3 7
4 5 9
4 6 14
5 4 9
5 6 10
6 3 4
6 4 14
6 5 10
6 7 2
7 6 2
7 8 1
7 9 6
8 1 8
8 2 11
8 7 1
8 9 7
9 3 2
9 7 8
9 8 7

Source -
1
Output-
0 4 12 19 21 11 9 8 14
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

const int N=1e5 + 5;

int ans[N];
vector<int> g[N];
int n,m;
map<pair<int,int>,int> mp;

int32_t main()
{
	IOS;
	cin >> n >> m;
	rep(i,1,m)
	{
		int x,y,w;
		cin >> x >> y >> w;
		g[y].pb(x);
		g[x].pb(y);
		mp[{x,y}]=w;
		mp[{y,x}]=w;
	}
	int sou;
	cin >> sou;
	int i;
	for(i=1;i<=n;i++)
	{
		ans[i] = INT_MAX;
	}
	set<pair<int,int>> s;
	s.insert({0,sou});
	ans[sou] =0;
	while(!s.empty())
	{
		auto x = *(s.begin());
		s.erase(x);
		for(auto it:g[x.second])
		{
			if(ans[it] > ans[x.second]+ mp[{x.second,it}])
			{
				ans[it] = ans[x.second] + mp[{x.second,it}];
				s.insert({ans[it],it});
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
}


