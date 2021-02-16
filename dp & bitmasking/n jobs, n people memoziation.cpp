// Given an array where there are n people and n jobs
// 
//		J1 J2 J3 J4
//	P1	10  2  6  5	
//	P2	1  15 12  8 
//	P3	7   8  9  3
//	P4  15 13  4  10

// person P takes a[p][j] time to do j job as given in the matrix. You can assign one job to only one person and a person can do only 1 job
// Find the min cost to get the job done.

/*
Input - 
	4
	10  2  6  5	
	1  15 12  8 
	7   8  9  3
	15 13  4  10

Output -
	10
*/	


#include<bits/stdc++.h>
using namespace std;

const int N = 20;
const int totSize = 1<<N + 5;

int n;
int a[N][N];
int dp[totSize];

// idx denotes the person which has to be assignned a task.
// We don't need this in the dp array because we dont care which person will be assigned a job
// We just need to check the states of the job which is represented by the mask 

//ALWAYS USE IDX AS A DP STATE---->>>>>>>>>
// HERE IT IS NOT GIVEN
int minCost(int idx,int mask) // but usually we need idx as a dp state
{
	if(idx==n)
		return 0;
	if(dp[mask]!=-1)
		return dp[mask];
	int ans = INT_MAX;
	for(int j=0;j<n;j++) // checking for all jobs
	{
		if((mask&(1<<j))==0) // jth bit in mask is 0, means it hasn't been assigned. if it is greater than 0 it meams it has been assigned.
		{
			ans = min(ans,minCost(idx+1,mask|1<<j)+a[idx][j]); // assign it as it is no assigned. and make the jth bit on.
		}
	}
	return dp[mask] = ans;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
		}	
	}	
	memset(dp,-1,sizeof(dp));
	cout << minCost(0,0) << endl;
	// cout << dp[0] << endl; why is answer stored at dp[0]?
}
