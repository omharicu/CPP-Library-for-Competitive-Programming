#include<bits/stdc++.h>
using namespace std;

vector<int> find_factors(int f)
{
	int i;
	vector<int> vec;	
	for(i=1;i*i<=f;i++)
	{
		if(f%i==0)
		{
			if(i*i==f)
			{
				vec.pb(i);
			}
			else
			{
				vec.pb(i);
				vec.pb(f/i);
			}
		}
	}
	sort(all(vec));
	return vec;
}

int isPrime(int f)
{
	int i;
	int cc=0;
	for(i=2;i*i<=f;i++)
	{
		if(f%i==0)
		{
			if(i*i==f)
			{
				cc++;
			}
			else
			{
				cc=cc+2;
			}
		}
	}
	if(cc==0)
		return 1;
	return 0;
}

int main()
{
	int N;
	cin >> N;
	int c= isPrime(N);
	if(c==0)
	{
		cout << "prime" << endl;
	}
	else
	{
		cout << "not " <<endl;
	}
	cout << c << endl; // will give the no. factors(excluding the no. itself and excluding 1)
}
