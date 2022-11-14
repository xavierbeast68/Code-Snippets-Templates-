/**
 * CODER=> xavierbeast68
 * Problem : From
 * Date : DD-MM-YYYY
 * URL : Problem Link
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


/*--GCC Optimizations--*/
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") // platform with no avx2 support, switch out the avx2 with avx

#include <bits/stdc++.h>
using namespace std;
#define endl                            '\n'
#define cendl                           cout<<endl
#define int                             long long
#define read(x)                         int x; cin >> x;
#define fastio                          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


/*--Aliases--*/
using ll                                = long long;
using ld                                = long double;
#define vi                              vector<int>

/*--Constants--*/
constexpr ll INF                        = 2e18;
constexpr ld EPS                        = 1e-9;
constexpr ll MOD                        = 1e9 + 7; //1000000007
constexpr ll mod1                       = 998244353;
constexpr ld PI                         = 3.14159265358979323846;


/*--Loop Macros--*/
#define FOR(i,a,b)                      for(int i = a; i < b; ++i)
#define FORL(i,a,b)                     for(int i = a; i <= b; ++i)
#define FORR(i,a,b)                     for(int i = a; i >= b; --i)
#define rep(i , var)                    for(auto i : var)
/*--Vector Macros--*/
#define pb                              push_back
#define eb                              emplace_back
#define ppb                             pop_back
/*--other macros--*/
#define sz(x)                           (int)(x).size()
#define all(x)                          begin(x), end(x)
#define ff                              first
#define ss                              second
#define mp(x,y)                         make_pair(x,y)
#define sumOf(c)                        accumulate(c.begin(),c.end(),0)
#define maxOf(c)                        *max_element(c.begin(),c.end())
#define minOf(c)                        *min_element(c.begin(),c.end())
#define getUp(s)                        transform(s.begin(), s.end(), s.begin(), ::toupper);
#define getDown(s)                      transform(s.begin(), s.end(), s.begin(), ::tolower);
#define lb(arr, x)                      lower_bound(arr.begin(), arr.end(), x) - arr.begin();
#define ub(arr, x)                      upper_bound(arr.begin(), arr.end(), x) - arr.begin();


/*--Print Functions--*/
//std outputs
#define print(x)                        cout<<(x)
#define println(x)                      cout<<(x)<<endl


/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b)                      {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                      {return a / gcd(a, b) * b;}
ll max(ll a, ll b)                      {return a > b ? a : b;}
ll min(ll a, ll b)                      {return a < b ? a : b;}
ll countDigit(ll n)                     {return (floor(log10(n) + 1));}
ll factorial(const int& p)              {if (p <= 1) {return 1;} return p * factorial(p - 1);}
bool isPrime(const long long& p)        {if (p == 4) {return false;} /*(p - 1) ! ≡  (p-1) mod p*/ ll a = factorial(p - 1) % p; if (a == p - 1) {return true;} return false;}
ll binpow(ll a , ll b)                  {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % MOD, b / 2);} else {return (a * binpow((a * a) % MOD, b / 2)) % MOD;}}


/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/


void solve()
{
    /*--Let's Code--*/
}

signed main()
{
    fastio;

    /*t=1: default value for single test case*/
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    fflush(stdout);

    return 0;
}