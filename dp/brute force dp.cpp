//https://codeforces.com/contest/1151/problem/B
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

const int N=505;

int dp[N][N];
int a[N][N];
int n,m;
vector<int> v;

int solve(int i,int j)
{
	if(i>n && j!=0)
	{
		cout << "TAK" << endl;
		return 1;
	}
	if(i>n && j==0)
		return 0;
	if(dp[i][j] == -1)
	{
		for(int k=1;k<=m;k++)
		{
			if(solve(i+1,j^a[i][k]))
			{
				v.push_back(k);
				dp[i][j]=1;
				return dp[i][j];
			}
		}
		dp[i][j]=0;
		return dp[i][j];
	}
	else 	
		return dp[i][j];
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			cin >> a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	int x=solve(1,0);
	reverse(v.begin(),v.end());
	if(x>0)
	{
		repp(i,0,n)
		{
			cout << v[i] << " ";
		}
	}
	else
	{
		cout << "NIE" << endl;
	}
}
