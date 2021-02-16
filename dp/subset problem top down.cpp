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

int a[N];
int n;
int m;
bool cache[N][N];
bool vis[N][N];

bool solve(int i,int j)
{
	if(j==m)
	{
		return true;
	}
	if(i>n)
	{
		return false;
	}
	if(vis[i][j]!=false)
	{
		return cache[i][j];
	}
	vis[i][j]=true;
	return  cache[i][j] = solve(i+1,j+a[i]) || solve(i+1,j);
}

int32_t main()
{
	IOS;
	cin >> n;
	cin >> m;
	rep(i,1,n)
	{
		cin >> a[i];
	}
	rep(i,1,N-2)
	{
		rep(j,1,N-2)
		{
			vis[i][j] = false;
		}
	}
	int flag=solve(1,0);
	if(flag==1)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
