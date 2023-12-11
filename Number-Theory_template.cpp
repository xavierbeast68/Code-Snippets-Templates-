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
 * URL : 
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

/*
    *Thought Process*
    !---------------!
    
*/


#include<bits/stdc++.h>
using namespace std;

#define JULI_OP ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
#define endl '\n'
#define fo(i, a, b) for(int i = a; i <= b; ++i)
#define repl(it, var) for(auto &it : var)
#define all(x) begin(x), end(x)
const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int INF = 1000000000000000005;
template<class T> using v = vector<T>;
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){int sz = a.size();for(int i = 0 ; i < sz; ++i){os << a[i] << " \n"[i==sz-1];}return os;}


// <---------- Global Variables ---------->
int n;
// string s;
// v<int> vec;

// <-------------------------- Helper Functions -------------------------->

// binary exponentiation
/*Recursive->
int binpow(int a, int b){
    if(b == 0) return 1;
    int res = binpow(a, b/2);
    if(b%2 == 0) return res*res;
    return res*res*a;
}
*/

/*Iterative Modular Exponentiation*/
int modExpo(int a, int b, int mod) {
    a %= mod;
    int res = 1;
    
    // binary exponentiation
    // while(b){
    //     if(b%2) res *= a;
    //     a *= a;
    //     b /= 2;
    // }
    
    // faster, modular exponentiation
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// modular arithematic
int _mod(int a, int mod){return (a+mod)%mod;}
// based on fermat-little theorem, mod should be prime, TC->O(log2(mod))
// 1/a = a^(mod-2)
int modInv(int a, int mod){return modExpo(_mod(a, mod), mod-2, mod);} 
int modAdd(int a, int b, int mod){return (_mod(a, mod) + _mod(b, mod))%mod;}
int modSub(int a, int b, int mod){return (_mod(a, mod) - _mod(b, mod))%mod;}
int modMul(int a, int b, int mod){return (_mod(a, mod) * _mod(b, mod))%mod;}
int modDiv(int a, int b, int mod){return modMul(_mod(a, mod), modInv(_mod(b, mod), mod), mod);}

// primality test
bool isPrime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}
// sieve of eratosthenes
int build = 0;
vector<bool> prime;
int sz = 1e6+5;
void buildSieve(){
    if(build == 1) return;
    build = 1;
    prime.resize(sz, true);
    prime[0] = prime[1] = false;
    
    for(int i = 2; i*i < sz; ++i){
        if(prime[i] == true){
            for(int j = i*i; j < sz; j += i){
                prime[j] = false;
            }
        }
    }
}
// Prime Factorization
vector<int> factors(int n){
    vector<int> facts;
    for(int d = 2; d*d <= n; d++){
        while(n%d == 0){
            facts.push_back(d);
            n /= d;
        }
    }
    if(n > 1) facts.push_back(n);
    return facts;
}


// <-------------------------- Solve Function -------------------------->

void solve(){

}

// <-------------------------- Main -------------------------->
signed main(){
    
    JULI_OP; // FAST_IO
    
    int testcases = 1;
    // cin >> testcases;
    while(testcases--){
        solve();
    }
    
    return 0;
}