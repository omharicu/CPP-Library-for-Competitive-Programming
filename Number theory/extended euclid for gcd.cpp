#include<bits/stdc++.h>
using namespace std;
int d,x,y;
void exEuclid(int a,int b)
{
	if(b==0)
	{
		d=a;
		x=1;
		y=0;
	}
	else
	{
		exEuclid(b,a%b);
		int temp=x;
		x=y;
		y = temp -(a/b)*y;
	}
}
int main()
{
	exEuclid(36,60);
	cout << "the gcd is " << d << endl;
	cout << "x= " << x << endl;
	cout << "y= " << y << endl;
}
