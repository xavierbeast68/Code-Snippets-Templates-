const int MOD = 1e9 + 7;

long long get_hash(string s){
    long long h = 0;
    for(char c : s){
        h = (h * 31 + (c - 'a' + 1)) % MOD;
    }
    return h;
}