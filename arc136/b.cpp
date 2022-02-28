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

void ng() {
    cout << "No" << endl;
    exit(0);
}

void turn(vector<int> &a, int i) {
    vector<int> x(3);
    for(int j = 0; j < 3; ++j) {
        x[j] = a[i + j];
    }
    for(int j = 0; j < 3; ++j) {
        a[i + (j + 1) % 3] = x[j];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    if(n == 3) {
        rep(_, 3) {
            bool ok = true;
            rep(j, n) {
                if(a[j] != b[j])
                    ok = false;
            }
            if(ok) {
                cout << "Yes" << endl;
                return 0;
            }
            turn(a, 0);
        }
        ng();
    }
    map<int,int> mpa, mpb;
    rep(i,n) {
        mpa[a[i]]++;
        mpb[b[i]]++;
    }
    for (auto [i, cnt]: mpa) {
        if (mpb.count(i) && mpb[i] == cnt) {

        } else {
            ng();
        }
    }
    cout << "Yes" << endl;

    return 0;
}
