/*
8 12
1 2 1
1 3 2
1 4 5
2 5 4
2 6 11
3 5 9
3 6 5
3 7 16
4 7 2
5 8 18
6 8 13
7 8 2
Source 1;
dest - n;
Ans for this = 9


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

const int N=1e2 + 5;

int dp[N];
int n,m;
map<pair<int,int>,int> mp;

int32_t main()
{
	cin >> n >> m;
	rep(i,1,m)
	{
		int x,y;
		cin >> x >> y;
		int w;
		cin >> w;
		mp[{x,y}]=w;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=INT_MAX;
	}
	dp[n]=0;
	int i;
	int j;
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			if(mp[{i,j}]==0)
			{
				continue;
			}
			else
			{
				dp[i] = min(mp[{i,j}]+dp[j],dp[i]);
			}
		}
	}
	cout << dp[1] << endl;
}
