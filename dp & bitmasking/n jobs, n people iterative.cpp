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
	//memset(dp,1e7,sizeof(dp)); this doesnt work , maually intialize the dp array
	for(int i=0;i<(1<<n);i++ )
		dp[i] = INT_MAX;
	dp[0]=0;
	for(int mask=0;mask<(1<<n)-1;mask++)
	{
		int idx = __builtin_popcount(mask); // counting number of bits set till now. if 1 bit is set means the 0th person has been assigned 
		//the job and now the 1st person will be assigned. 
		for(int j=0;j<n;j++)
		{
			if((mask&(1<<j))==0) // if the current bit is unset it can be assigned
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + a[idx][j]); // mask|1<<j makes the jth set, choosing min of its previous one
				// and the current mask + the cost of this job done by the idxth person.
		}
	}
	cout << dp[(1<<n)-1] << endl; // answer stored in all 1111, all jobs done.
}
