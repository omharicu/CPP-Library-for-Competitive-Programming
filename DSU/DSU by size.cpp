#include<bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const int N=1e5 + 5;

// This is global for now. You can also pass it initi if you don't want in global
int n;


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
	}
};

int32_t main()
{
	int i;
	DSU dsu;
	n = 5;
	dsu.initi();
	cout << dsu.find(1) << endl; // return 1
	cout << dsu.find(5) << endl; // return 5 as everyone is the root of itself
	
	cout << dsu.connected << endl;// 5 diff sets
	
	dsu.merge(1,2);// 1,2 are int the same set now and 2 is the root
	cout << dsu.find(1) << endl;// return 2
	cout << dsu.find(2) << endl;// 2 is the root of its own group;
	
	cout << dsu.connected << endl;// 4 diff sets
	
	dsu.merge(4,3);
	cout << dsu.find(4) << endl;// return 3;
	
	cout << dsu.connected << endl;// return 3
	
	dsu.merge(4,2);//1,2,3,4 are in the same set and 2 is the root of all
	cout << dsu.find(3) << endl;
	cout << dsu.find(1) << endl;
	cout << dsu.find(4) << endl;
	cout << dsu.find(2) << endl;// all returns 2
	
	cout << dsu.connected << endl;// 2 diff sets
}
