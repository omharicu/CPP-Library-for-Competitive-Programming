// in case of multiple test cases and N=1e5 don't intialize arrays as global except for graph vector-array
// always check whether or not you are doing mod of a negative number
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
	int count = 0; // count of how many times current node was visited while inserting every number
};

void insert(int val, Trie* head)
{
	Trie* cur = head;
	(cur->count)++;
	for(int i=31;i>=0;i--)
	{
		int curBit = val&(1<<i); 
		if(curBit==0)
		{
			if(cur->left==NULL)
				cur->left = new Trie(); 
			cur = cur->left;
			(cur->count)++;
		}
		else
		{
			if(cur->right==NULL)
				cur->right = new Trie();
			cur = cur->right;
			(cur->count)++;
		}
	}	
}

// val is the current xor
// bit is the bit number we are checking
// flag = 1 means that we are sure current node results in xor less than k and we can simply add the number of leaves of this node to the answer
// flag = 0 means otherwise
int numSub(int val, Trie* head,int bit,int k,int flag)
{
	if(bit==-1)
	{
		if(flag==1)
			return head->count;
		else
			return 0;
	}
	int bitk = k&(1<<bit);
	int bitval = val&(1<<bit);
	int cur = 0;
	if(flag==1)
	{
		return head->count;
	}
	if(bitk==0)
	{
		if(bitval==0)
		{
			if(head->left!=NULL)
				cur += numSub(val,head->left,bit-1,k,0);
		}
		else
		{
			if(head->right!=NULL)
				cur += numSub(val,head->right,bit-1,k,0);
		}
	}
	else
	{
		if(bitval>0)
		{
			if(head->right!=NULL)
				cur += numSub(val,head->right,bit-1,k,1);
			if(head->left!=NULL)
				cur += numSub(val,head->left,bit-1,k,0);
		}
		else
		{
			if(head->right!=NULL)
				cur += numSub(val,head->right,bit-1,k,0);
			if(head->left!=NULL)
				cur += numSub(val,head->left,bit-1,k,1);
		}
	}
	return cur;
}

int32_t main()
{
	IOS;
	int T=1;
	cin >> T;
	// int numOfSetBits = __builtin_popcountll(n);
	std::cout << std::fixed << std::setprecision(12);
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		int a[n+5];
		Trie* head = new Trie();
		int ans = 0;
		int cur = 0;
		rep(i,1,n)
		{
			cin >> a[i];
			cur = cur^a[i];
			if(cur<k)
				ans++;
			if(i>1)
				ans += numSub(cur,head,31,k,0);
			insert(cur,head);
		}
		cout << ans << endl;
	}
}
