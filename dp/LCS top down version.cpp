#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N=1e3 + 5;

int cache[N][N];
string s1,s2;
int n,m;

int sub(int i, int j)
{
	if(i>=n || j>=m)
	{
		return 0;
	}
	else if(s1[i]==s2[j] && cache[i][j]==-1)
	{
		return cache[i][j]= 1 + sub(i+1,j+1);
	}
	else if(s1[i]==s2[j] && cache[i][j]!=-1)
	{
		return cache[i][j];
	}
	else if(cache[i][j]==-1)
	{
		return cache[i][j]= max(sub(i+1,j),sub(i,j+1));
	}
	else
	{
		return cache[i][j];
	}
}

int32_t main()
{
	cin >> s1;
	cin >> s2;
	n= s1.size();
	m = s2.size();
	int i;
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cache[i][j]=-1;
		}
	}
	cout << sub(0,0) << endl;
}
