//Problem - https://codeforces.com/contest/1341/problem/D
// Video Solution - https://www.youtube.com/watch?v=0TmuETwVit4
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

const int N=2005;
const int M=1e9 + 7;

string inttos(int num)
{
    return to_string(num);
}

int stoint(string sss)
{
    return stoi(sss);
}

vector<string> nums;
int n,k;
int changes[N][12];
int dp[N][N];
string ans = "";

void findans(int i,int sum)
{
	if(i==n)
		return;
	for(int j=9;j>=0;j--) // reverse for loop because we want the lexographically biggest string
	{
		int req = changes[i][j];
		if(req!=-1 && req<=sum && dp[i+1][sum-req]==1)
		{
			char c = '0' + j;
			ans += c;
			findans(i+1,sum-req);
			return;
		}
	}
}	

int solve(int i,int sum)
{
	if(i==n)
	{
		if(sum==0)
			return dp[i][sum] = 1;
		else
			return dp[i][sum] = 0;
	}
	if(sum<0)
		return dp[i][sum] = 0;	
	if(dp[i][sum]!=-1)
		return dp[i][sum];
	int maxx = 0;
	for(int j=0;j<=9;j++)
	{
		int req = changes[i][j];
		if(req!=-1 && req<=sum)
			maxx = max(maxx,solve(i+1,sum-req)); // can use OR too as we just need to see if this transition is possible. 
												// 0 is not possible , 1 is possible
	}
	return dp[i][sum] = maxx;
}

int check(string s1,string s2)
{
	int c=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]=='1' && s2[i]=='0')
		{
			return -1;
		}
		if(s1[i]!=s2[i])
		{
			c++;
		}
	}
	return c;
}

int32_t main()
{
	IOS;
	memset(dp,-1,sizeof(dp));	
	nums = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<=9;j++)
		{
			int x = check(s,nums[j]);
			changes[i][j] = x;
		}
	}
	solve(0,k);
	findans(0,k);
	if(ans.size()==0)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}

