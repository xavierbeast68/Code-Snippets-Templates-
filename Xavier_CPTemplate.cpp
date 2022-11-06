/**
 * CODER=> xavierbeast68
 * Problem : From
 * Date : DD-MM-YYYY
 * URL : Problem Link
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */


#include <bits/stdc++.h>
using namespace std;
#define endl            '\n'
#define cendl           cout<<endl
#define fastio          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int             long long
#define INF             1e18
const int MOD =         1e9 + 7; //1000000007
#define mod1            998244353
#define PI              3.14159265358979323846

/*--short--*/
#define ll              long long
#define ld              long double
#define vi              vector<int>
#define vll             vector<ll>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll>>


/*--Loop Macros--*/
#define FOR(i,a,b)      for(int i = a; i < b; ++i)
#define FORL(i,a,b)     for(int i = a; i <= b; ++i)
#define FORR(i,a,b)     for(int i = a; i >= b; --i)
#define rep(i , var)    for(auto i : var)
/*--Vector Macros--*/
#define pb push_back
#define eb emplace_back
#define ppb pop_back
/*--other macros--*/
#define sz(x)           ((int)(x).size())
#define all(x)          ((x).begin(), (x).end())
#define asc(c)          c.begin(),c.end()
#define des(c)          c.begin(),c.end(),greater<int>()
#define ff              first
#define ss              second
#define mp(x,y)         make_pair(x,y)
#define sumOf(c)        accumulate(c.begin(),c.end(),0)
#define maxOf(c)        *max_element(c.begin(),c.end())
#define minOf(c)        *min_element(c.begin(),c.end())
#define getUp(su)       transform(su.begin(), su.end(), su.begin(), ::toupper);
#define getDown(su)     transform(su.begin(), su.end(), su.begin(), ::tolower);
#define lb(bin, x)      lower_bound(bin.begin(), bin.end(), x) - bin.begin();
#define ub(bin, x)      upper_bound(bin.begin(), bin.end(), x) - bin.begin();


/*--Print Functions--*/
//std outputs
#define print(x)        (cout<<(x))
#define println(x)      (cout<<(x)<<endl)

/*--Debug--*/
#ifndef ONLINE_JUDGE
#define debug(x)        (cerr <<"<==Testing(#"<<x<<")==>"<< endl)
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


/*--Execution Time--*/
void execTime() {cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;}


/*----------------------------------------Functions----------------------------------------*/

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll max(ll a, ll b) {return a > b ? a : b;}
ll min(ll a, ll b) {return a < b ? a : b;}
ll countDigit(ll n) {return (floor(log10(n) + 1));}

ll mod(ll x) { return ((x % MOD + MOD) % MOD);}
// ll addMOD(ll a, ll b) { return (mod(a)+mod(b));}
// ll mul(ll a, ll b) { return (mod(a)*mod(b));}

bool isprime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    if (n % 2 == 0 && n > 2)
    {
        return false;
    }
    if (n % 3 == 0 && n > 3)
    {
        return false;
    }
    for (int i = 5 ; i * i <= n ; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

ll power(ll a , ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    if (b % 2 == 0)
    {
        return power((a * a) % MOD, b / 2);
    }
    if (b % 2 == 1)
    {
        return (a * power((a * a) % MOD, b / 2)) % MOD;
    }
}

/*-----------------------------------Template Classes-----------------------------------*/

template <class T>
vector<T> readvector(T n)
{
    vector<T> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    return arr;
}// vector<ll> arr = readvector(n);

/*-----------------------------------||| Here We Go!!! |||-----------------------------------*/


void solve()
{
    /*--Let's Code--*/

}

signed main()
{

    fastio;
    //file_io();

    /*t=1: default value for single test case*/
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    //execTime();

    fflush(stdout);

    return 0;
}