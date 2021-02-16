#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const int N=1e5+5;
int a[N];
int n;

int profit(int be,int en)
{
	if(be>en)
		return 0;
	int year = n - en + be;
	return max((profit(be+1,en) + year*(a[be])),(profit(be,en-1) + year*a[en]));
}
int32_t main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	cout << profit(1,n) << endl;
}
