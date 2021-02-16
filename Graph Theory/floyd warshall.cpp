/*
4 12
1 2 11
2 1 11
1 4 6
4 1 6
1 3 1
3 1 1
3 4 2
4 3 2
3 2 7
2 3 7
2 4 3
4 2 3

Output - 0 6 1 3
		6 0 5 3
		1 5 0 2
		3 3 2 0
*/

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

const int N=105;

int dist[N][N];
int n,m;

int32_t main()
{
	IOS;	
	cin >> n >> m;
	memset(dist, INT_MAX, sizeof(dist));
	rep(i,1,m)
	{
		int x,y,z;
		cin >> x >> y >> z;
		dist[x][y] = z;
		// dist[y][x] = z in case of bidirectional
	}
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			if(i==j)
			{
				dist[i][j] =0;//self loop =0;
			}
		}
	}
	rep(k,1,n)
	{
		rep(i,1,n)
		{
			rep(j,1,n)
			{
				dist[i][j] = min(dist[i][j], dist[i][k]+ dist[k][j]);
			}
		}
	}
	rep(i,1,n)
	{
		rep(j,1,n)
		{
			cout << dist[i][j] << " ";//shortest path between i and j
		}
		cout << endl;
	}
}
