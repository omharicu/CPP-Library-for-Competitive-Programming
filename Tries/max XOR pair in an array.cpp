/*
O(n) soln- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91049/Java-O(n)-solution-using-bit-manipulation-and-HashMap
	
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


const int N=1e5 + 5;
const int MOD=1e9 + 7;

class Trie{
public:
	Trie* left; // 0
	Trie* right; // 1
};

void insert(int val, Trie* head)
{
	// unecessary but done if in case head is global
	Trie* cur = head;
	for(int i=31;i>=0;i--)
	{
		int curBit = val&(1<<i); // 31 means MSB
		if(curBit==0)
		{
			if(cur->left==NULL)
				cur->left = new Trie(); 
			cur = cur->left;
		}
		else
		{
			if(cur->right==NULL)
				cur->right = new Trie();
			cur = cur->right;
		}
	}	
}

int maxXORpair(int val,Trie* head)
{
	int ans = 0;
	// unecessary but done if in case head is global
	Trie* cur = head;
	for(int i=31;i>=0;i--)
	{
		int curBit = val&(1<<i);
		if(curBit==0)
		{
			if(cur->right!=NULL)// 1 exists in this node
			{
				ans += (1<<i); // add 2^bitposition to answer
				cur = cur->right;// move to right
			}
			else
				cur = cur->left; // forcibly moved here. xor becomes 0 in this case
		}
		else
		{
			if(cur->left!=NULL)
			{
				ans += (1<<i);
				cur = cur->left;
			}
			else
				cur = cur->right;
		}
	}
	return ans;
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
		int n;
		cin >> n;
		int a[n+5];
		Trie* head = new Trie();
		rep(i,1,n)
		{
			cin >> a[i];
			insert(a[i],head);
			// here it self you can call the maxXORpair func with a[i] but only after inserting it else runtime error
		}
		int max_xor = INT_MIN;
		rep(i,1,n)
		{
			int cur_xor = maxXORpair(a[i],head);
			max_xor = max(cur_xor,max_xor);
		}
		cout << max_xor;
	}
}
