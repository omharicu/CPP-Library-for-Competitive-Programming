/*
	Longest common subsequence between two arrays both of size 1 to 1e5. One has unique elements other has duplicate elements - 
	Question - https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
	Solution - https://leetcode.com/submissions/detail/437891082/
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string s1,s2;
int n,m;

int sub(int i, int j)
{
	if(i>=n || j>=m)
	{
		return 0;
	}
	else if(s1[i]==s2[j])
	{
		return 1 + sub(i+1,j+1);
	}
	else
	{
		return max(sub(i+1,j),sub(i,j+1));
	}
}
int32_t main()
{
	cin >> s1;
	cin >> s2;
	n= s1.size();
	m = s2.size();
	cout << sub(0,0) << endl;
}
