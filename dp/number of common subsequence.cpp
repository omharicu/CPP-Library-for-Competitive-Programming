//https://atcoder.jp/contests/abc130/tasks/abc130_e
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

const int N=2e3 + 5;
const int M=1e9 + 7;

int a[N];
int b[N];
int cache[N][N];
int n,m;

int solve(int i, int j)
{
	if(i>n || j>m)
		return 0;
	int &ans = cache[i][j];
	if(ans!=-1)
		return ans;
	if(a[i] == b[j])
		ans = 1+ solve(i+1,j)+ solve(i,j+1);
	else
		ans = solve(i+1,j) + solve(i,j+1) - solve(i+1,j+1);// more explanation req
	ans += M;// this step is very imp
	ans %= M;
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	memset(cache,-1,sizeof(cache));
	rep(i,1,n)
	{
		cin >> a[i];
	}
	rep(i,1,m)
	{
		cin >> b[i];
	}
	int ans= solve(1,1);
	ans++;// for empty subsequence
	ans %= M;
	cout << ans << endl;
}

