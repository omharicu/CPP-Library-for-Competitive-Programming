/* sack( dsu on tree) 
	Try Learning abt sack from here - https://codeforces.com/blog/entry/67696
	(Havent learnt yet) 
	
	Problem here - https://atcoder.jp/contests/abc183/tasks/abc183_f
	
	Here idea is similar thou even without knowing sack you can understand this -
	Think of small to large merge operations. For each student maintain a set of all distinct classes in his group , and while 
	merging in dsu, take the smaller set and merge it to the larger set. Also maintain a map<pair,int> to store the answer of the queries (a,b)
	
*/


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;

// using long doubles saves you from corner cases but is very time consuming
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
// just comment the line below in case of interactive problems
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
//vector<vector<int> > v( n , vector<int> (m, 0));


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N=2e5 + 5;
const int MOD=1e9 + 7;

int n;
map<int,int> ans[N];

struct DSU{
	int parent[N],sz[N];
	int connected;
	
	void initi()
	{
		int i;
		for(i=1;i<=n;i++)
		{
			parent[i] =i;
			sz[i]=1;
		}
		connected=n;
	}
	
	int find(int k)
	{
		while(k!=parent[k])
		{
			parent[k]= parent[parent[k]];
			k= parent[k];
		}
		return k;
	}
	
	void merge(int u,int v)
	{
		int r1= find(u);
		int r2 = find(v);
		if(r1==r2)
			return;
		
		connected--;
			
		if(sz[r1]>sz[r2])
		{
			swap(r1,r2);
		}
		// merging the smaller component with the bigger one
		parent[r1] = parent[r2];
		sz[r2] += sz[r1];
		sz[r1]=0;
		// note you copying any element atmost once, not more than that
		// because once a merge happens the smaller set is never visited again as its parent has changed
		// Hence this is not N^2.  
		for(auto it: ans[r1])
			ans[r2][it.F] += it.S;
	}
};


int32_t main()
{
	IOS;
	int T=1;
	//cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		int q;
		cin >> n >> q;
		DSU dsu;
		dsu.initi();
		rep(i,1,n)
		{
			int x;
			cin >> x; 
			ans[i][x]++;
		}
		while(q--)
		{
			int type,l,r;
			cin >> type >> l >> r;
			if(type==1)
				dsu.merge(l,r);	
			else
			{
				int par = dsu.find(l);
				if(ans[par].find(r)!=ans[par].end())
					cout << ans[par][r] << endl;
				else
					cout << "0" << endl;
			}
		}
	}
}

/*
	* while writing bool comp function for sorting put 1 statement in the end which has no if comdition
 	* in case of multiple test cases and N=1e5 don't intialize arrays as global except for graph vector-array
 	* always check whether or not you are doing mod of a negative number
 	* always use 1LL instead of 1
*/
