#include<bits/stdc++.h>
using namespace std;

//#define int         long long
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

const int N=1e3 + 5;

int w[N];//weight
int p[N];//profit
int n,m;//# of items,capacity
int dp[N][N];

int solve()
{
	int i;
	int j;
	memset(dp,0,sizeof(dp));
	for(j=0;j<=m;j++)
	{
		dp[0][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0]=0;
		for(j=1;j<=m;j++)
		{
			if(w[i]<=j)
			{
				dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] +p[i]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][m];
}

int32_t main()
{
	IOS;
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> n >> m >> x >> y;
		rep(i,1,n)
		{
			cin >> w[i];
		}
		rep(i,1,n)
		{
			cin >> p[i];
		}
		int ans = -1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				p[i] = p[i]*x;
				p[j] = p[j]*y;
				ans = max(ans,solve());
				p[i] = p[i]/x;
				p[j] = p[j]/y;
				p[i] = p[i]*y;
				p[j] = p[j]*x;
				ans = max(ans,solve());
				p[i] = p[i]/y;
				p[j] = p[j]/x;
			}
		}
		cout << ans << endl;
	}
}
