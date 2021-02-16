// try to solve fenwick tree in 1 indexed bit 
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
const int M=1e9 + 7;

int bit[N];
int n,q;

// 1 indexed code . idx = 0 can never be updated by this code
void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

// update in case of 0 indexed  bit tree-
/* 
void update(int idx, int val)
{
	idx++;
    while(idx<n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}*/

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
	IOS; // always use IOS in fenwick problems
	int T;
	T=1;
	for(int i_T=1;i_T<=T;i_T++)
	{	
		//cout << "Case #" << i_T << ": ";
		cin >> n >> q;
		memset(bit,0,sizeof(bit));	
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x; 
			update(i,x); //intially all was zero, now we are updating position i with x which is same as taking input( 0+x = 0)
		}
		while(q--)
		{
			int type;
			cin >> type; //type=1 for updating idx by x , type=2 to find sum in between l,r
			if(type==1)
			{
				int idx,val;
				cin >> idx >> val;
				// let prev value at position idx be prev. New value will be prev + val
				update(idx,val); 
			}
			else
			{
				int l,r;
				cin >> l >> r;
				cout << rangeSum(l,r) << endl;
			}
		}
	}
}

