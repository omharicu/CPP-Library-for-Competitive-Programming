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

const int N=1e5 + 5;

int n,m;

bool check(int x, int y)
{
	if(y == 1)
		return 1;
	if(__gcd(x, y) == 1)
		return 0;
	return check(x, y / __gcd(x, y));
}


int32_t main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		//n is superset no. , m is the no. we r testing whether it has a subset of prime factors wrt n
		cout << check(n,m) << endl;
	}
}
