//https://leetcode.com/problems/longest-increasing-subsequence/
//https://leetcode.com/problems/longest-increasing-subsequence/discuss/74855/Short-C%2B%2B-STL-based-solution%3A-O(n-log-n)-time-O(1)-space-with-explanation


/*
	Longest common subsequence between two arrays both of size 1 to 1e5. One has unique elements other has duplicate elements - 
	Question - https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
	Solution - https://leetcode.com/submissions/detail/437891082/
*/

#include<bits/stdc++.h>
using namespace std;

#define int         long long
#define IOS         ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

//O(n^2) typical dp

/*
int lengthOfLIS(vector<int>& v) 
{
    int n = v.size();
    vector<int> dp(n,1);
    int ans = 0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(v[i] > v[j])
                dp[i] = max(dp[i],1+dp[j]);
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}*/

//0(nlogn) Binary search solution , O(n) space complexity // see above leetcode solution link for more info

/*
int lengthOfLIS(vector<int>& v) 
{
    int n = v.size();
    if(n==0)
        return 0;
    vector<int> res;
    for(int x:v)
    {
        auto it = lower_bound(res.begin(),res.end(),x);
        if(it==res.end())
            res.push_back(x);
        else
            *it = x;
    }
    return (int)res.size();
} 
*/

// O(nlogn) with space - O(1). see the article for more explanation

int lengthOfLIS(vector<int>& v) 
{
    int n = v.size();
    if(n==0)
        return 0;
    auto it = v.begin();
    for(int x: v)
    {
        auto f = lower_bound(v.begin(),it,x);
        *f = x;
        if(f==it)
            it++;
    }
    return it - v.begin();
}

// length of Longest Non Decreasing Sequence - 

//Just change lower_bound to upper_bound in the most optimal soln above 
// this doesnt work on the O(n) space soln above that

int lengthOfLNDS(vector<int>& v) 
{
	int n = v.size();
    if(n==0)
        return 0;
    auto it = v.begin();
    for(int x: v)
    {
        auto f = upper_bound(v.begin(),it,x);
        *f = x;
        if(f==it)
            it++;
    }
    return it - v.begin();
}


int32_t main()
{
	IOS;
	vector<int> v = {10,9,2,5,3,7,101,18};
	cout << lengthOfLIS(v) << endl;
	v = {1,1,1,1,1};
	cout << lengthOfLNDS(v) << endl;
}

