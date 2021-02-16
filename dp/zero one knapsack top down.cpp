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

const int N=1e3 + 5;

int w[N];//weight
int p[N];//profit
int n,m;//# of items,capacity
int cache[N][N];

int solve(int i,int cap)
{
	if(i>n)
	{
		return 0;
	}
	if(cap<=0)
	{
		return 0;
	}
	if(cache[i][cap]!=-1)
	{
		return cache[i][cap];
	}
	if(cap>=w[i])
	{
		return cache[i][cap] = max(p[i] + solve(i+1,cap-w[i]),solve(i+1,cap));
	}
	else
	{
		return cache[i][cap]= solve(i+1,cap);
	}
}

int32_t main()
{
	IOS;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		rep(i,1,n)
		{
			cin >> p[i];
		}
		rep(i,1,n)
		{
			cin >> w[i];
		}
		rep(i,1,n+1)
		{
			rep(j,1,m+1)
			{
				cache[i][j]=-1;
			}
		}
		cout << solve(1,m) << endl;
	}
}
