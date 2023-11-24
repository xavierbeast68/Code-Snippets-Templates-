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
 * URL : Problem_URL
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#ifndef XAVIERBEAST
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#endif

#include <bits/stdc++.h>
using namespace std;

//*---------------------------------------------Alias-----------------------------
#define endl                                        '\n'
#define cendl                                       cout << endl;
#define int                                         long long
using ld                                            = long double;


//*------------------------------------------Constants---------------------------
constexpr int MOD1                                  = 1e9 + 9; //1000000009
constexpr ld EPS                                    = 1e-9;
constexpr ld PI                                     = 3.1415926535897932384626;


//*-------------------------------------------Macros-------------------------------
#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)
#define read(x)                                     cin >> x;    
#define readInt(x)                                  int x; cin >> x; // reads long long
#define readStr(x)                                  string x; cin >> x; // reads string(word)
#define readLine(x)                                 string x; getline(cin, x); // reads string(sentence)
#define print(x)                                    cout<<(x)<<" "
#define println(x)                                  cout<<(x)<<endl

// Streams ->
template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a){in >> a.first >> a.second;return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a){os << a.first << " " << a.second;return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){for(int i = 0 ; i < sz(a) ; i++){if(i != 0){os << ' ';}os << a[i];}return os;}


//*--------------------------------------------------------------Debugger Starts--------------------------------------------------------------
//            [di:b^b-ing]
// -Being the detective in a crime
//  where you are also the murderer.

#define test(i)                                     cerr << "(#" << i << ")" << endl

// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
#define dbg(x)                                      cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

// #pragma warning disable format

void _print(int t) {cerr << t;}
// void _print(long long t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]";}
template <class T> void _print(stack <T> v) { cerr << "[ "; while(!v.empty()) { _print(v.top()); v.pop(); cerr << " "; } cerr << "]";}

//*--------------------------------------------------------------Debugger Ends--------------------------------------------------------------

/*-------------------------------------------------------||||||||||-----------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
                                        |H| |e| |r| |e|   |w| |e|   |g| |o| |!| |!| |!|
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------||||||||||------------------------------------------------------------------------*/


/*
    *Thought Process*
    !---------------!

*/

signed main() {
    ios_base::sync_with_stdio(0);   cin.tie(0);
    
    auto __solve_testcase = [&](int testcase) -> void {
        //--Let's Code--

    };
    
    int no_of_tests = 1;   
    // cin >> no_of_tests;
    for(int test_no = 1 ; test_no <= no_of_tests ; test_no++)
        __solve_testcase(test_no);
    
    return 0;
}