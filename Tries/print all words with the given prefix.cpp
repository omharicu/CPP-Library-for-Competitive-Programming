/*
	You are given n strings and q queries.
	In each query you are given a string s.
	for each s you have to ouput all those strings among those n which has a prefix as s.
	if no such exists print "No suggestion".
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

/*
// alternate trie structure intialization-
class Trie
{
public:
    Trie *arr[26];
    bool endOfWord;
    Trie()
    {
        memset(arr,NULL,sizeof(arr));
        endOfWord = false;
    }
};
*/


class Trie{
public:
	Trie* arr[26];
	bool endOfWord = false;
};



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

pair<int,Trie*> doExists(string s,Trie* head)
{
	Trie* cur = head;
	for(char c: s)
	{
		if(cur->arr[c-'a']==NULL)
			return {0,NULL};
		cur = cur -> arr[c-'a'];
	}
	return {1,cur};
}

void getAllSuggestions(Trie* head,string cur,string& s)
{
	if(head->endOfWord==true)
		cout << s + cur << endl;
	for(int i=0;i<=25;i++)
	{
		char c = 'a' + i;
		if(head->arr[i]!=NULL)
			getAllSuggestions(head->arr[i],cur+c,s);
	}
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
		cin >> n;
		Trie* head = new Trie();
		rep(i,1,n)
		{
			string s;
			cin >> s;
			insert(s,head);
		}
		cin >> q;
		while(q--)
		{
			string s;
			cin >> s;
			pair<int,Trie*> p = doExists(s,head);
			if(p.F==0)
			{
				cout << "No suggestions" << endl;
				continue;
			}
			getAllSuggestions(p.S,"",s);
		}
	}
}
