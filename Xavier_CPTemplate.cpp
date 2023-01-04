/*
    ▄  ██       ▄   ▄█ ▄███▄   █▄▄▄▄ ███   ▄███▄   ██      ▄▄▄▄▄      ▄▄▄▄▀ 
▀▄   █ █ █       █  ██ █▀   ▀  █  ▄▀ █  █  █▀   ▀  █ █    █     ▀▄ ▀▀▀ █    
  █ ▀  █▄▄█ █     █ ██ ██▄▄    █▀▀▌  █ ▀ ▄ ██▄▄    █▄▄█ ▄  ▀▀▀▀▄       █    
 ▄ █   █  █  █    █ ▐█ █▄   ▄▀ █  █  █  ▄▀ █▄   ▄▀ █  █  ▀▄▄▄▄▀       █     
█   ▀▄    █   █  █   ▐ ▀███▀     █   ███   ▀███▀      █              ▀      
 ▀       █     █▐               ▀                    █                      
        ▀      ▐                                    ▀                       
*/
/**
 * xavierbeast68
 * Problem : From
 * URL : Problem_Link
 * Date : DD-MM-YYYY
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


/*--GCC Optimizations--*/
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") // platform with no avx2 support, switch out the avx2 with avx


#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;


/*--------------------------------------------------------Aliases--------------------------------------------------------*/

#define endl                                       '\n'
#define cendl                                      cout<<endl
#define int                                        long long
#define fastio                                     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using ll                                           = long long;
using ull                                          = unsigned long long;
using lld                                          = long double;
#define vi                                         vector<int>
#define vll                                        vector<ll>
#define pii                                        pair<ll,ll>
#define ump                                        unordered_map
#define pq_max                                     priority_queue<ll>
#define pq_min                                     priority_queue<ll,vi,greater<ll>>

/*--------------------------------------------------------Constants--------------------------------------------------------*/

constexpr ll INF                                    = 2e18;
constexpr lld EPS                                   = 1e-9;
constexpr ll MOD                                    = 1e9 + 7; //1000000007
constexpr ll mod1                                   = 998244353;
constexpr lld PI                                    = 3.14159265358979323846;

/*--------------------------------------------------------Macros--------------------------------------------------------*/

//Loop Macros
#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)
#define FORL(i,a,b)                                 for(int i = a; i <= b; ++i)
#define FORR(i,a,b)                                 for(int i = a; i >= b; --i)
#define rep(i , var)                                for(auto i : var)
//Vector Macros
#define pb                                          push_back
#define eb                                          emplace_back
#define ppb                                         pop_back
//other macros
#define sz(x)                                       (int)(x).size()
#define all(x)                                      begin(x), end(x)
#define allr(x)                                     rbegin(x), rend(x)  // sort(allr(v)) -> reverse sort
#define asc(c)                                      c.begin(),c.end()
#define des(c)                                      c.begin(),c.end(),greater<int>()
#define ff                                          first
#define ss                                          second
#define mp(x,y)                                     make_pair(x,y)
#define sumOf(c)                                    accumulate(c.begin(),c.end(),0)
#define maxOf(c)                                    *max_element(c.begin(),c.end())
#define minOf(c)                                    *min_element(c.begin(),c.end())
#define getUp(s)                                    transform(s.begin(), s.end(), s.begin(), ::toupper);
#define getDown(s)                                  transform(s.begin(), s.end(), s.begin(), ::tolower);
#define lb(arr, x)                                  lower_bound(arr.begin(), arr.end(), x) - arr.begin();
#define ub(arr, x)                                  upper_bound(arr.begin(), arr.end(), x) - arr.begin();

/*--Operation on bits--*/
#define lshift(x)                                   x<<=1     // x*2
#define rshift(x)                                   x>>=1     // x/2
#define odd(x)                                      x & 1     // true if x%2==1
#define setbit(num,pos)                             num |= (1 << pos)     // set a bit at 'pos' position in the number ‘num'
#define unsetbit(num,pos)                           num &= (~(1 << pos))  // unset a bit at 'pos' position in the number ‘num'
#define togglebit(num,pos)                          num ^= (1 << pos)     // turn bit ‘on'(1) if it was ‘off'(0)
#define invert(num)                                 ~num  // Inverting every bit of num/1’s complement. Add 1 for 2's complement (~num, makes +ve -> -ve, (~5)==((~6)+1))


/*------------------------------------------------------Read and Print Macros------------------------------------------------------*/

#define read(x)                                     int x; cin >> x; // reads long long
#define readstr(x)                                  string s; cin >> s; // reads string
#define print(x)                                    cout<<(x)
#define println(x)                                  cout<<(x)<<endl

//InputOutputError_From/To_File ->
void file_io()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

// Vector Read & Print ->
template <class T> vector<T> readvector(T n) { vector<T> arr(n); for (int i = 0; i < n; i++) {cin >> arr[i];} return arr;} // vector<ll> arr = readvector(n);
template <class T> void printvector(vector<T> arr, T n) {for (int i = 0; i < n; i++) {cout << arr[i] << " ";} cout << endl;}


/*----------------------------------------------------------------PBDS----------------------------------------------------------------*/

// Ordered Set & Multiset ->
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ost.find_by_order(x) -> returns pointer, ost.order_of_key(y) -> returns index, (int)ost.size() -> needs to be typecasted
// key y is not in the set but it will show the index number if it was there in sorted array
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// Ordered Map & Multimap ->
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
// om.find_by_order(x)->first, om.find_by_order(x)->second , om.order_of_key({ x, y })
// Pair {x, y1} is not in the map but it will show the index number if it was there in sorted array
typedef tree<pair<int, int>, null_type, less_equal<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multimap;


/*--------------------------------------------------------------Debugger--------------------------------------------------------------*/

#define testing(i)                                  cout << "(#" << i << ")" << endl

#ifndef ONLINE_JUDGE
#define dbg(x)                                      cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
// void _print(auto t) {cerr << *t;} // for ordered_set

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(ordered_set v) {cerr << "[ "; for (int i=0 ; i<(int)v.size();i++) {_print(v.find_by_order(i)); cerr << " ";} cerr << "]";}


/*------------------------------------------------------Functions------------------------------------------------------*/

ll gcd(ll a, ll b)                                  {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                                  {return a / gcd(a, b) * b;}
ll max(ll a, ll b)                                  {return a > b ? a : b;}
ll min(ll a, ll b)                                  {return a < b ? a : b;}
ll countDigit(ll n)                                 {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b)                      {return log2(a) / log2(b);}
ll isPowerof2(ll x)                                 {return (x && !(x & (x - 1)));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a)                                 {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)
ll factorial(const int& p)                          {if (p <= 1) {return 1;} return p * factorial(p - 1);}
// bool isPrime(const long long& p)                 {if (p == 4) {return false;} /*(p - 1) ! ≡  (p-1) mod p*/ ll a = factorial(p - 1) % p; if (a == p - 1) {return true;} return false;}    //Using Wilson Primality Test->O(N)
bool isPrime(ll n)                                  {if (n == 2 || n == 3) {return true;} if (n <= 1 || n % 2 == 0 || n % 3 == 0) {return false;}/* To check through all numbers of the form 6k ± 1*/ for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) {return false;}} return true;} // O(sqrt(N))
ll binpow(ll a , ll b)                              {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % MOD, b / 2);} else {return (a * binpow((a * a) % MOD, b / 2)) % MOD;}}    // binary exponentiation
ll binomial_Coefficient(ll n, ll r)                 {ll n_fact = factorial(n); ll r_fact = factorial(r); ll nmr_fact = factorial(n - r); return (n_fact / (r_fact * nmr_fact));}

ll mod(ll x)                                        {return (((x) % MOD + MOD) % MOD);}
ll mod_add(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a+b));}
ll mod_mul(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a*b)); }
ll mod_sub(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a-b));}

// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r)                      {return uniform_int_distribution<ll>(l, r)(rng); }

// Kickstart->
void google(int t)                                  {cout << "Case #" << t << ": "; }


/*-------------------------------------------------------||||||||||-----------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
                                        |H| |e| |r| |e|   |w| |e|   |g| |o| |!| |!| |!|
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------||||||||||------------------------------------------------------------------------*/

void solve()
{
    /*--Let's Code--*/
}

signed main()
{
    fastio;

    cout << fixed << setprecision(10);
    // file_io();
    auto start = high_resolution_clock::now();

    /*t=1: default value for single test case*/
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    #ifndef ONLINE_JUDGE
        cerr << endl << "Time: " << (float)duration.count()/1000000 << " s" << endl;
    #endif

    fflush(stdout);

    return 0;
}