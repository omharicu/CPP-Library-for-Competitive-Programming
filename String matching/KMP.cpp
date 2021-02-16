/*
KMP Application - 
Problem where we only need prefix_funtion-
Question - https://leetcode.com/problems/longest-happy-prefix/
Solution - https://leetcode.com/submissions/detail/314752775/
Video to understand KMP - https://www.youtube.com/watch?v=GTJr8OvyEVQ

Rabin Karp Application -  
Find the longest duplicate substring in a string -
Question - https://leetcode.com/problems/longest-duplicate-substring/
Solution - https://leetcode.com/submissions/detail/355800942/
Explanation - https://www.youtube.com/watch?v=qQ8vS2btsxI

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string &s) 
{
	int n = (int)s.length();
	vector<int> pi(n); // pi[0] = 0;
	for (int i = 1; i < n; i++) 
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

// I don't understand this function-
vector<int> find_occurences(string &text, string &pattern)
{
	string cur=pattern + '#' + text;
	int sz1=text.size(), sz2=pattern.size();
	vector<int> v;
	vector<int> lps=prefix_function(cur);
	for(int i=sz2+1;i<=sz1+sz2;i++)
	{
		if(lps[i]==sz2)
			v.push_back(i-2*sz2);
	}
	return v;
}

int main()
{
	string text = "aaa";
	string pattern = "aa";
	vector<int> v = find_occurences(text,pattern);
	for(int x:v)
	{
		cout << x << " ";
	}
	cout << endl;
}
