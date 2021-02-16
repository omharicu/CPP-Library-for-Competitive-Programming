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

int a[N];
int T;
int n;
int dp[N];

int32_t main()
{
	IOS;
	cin >> n >> T;
	rep(i,1,T)
	{
		dp[i] = INT_MAX;
	}
	rep(i,1,n)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=0;
	rep(i,1,T)
	{
		rep(j,1,n)
		{
			if(i-a[j]>=0)
			{
				dp[i] = min(dp[i],dp[i-a[j]]+1);
			}
		}
	}
	cout << dp[T] << endl;
}

