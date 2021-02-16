#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e3 + 5;
int a[N];
int n;
int res = INT_MAX;
int x;

int mul(int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	int k;
	int res= INT_MAX;
	for(k=i;k<j;k++)
	{
		x=(mul(i,k)+mul(k+1,j)+a[i-1]*a[k]*a[j]);
		if(x<res)
		{
			res=x;
		}
	}
	return res;
}

int32_t main()
{
	cin >> n;
	int i;
	for(i=0;i<=n;i++)
	{
		cin >> a[i];
	}
	cout << mul(1,n) << endl;
}
