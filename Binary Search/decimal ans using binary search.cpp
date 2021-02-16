//https://codeforces.com/problemset/problem/1010/A
// also see how to cehck whether answer exists or not
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

const int N=1e3 + 5;


int n;
double w;
double a[N];
double b[N];

int check(double x)
{
	double tot = w + x;
	tot = tot - (tot)/a[1];
	rep(i,2,n)
	{
		tot = tot - (tot/b[i]);
		tot = tot - (tot/a[i]);
	}
	tot = tot - (tot)/b[1];
	if(tot>=w)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


double binsearch(double lo, double hi)
{
	rep(i,1,200)
	{
		// for finding min in binary search
		double mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo= mid;
		
		// for finding max in binary search	
		/*
		double mid=(lo+hi+1)>>1;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
		*/	
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n >> w;
	rep(i,1,n)
	{
		cin >> a[i];
		cin >> b[i];	
	}
	double ans = binsearch(0,1e10);// sending value out of range 
	if(ans>1e9)//check whether the answer is within the range or not
	{
		cout << "-1" << endl;//answer doesnt exists
		return 0;
	}
	cout<<fixed<<setprecision(12)<<ans;
}

