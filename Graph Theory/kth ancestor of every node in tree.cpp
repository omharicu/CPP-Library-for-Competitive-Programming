/* Input - 
	7 
	1 2 
	1 3
	2 4 
	2 5
	3 6 
	3 7
	3
	4 1
	6 2
	7 3

	Output - 
	2
	1
	-1
	
	
	This is the tree . Try to analyse the queries and the answer
			1
		   / \
		  2    3
		 /\    /\
		4  5  6 7  	
		
		
	Some explanation here - https://www.geeksforgeeks.org/kth-ancestor-of-a-node-in-an-n-ary-tree-using-binary-lifting-technique/
*/


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
#define clr(x) 			memset(x, 0, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N = 1e5 + 5;
const int height = 20;
int dp[N][height];
int n;

// returns -1 if there is no kth ancestor
int kthancestor(int u, int k) 
{  
    for (int i = 0; i < height; i++) 
    { 
        if (k & (1 << i)) 
        { 
            u = dp[u][i]; 
            if (u == -1) 
                break; 
        } 
    } 
    return u; 
} 
    
int32_t main()
{
	IOS;
	int T=1;
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		cin >> n;
		memset(dp,-1,sizeof(dp));
		rep(j,1,n-1)
		{
			int u,v;
			cin >> u >> v; // u is a parent of v
			dp[v][0] = u; 
	        for (int i = 1; i < height; i++) 
	        { 
	            dp[v][i] = dp[dp[v][i - 1]][i - 1]; 
	            if (dp[v][i] == -1) 
	                break; 
	        } 
		}
		int q;
		cin >> q;
		while(q--)
		{
			int node,k;
			cin >> node >> k;
			cout << kthancestor(node,k) << endl;
		}
	}
}


