// https://codeforces.com/blog/entry/78952?#comment-643644

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree{
    
    vector<T> segtree;
    int n;
    T (*join)(T, T);
    T base;
    
    segment_tree(vector<T> &a, T (*merge)(T,T), T defvalue){
        n = a.size();
        join = merge;
        base = defvalue;
        segtree.resize(2 * n);
        
        build(a);
    }
    
    void build(vector<T> &a){
        for(int i = 0; i < n; i++){
            segtree[n + i] = a[i];
        }
        for(int i = n - 1; i >= 1; i--){
            segtree[i] = join(segtree[2 * i], segtree[2 * i + 1]);
        }
    }
    
    void update(int pos, T val){
        // pos += n;
        // segtree[pos] = val;
        // for (; pos > 1; pos >>= 1) segtree[pos>>1] = join(segtree[pos], segtree[pos^1]);
        
        for (segtree[pos += n] = val; pos > 1; pos >>= 1) segtree[pos>>1] = join(segtree[pos], segtree[pos^1]);
    }
    
    T query(int left, int right){
        T res = base; // initialize with default value
        
        for(left += n, right += n; left <= right; left >>= 1, right >>= 1){
            
            // if left is an odd node
            if(left & 1) res = join(res, segtree[left++]);
            
            // if right is an even node
            if(!(right & 1)) res = join(res, segtree[right--]);
        }
        return res;
        
        /*
        for(left += n, right += n+1; left < right; left >>= 1, right >>= 1){
            if(left & 1) res.merge(res, tree[left++]); // if left is an odd node
            if(right & 1) res.merge(res, tree[--right]); // if right is an odd node
        }
        return res;
        */
    }
    void debug(){
        // debugging
        for(int i = 1; i < 2 * n; i++) cout << segtree[i] << " ";
        cout << "\n";
    }
};
int mx(int x, int y){
    return x > y ? x : y;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> hotels(1<<(64 - __builtin_clz(n)));
    for(int i=0;i<n;i++){
        cin>>hotels[i];
    }
    
    segment_tree<int> segtree(hotels, mx, -1e9);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}