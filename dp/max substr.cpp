#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll lcs(string p, string q, ll n ,ll m)
{
	ll result=0;
	if(n==0 || m==0)
	{
		result = 0;
	}
	else if(p[n-1]==q[m-1])
	{
		result = 1+ lcs(p,q,n-1,m-1);
	}
	else if(p[n-1]!=q[m-1])
	{
		ll temp = lcs(p,q,n-1,m);
		ll temp1 = lcs(p,q,n,m-1);
		result = max(temp,temp1);
	}
	return result;
}
int main()
{
	string s, s2;
	cin >> s;	
	cin >> s2;
	cout << "the rec soln is -" << lcs(s,s2,s.size(),s2.size());
}

