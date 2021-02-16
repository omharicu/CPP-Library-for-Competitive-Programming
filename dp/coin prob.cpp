#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const int N=1e5 + 5;

int a[N];
int n;

int solve(int x)
{
	if(x<0)
	{
		return INT_MAX;
	}
	if(x==0)
	{
		return 0;
	}
	int best = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		best = min(solve(x-a[i])+1,best);
	}
	return best;
}

int32_t main()
{
	int x;
	cin >> n;
	cin >> x;
	int i;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	cout << solve(x) << endl;
}
