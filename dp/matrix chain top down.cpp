#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e3 + 5;

int a[N];
int cache[N][N];
int n;

int mul(int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(cache[i][j]!=INT_MAX)
	{
		return cache[i][j];
	}
	int k;
	int x;
	for(k=i;k<j;k++)
	{
		x=(mul(i,k)+mul(k+1,j)+a[i-1]*a[k]*a[j]);
		if(x<cache[i][j])
		{
			cache[i][j]= x;
		}
	}
	return cache[i][j];
}

int32_t main()
{
	cin >> n;
	int i;
	for(i=0;i<=n;i++)
	{
		cin >> a[i];
	}
	int j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cache[i][j]= INT_MAX;
		}
	}
	cout << mul(1,n) << endl;
}
