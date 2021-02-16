#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e3 + 5;

string s1,s2;
int n,m;
int a[N][N];

int32_t main()
{
	cin >> s1 >> s2;
	n=s1.size();
	m=s2.size();
	int i;
	int j;
	for(i=0;i<=n;i++)
	{
		a[i][0]=0;
	}
	for(j=0;j<=m;j++)
	{
		a[0][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				a[i][j]= 1 + a[i-1][j-1];
			}
			else
			{
				a[i][j] = max(a[i-1][j],a[i][j-1]);
			}
		}
	}
	cout << a[n][m] << endl;
}
