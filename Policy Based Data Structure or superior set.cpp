//Use of PBDS with pair - https://codeforces.com/contest/1042/problem/D
// Solution - https://codeforces.com/contest/1042/submission/62598690

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
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

 
typedef
tree<
  int,// change the datatype to int,char,pair<int,int> whatever
  null_type,
  less<int>,//change the datatype here too if you want
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
 
int32_t main()
{
    IOS;
    ordered_set X;
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);
    
    //find_by_order(k) gives us the (k+1)th largest number in the set (the smallest element is 1st largest)
    cout << "Use of find_by_order:-" << endl;
    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true or say 1
    
    //order_of_key(k) gives us number of items in the set which are strictly smaller than k
    cout << "Use of order_of_key-" << endl;
    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
    
    X.erase(16);
    cout<<X.order_of_key(400)<<endl; // 4 (Since 16 has been erased)
}
