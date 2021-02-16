static auto __io_speed_up = [](){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;  
}();


#define ll              long long
#define pb              push_back
#define vi              vector<int>
#define pii             pair<int,int>
#define vii             vector<pii>
#define mi              map<int,int>
#define mii             map<pii,int>
#define all(a)          (a).begin(),(a).end()
#define repp(i,a,b)     for(int i=a;i<b;i++)
#define rep(i,a,b) 	    for(int i=a;i<=b;i++)
#define deb1(x)      	cout << #x << "=" << x << endl
#define deb2(x, y)  	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z)  	cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define trace(v) 		for(auto it=v.begin();it!=v.end();it++)cout<<*it<<" ";cout<<endl;
#define tracearr(a,l,r) for(int iii=l;iii<=r;iii++)cout << a[iii] << " ";cout << endl;
#define F 				first
#define S 				second
#define clr(x,y) 		memset(x, y, sizeof(x))
//2d- vector ---> vector<vector<int> > v( n , vector<int> (m, 0));

const int N=1e5 + 5;
const int M=1e9 + 7;

