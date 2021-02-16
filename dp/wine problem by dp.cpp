#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const int N=1e4+5;
int a[N];
int n;
int cache[N][N];

int profit(int be,int en)
{
	if(be>en)
		return 0;
	/*if(cache[be][en]!=-1)
	{
		return cache[be][en];
	}*/
	int year = be + (n-en);
	return cache[be][en] = max( profit(be+1,en)+ year*a[be] , profit(be,en-1) + year*a[en]);
}
int32_t main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cache[i][j] = -1;
		}
	}
	cout << profit(1,n) << endl;
}
