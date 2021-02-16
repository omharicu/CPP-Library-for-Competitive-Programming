// Question - https://atcoder.jp/contests/abc174/tasks/abc174_f
// Video Explantion - https://www.youtube.com/watch?v=6tUxckNqFaM&t=3142s   (Starts at 51:31)			
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

#define double      	long double
#define int         	long long
#define pb          	push_back
#define pii         	pair<int,int>
#define vi          	vector<int>
#define vii         	vector<pii>
#define mi          	map<int,int>
#define mii         	map<pii,int>
#define all(a)      	(a).begin(),(a).end()
#define sz(x)       	(int)x.size()
#define endl        	"\n"
#define repp(i,a,b) 	for(int i=a;i<b;i++)
#define rep(i,a,b) 		for(int i=a;i<=b;i++)
#define brep(i,a,b)     for(int i=a;i>=b;i--)
#define deb1(x)      	cout << #x << "=" << x << endl
#define deb2(x, y)  	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)  	cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define trace(v) 		for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
#define tracearr(a,l,r) for(int iii=l;iii<=r;iii++)cout << a[iii] << " ";cout << endl;
#define PI          	3.1415926535897932384626
#define F 				first
#define S 				second
#define clr(x,y) 		memset(x, y, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N=5e5 + 5;
const int MOD=1e9 + 7;

struct node{
	int l;
	int r;
	int idx;
};

int bit[N];
int n,q;
int ans[N];
vector<node> queries[N];
int lastSeen[N];

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

// returns sum int the array from  position 1 to idx
int prefSum(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rangeSum(int l, int r)
{
	return prefSum(r) - prefSum(l-1);
}

int32_t main()
{
	IOS;
	int T=1;
	//cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		cin >> n >> q;
		memset(bit,0,sizeof(bit));
		clr(lastSeen,-1);
		int a[n+5];
		rep(i,1,n)
			cin >> a[i];
		// take all queries in with respect to their left point
		rep(i,1,q)
		{
			node p;
			cin >> p.l >> p.r;
			p.idx = i;
			queries[p.l].push_back(p);
		}
		brep(i,n,1)
		{
			if(lastSeen[a[i]]!=-1)
				update(lastSeen[a[i]],-1); // -1 as previously it was 1, so substract -1 to make it 0		
			lastSeen[a[i]] = i;
			update(lastSeen[a[i]],1);
			// asnwer all queries whose left point is i
			for(auto it: queries[i])
			{
				int cur = rangeSum(it.l,it.r);
				ans[it.idx] = cur;
			}
		}
		rep(i,1,q)
			cout << ans[i] << endl;
	}
}
