#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

const int t1 = 1900;
const int t2 = 100;

int main() {
    int n, m;
    cin >> n >> m;
    int t = t1 * m + t2 * (n-m);
    rep(i, m) t *= 2;
    cout << t << endl;
    return 0;
}