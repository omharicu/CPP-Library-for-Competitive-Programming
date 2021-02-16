//https://codeforces.com/problemset/problem/161/A
// multimap deletes only one, multiset deletes all
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5 +5;

int n,m,x,y;
vector<int> vn;
vector<pair<int,int>> vm;
set<int> s;
multimap<int, int> mp;  
map<int,int> mpp;

int32_t main()
{
	IOS;
	cin >> n >> m >> x >> y;
	int i;
	for(i=0;i<n;i++)
	{
		int xx;
		cin >> xx;
		vn.push_back(xx);
	}
	for(i=0;i<m;i++)
	{
		int yy;
		cin >> yy;
		s.insert(yy);
		mp.insert({yy,i+1});
		mpp[yy]++;
	}
	for(i=0;i<n;i++)
	{
		int xx= max(1LL,(vn[i]-x));
		int yy= min(1000000000LL,(vn[i]+y));
		auto p= s.lower_bound(xx);
		auto q= s.upper_bound(yy);
		if(p!=q)
		{
			q--;
			auto it = mp.find(*p);
			mpp[*p]--;
			if(mpp[*p]==0)
			{
				mpp.erase(*p);
				s.erase(*p);	
			}
   			vm.push_back({i+1,it->second});
   			mp.erase(it); 
		}
	}
	cout << vm.size() << endl;
	for(i=0;i<vm.size();i++)
	{
		cout << vm[i].first << " " << vm[i].second << endl;
	}
	
}
