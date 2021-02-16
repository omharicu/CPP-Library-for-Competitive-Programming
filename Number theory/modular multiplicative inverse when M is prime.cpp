#include<bits/stdc++.h>
using namespace std;
int me(int x,int y,int M)
{
	if(y==0)
	{
		return 1;
	}
	else
	{
		if(y%2==0)
		{
			return me((x*x)%M,y/2,M);
		}
		else
		{
			return (x*me((x*x)%M,(y-1)/2,M))%M;
		}
	}
}
int main()
{
	int A,M;
	cin >> A >> M;
	cout << me(A,M-2,M);
	
}
