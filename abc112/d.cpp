#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

vector<int> enum_divisors(int n) {
    vector<int> res;
    for (int i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.rbegin(), res.rend());
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> divisors = enum_divisors(m);
    for (int d : divisors) {
        if (m/d >= n) {
            cout << d << endl;
            return 0;
        }
    }
    return 0;
}