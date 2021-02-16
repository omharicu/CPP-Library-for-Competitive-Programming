#include<bits/stdc++.h>
using namespace std;


#define int long long


const int M = 1e9 + 7;
#define ll long long

ll me(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	else
	{
		if(y%2==0)
		{
			return me((x*x)%M,y/2);
		}
		else
		{
			return (x*me((x*x)%M,(y-1)/2))%M;
		}
	}
}
int32_t main()
{
	cout << me(3,4) << endl;
}
