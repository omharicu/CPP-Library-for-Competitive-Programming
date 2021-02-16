#include<bits/stdc++.h>
using namespace std;

#define int long long

string removeZeroesfromfront(string s)
{
	int j=0;
	while(s[j]=='0')
		j++;
	string ans = s.substr(j,s.size()-j);
	if(ans.size()==0)
		ans="0";
	return ans;
}

string intoBinString(int x)
{
	string s;
	// will give a 64 bit string
	for(int i =  63; i >= 0; i--)
		s += (x >> i & 1) + '0';
	// removing zeroes from front
	s = removeZeroesfromfront(s);
	return s;
}

// note int means long long here
// for LC, change int to ll
int binStringtodec(string s)
{
	int val=0;
	for(auto &it:s)
			val = val * 2 + (it - '0');
	return val;
}

// to find remainder of string x when divided by x -
/*
int binStringtodec(string s,int x)
{
	int val=0;
	for(auto &it:s)
	{
		val = val * 2 + (it - '0');
		val = val%x;
	}
	return val;
}
*/




int32_t main()
{
//    std::string binary = std::bitset<32>(1000000000).to_string(); //to binary--> this will give string of size 32.
//    // this conversion will work fine till 1e9 .. abouve that number use bitset<64>
//    std::cout<<binary<<"\n";
//
//    unsigned long decimal = std::bitset<32>(binary).to_ulong();
//    int dec= decimal;
//    std::cout<<dec<<"\n";


		string s = "1000";
		cout << binStringtodec(s) << endl;
		
		cout << intoBinString(0) << endl;
}
