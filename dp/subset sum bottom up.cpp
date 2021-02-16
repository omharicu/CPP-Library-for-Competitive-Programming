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
bool dp[N][N];

int32_t main()
{
	IOS;
	cin >> n;
	cin >> m;
	rep(i,1,n)
	{
		cin >> a[i];
	}
	int i;
	int j;
	for(j=1;j<=m;j++)
	{
		dp[0][j]=false;
	}
	dp[0][0]=true;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=true;
		for(j=1;j<=m;j++)
		{
			if(j>=a[i])
			{
				dp[i][j] = dp[i-1][j-a[i]] || dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	if(dp[n][m]==true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	// Another way to find in O(n) space--
	int tar = m;
    bool dpp[tar+1];
    memset(dpp,false,sizeof(dpp));
    dpp[0] = true;
    for(int i=1;i<=n;i++) // i as input array starts from 1  --> array a
    {
        for(int j=tar;j>=a[i];j--)
        {
            dpp[j] = dpp[j] || dpp[j-a[i]]; // to find number of ways -> instead of || do + , ans will be in dpp[tar]
        }
    } 
    if(dpp[tar]==true)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
