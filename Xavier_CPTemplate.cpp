/**
 * CODER=> xavierbeast68
 * Problem : From
 * Date : DD-MM-YYYY
 * URL : Problem-Link
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


/*--GCC Optimizations--*/
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") // platform with no avx2 support, switch out the avx2 with avx


#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define endl                            '\n'
#define cendl                           cout<<endl
#define int                             long long
#define read(x)                         int x; cin >> x;
#define fastio                          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


/*--Aliases--*/
using ll                                = long long;
using ull                               = unsigned long long;
using ld                                = long double;
#define vi                              vector<int>
#define vll                             vector<ll>
#define pii                             pair<ll,ll>
#define ump                             unordered_map
#define pq_max                          priority_queue<ll>
#define pq_min                          priority_queue<ll,vi,greater<ll>>

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
#define allr(x)                         rbegin(x), rend(x)
#define asc(c)                          c.begin(),c.end()
#define des(c)                          c.begin(),c.end(),greater<int>()
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


/*--Operation on bits--*/
/*
#define lshift(x)                       x<<=1     // x*2
#define rshift(x)                       x>>=1     // x/2
#define odd(x)                          x & 1     // true if x%2==1
#define setbit(num,pos)                 num |= (1 << pos)     // set a bit at 'pos' position in the number ‘num'
#define unsetbit(num,pos)               num &= (~(1 << pos))  // unset a bit at 'pos' position in the number ‘num'
#define togglebit(num,pos)              num ^= (1 << pos)     // turn bit ‘on'(1) if it was ‘off'(0)
#define invert(num)                     ~num  // Inverting every bit of num/1’s complement. Add 1 for 2's complement
*/

/*--Print Functions--*/
//std outputs
#define print(x)                        cout<<(x)
#define println(x)                      cout<<(x)<<endl

/*--Debug--*/
#ifndef ONLINE_JUDGE
#define debug(x)                        cerr <<"<==Testing(#"<<x<<")==>"<< endl
#else
#define debug(x)
#endif


/*--InputOutputError_From/To_File*/
void file_io()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);
#endif
}


/*--Execution Time macro-1--*/
// void execTime()                      {cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;}

/*--Execution Time macro-2--*/
clock_t startClock()
{
#ifndef ONLINE_JUDGE
    clock_t start = clock();
    return start;
#endif
}
void endClock(clock_t start)
{
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cerr << "Execution time : " << time_taken << "secs";
#endif
}


/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b)                      {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                      {return a / gcd(a, b) * b;}
ll max(ll a, ll b)                      {return a > b ? a : b;}
ll min(ll a, ll b)                      {return a < b ? a : b;}
ll countDigit(ll n)                     {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b)          {return log2(a) / log2(b);}
ll isPowerof2(ll x)                     {return (x && !(x & (x - 1)));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a)                     {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)
ll factorial(const int& p)              {if (p <= 1) {return 1;} return p * factorial(p - 1);}
// bool isPrime(const long long& p)        {if (p == 4) {return false;} /*(p - 1) ! ≡  (p-1) mod p*/ ll a = factorial(p - 1) % p; if (a == p - 1) {return true;} return false;}    //Using Wilson Primality Test->O(N)
bool isPrime(ll n)                      {if (n == 2 || n == 3) {return true;} if (n <= 1 || n % 2 == 0 || n % 3 == 0) {return false;}/* To check through all numbers of the form 6k ± 1*/ for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) {return false;}} return true;} // O(sqrt(N))
ll binpow(ll a , ll b)                  {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % MOD, b / 2);} else {return (a * binpow((a * a) % MOD, b / 2)) % MOD;}}
ll binomial_Coefficient(ll n, ll r)     {ll n_fact= factorial(n);ll r_fact= factorial(r);ll nmr_fact= factorial(n-r);return (n_fact/(r_fact*nmr_fact));}

ll mod(ll x)                            {return ((x % MOD + MOD) % MOD);}
// ll addMOD(ll a, ll b)                {return (mod(a)+mod(b));}
// ll mul(ll a, ll b)                   {return (mod(a)*mod(b));}

/*-----------------------------------Template Classes-----------------------------------*/

template <class T>
vector<T> readvector(T n)
{
    vector<T> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}// vector<ll> arr = readvector(n);

template <class T>
void printvector(vector<T> arr, T n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/


void solve()
{
    /*--Let's Code--*/
}

signed main()
{
    fastio;
    //file_io();

    // clock_t start=startClock();

    /*t=1: default value for single test case*/
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    //endClock(start);

    fflush(stdout);

    return 0;
}