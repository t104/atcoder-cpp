#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL << 60)
#define rep(i, n) for(int i = 0; i < (n); ++i)
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2, typename T3>
inline bool in(T1 val, T2 l, T3 r) {
    return l <= val && val < r;
}
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    if(abs(a) < abs(b)) {
        int sum = 0;
        rep(i, b) {
            cout << -(i + 1) << ' ';
            sum += i + 1;
        }
        rep(i, a - 1) {
            cout << i + 1 << ' ';
            sum -= i + 1;
        }
        cout << sum << endl;
    } else {
        int sum = 0;
        rep(i, a) {
            cout << i + 1 << ' ';
            sum += i+1;
        }
        rep(i,b-1) {
            cout << -(i+1) << ' ';
            sum -= i+1;
        }
        cout << -sum << endl;
    }
    return 0;
}