//https://atcoder.jp/contests/abc044/tasks/arc060_a
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=55;

int n, a;
int x[N];
int cache[N][2*N*N];

int dp(int idx, int sum)
{
	if(idx==n+1)
		return (sum==0);
	int ans=cache[idx][sum+N*N];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, sum) + dp(idx+1, sum+x[idx]);
	cache[idx][sum+N*N] = ans;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		x[i]-=a;
	}
	int ans=dp(1, 0)-1;
	cout<<ans;
	return 0;
}

