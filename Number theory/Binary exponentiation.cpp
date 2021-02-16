#include<bits/stdc++.h>
using namespace std;

int be(int x,int y)
{
	if(y==0)
	{
		return 1;
	}
	else
	{
		if(y%2==0)
		{
			return be(x*x,y/2);
		}
		else
		{
			return x*be(x*x,(y-1)/2);
		}
	}
}

int main()
{
	cout << be(3,1) << endl;
}
