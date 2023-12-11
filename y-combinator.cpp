#include<bits/stdc++.h>
using namespace std;


// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
/*
 Y combinator is a well-known high-order function used to implement recursion.
 Y combinator, accompanied by C++14 generic lambdas, provides a convenient way to define recursive lambda functions.
*/

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main(){
    
    auto gcd = y_combinator([](auto gcd, int a, int b) -> int {
        return b == 0 ? a : gcd(b, a % b);
    });
    cout << gcd(20, 30) << endl;
    
    return 0;
}