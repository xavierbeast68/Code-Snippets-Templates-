#include <bits/stdc++.h>
using namespace std;

struct Hash
{
    const int p1 = 31, m1 = 1e9 + 7;
    const int p2 = 37, m2 = 1e9 + 9;
    int hash1 = 0, hash2 = 0;
    Hash(const string &s)
    {
        compute_hash1(s);
        compute_hash2(s);
    }

    void compute_hash1(const string &s)
    {
        long p_pow = 1;
        for (char ch : s)
        {
            hash1 = (hash1 + (ch + 1 - 'a') * p_pow) % m1;
            p_pow = (p_pow * p1) % m1;
        }
    }

    void compute_hash2(const string &s)
    {
        long p_pow = 1;
        for (char ch : s)
        {
            hash2 = (hash2 + (ch + 1 - 'a') * p_pow) % m2;
            p_pow = (p_pow * p2) % m2;
        }
    }

    // For two strings to be equal
    // they must have same hash1 and hash2
    bool operator==(const Hash &other)
    {
        return (hash1 == other.hash1 && hash2 == other.hash2);
    }
};

int main()
{
    const string s = "geeksforgeeks";
    Hash h(s);
    cout << "Hash values of " << s << " are: ";
    cout << "(" << h.hash1 << ", " << h.hash2 << ")" << '\n';
    return 0;
}