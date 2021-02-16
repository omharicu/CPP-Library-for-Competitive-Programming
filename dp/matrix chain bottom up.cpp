#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e3 + 5;

int dp[N][N];
int a[N];
int n;

int32_t main()
{
	cin >> n;
	int i;
	int j;
	for(i=0;i<=n;i++)
	{
		cin >> a[i];
	}
	for(i=1;i<=n;i++)
	{
		dp[i][i]=0;
	}
	int l;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			dp[i][j]=INT_MAX;
			int k;
			for(k=i;k<=(j-1);k++)
			{
				dp[i][j]= min(dp[i][j],dp[i][k] + dp[k+1][j]+ a[i-1]*a[j]*a[k]);
			}
		}
	}
	/*for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[1][n] << endl;
}
