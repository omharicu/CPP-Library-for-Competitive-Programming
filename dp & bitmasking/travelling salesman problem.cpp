#include<bits/stdc++.h>
using namespace std;

/*

Time Complexity - O(n^2 * 2^n)

Input - 
This is the cost matrix.

4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0

Output - 
85

*/


const int N = 11;
const int maxx = 1<<N + 5;

int dp[N][maxx];
int cost[N][N];
int n;
int tot;

int solve(int node,int mask)
{
	if(mask==tot)
		return cost[node][0];
	int& ans = dp[node][mask];
	if(ans!=-1)
		return ans;
	ans = INT_MAX;
	for(int j=0;j<n;j++)
	{
		if( (mask&(1<<j)) == 0 )
		{
			ans = min(ans,cost[node][j] + solve(j,mask|(1<<j)));	
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> cost[i][j];		
		}
	}
	tot = (1<<n) - 1;
	memset(dp,-1,sizeof(dp));
	// sending mask = 1 as you have already visited node 0.
	cout << solve(0,1) << endl;
		
}
