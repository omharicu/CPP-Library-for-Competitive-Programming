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
#define rep(i,a,b)  for(i=a;i<b;i++)
#define repp(i,a,b) for(i=a;i<=b;i++)
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e5 + 5;

mi mp;
int n;
int a[N];
int cache[N];

int solve(int i)
{
	if(i>1e5)
	{
		return 0;
	}
	if(cache[i]!=-1)
	{
		return cache[i];
	}
	if(mp[i]==0)
	{
		cache[i]= solve(i+1);
	}
	return cache[i]= max((i*mp[i]+solve(i+2)),solve(i+1));
}
int32_t main()
{
	cin >> n;
	int i;
	repp(i,1,n)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	repp(i,1,N)// cannot run till N but runs till 1000
	{
		cache[i]=-1;
	}
	cout << solve(1) << endl;
}
