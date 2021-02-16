/*
	Question - 
		Given n,q. You are given n strings.  q is the number of queries
		Each query is of 2 types x , s where x is int ans s is string.
		if x= 1, check if the string s is one of the given n strings. Print 1 if yes else 0
		if x>1 , check if the string s is suffix of any of the given n words. Print 1 if yes else no.
		LC question - https://leetcode.com/problems/implement-trie-prefix-tree/
	
	Input - 
		aqib
		mahboob
		far
		farray
		xxx
		1 a
		1 far
		2 far
		2 mah
		2 mahe
		
	Output - 
		0
		1
		1
		1
		0
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
	Trie* arr[26];
	bool endOfWord = false;
};

/** Inserts a word into the trie. */
void insert(string s,Trie* head) 
{
    Trie* cur = head;
    for(char c: s)
    {
        if(cur->arr[c-'a']==NULL)
            cur -> arr[c-'a'] = new Trie();
        cur = cur -> arr[c-'a'];
    }
    cur->endOfWord = true;
}
    
/** Returns if the word is in the trie. */
bool search(string s,Trie* head) 
{
    Trie* cur = head;
    for(char c: s)
    {
        if(cur->arr[c-'a']==NULL)
            return 0;
        cur = cur->arr[c-'a'];
    }
    return cur->endOfWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool startsWith(string s,Trie* head) 
{
    Trie* cur = head;
    for(char c:s)
    {
        if(cur->arr[c-'a']==NULL)
            return false;
        cur = cur->arr[c-'a'];
    }
    return true;
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
		int n,q;
		cin >> n >> q;
		Trie* head = new Trie();
		rep(i,1,n)
		{
			string s;
			cin >> s;
			insert(s,head);
		}
		while(q--)
		{
			int x;
			string s;
			cin >> x >> s;
			if(x==1)
				cout << search(s,head) << endl;
			else
				cout << startsWith(s,head) << endl;
		}
	}
}
