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

const int N=1e5 + 5;
const int M=1e9 + 7;

vector<string> actual;
vector<string> v;

int check(char c)
{
    if(c>='a' && c<='z')// since everything is in lowercase
        return 0;
    return 1;
}

void printWords(string str) 
{ 
    string word; 
    stringstream iss(str); 
    while (iss >> word) 
    {
    	transform(word.begin(), word.end(), word.begin(), ::tolower); //changing everything to lowercase, comment this if not req
        int x = sz(word);
        int j=0;
        int flag=0;
        rep(i,0,x-1)
        {
            if(check(word[i])==1)// to remove cases like jack,alice .. jack and alice should be other words
            {
                string str = word.substr(j,i-j);// substring starting from pos i of length i-j
                j = i+1;
                flag=1;
                v.pb(str);
            }
        }
        if(flag==0)
    	    v.pb(word);
	} 
} 

int isPalin(string str)// unncessary check palindrome function
{
	int n= str.size();
	int i;
	for(i=0;i < n ;i++)
	{
        if(str[i] != str[n-i-1])
		{
            return 0;
   		} 
	}
	return 1;
}

int32_t main()
{
	IOS;
	//memset(dp,-1,sizeof(dp));
	/* Sample input - 
	Bob hit a ball, the hit BALL flew far after it was hit.
	*/
	int T;
	cin >> T;
	T++;// dunno why you have to do this
	while(T--)
	{
		v.clear();
		string s;
		getline(cin, s); 
		printWords(s); 
		for(string x: v)
		{
			cout << x << " ";
		}
		cout << endl;
	}	
}

