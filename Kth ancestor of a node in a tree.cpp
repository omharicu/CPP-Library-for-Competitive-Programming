/*
	// LC question - https://leetcode.com/contest/weekly-contest-193/problems/kth-ancestor-of-a-tree-node/
	i/p -
	n - number of edges , number of queries 
	n-1 numbers where a[i] denotes the parent of i
	Asumming 1 has no parent
	
	i/p1-
	4 4
	1 2 3
	
	1
	\
	2
	\
	3
	\
	4
	
	
	i/p2-
	8 5
	1 1 3 4 4 3 4
	
	The tree -
				1
			  /   \
			 2 	   3
				   /\
				  4  7	
				/ ! \
				5 6 8
	
	
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
#define clr(x,y) 		memset(x, y, sizeof(x))
#define IOS         	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// *s.find_by_order(1) - gives the 2nd samllest element in set
// s.order_of_key(x)   - gives the number of elements in the set which are strictly smaller than x


const int N=5e5 + 5;
const int MOD=1e9 + 7;

int n;
vector<int> g[N];
int table[N][20]; 
// should be greater than logN base 2
int height=20; 

void calculateSparse(int u, int v) 
{ 
    table[v][0] = u; 
    for (int i = 1; i < height; i++) 
    { 
        table[v][i] = table[table[v][i - 1]][i - 1];            
        if (table[v][i] == -1) 
            break; 
    } 
} 


int kthancestor(int V, int k) 
{  
    for (int i = 0; i < height; i++) 
    { 
        if (k & (1 << i)) 
        { 
            V = table[V][i]; 
            if (V == -1) 
                break; 
        } 
    } 
    return V; 
} 

// returns the kth parent of node 
// if doesnt exists return -1
// 
int getKthAncestor(int node, int k) 
{
    int ans= kthancestor(node, k);
    if(ans<0)
        return -1;
    return ans;
}


int32_t main()
{
	//IOS;
	int T;
	//cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	for(int i_T=1;i_T<=T;i_T++)
	{	
		int q;
		cin >> n >> q;
		rep(i,0,n+1)
		{
			g[i].clear();
		}
		memset(table,-1,sizeof(table));
		rep(i,2,n)
		{
			int x;
			cin >> x;
			// x is the parent of node i
		    calculateSparse(x,i); 
		}
		//For i/p 1 - 
		while(q--)
		{
			cout << "Enter the node id and k - " << endl;
			int x ,y;
			cin >> x >> y;
			cout << getKthAncestor(x,y) << endl;
		}
	}
}

