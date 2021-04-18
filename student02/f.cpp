#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

template <typename T>
vector<T> compress(vector<T> &x) {
    vector<T> vals = x;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    rep(i, (int) x.size()) {
        x[i] = lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin();
    }
    return vals;
}

using BIT = fenwick_tree<ll>;

const int MX = 220000;
int N, M, Q;
vector<int> T(MX), X(MX), Y(MX);
vector<int> A(MX), B(MX);
BIT a_cnt(MX), b_cnt(MX);
BIT a_tot(MX), b_tot(MX);

int main() {
    cin >> N >> M >> Q;
    rep(i,Q) cin >> T[i] >> X[i] >> Y[i];

    auto ZY = compress(Y);
    a_cnt.add(0, N);
    b_cnt.add(0, M);

    ll ans = 0;
    rep(q, Q) {
        int x = X[q] - 1;
        int y = Y[q];
        if (T[q] == 1) {
            ans -= b_cnt.sum(0, A[x] + 1) * ZY[A[x]];
            ans -= b_tot.sum(A[x] + 1, MX);

            a_cnt.add(A[x], -1);
            a_tot.add(A[x], -ZY[A[x]]);

            A[x] = y;

            ans += b_cnt.sum(0, A[x] + 1) * ZY[A[x]];
            ans += b_tot.sum(A[x] + 1, MX);

            a_cnt.add(A[x], 1);
            a_tot.add(A[x], ZY[A[x]]);
        }
        else {
            ans -= a_cnt.sum(0, B[x] + 1) * ZY[B[x]];
            ans -= a_tot.sum(B[x] + 1, MX);

            b_cnt.add(B[x], -1);
            b_tot.add(B[x], -ZY[B[x]]);

            B[x] = y;

            ans += a_cnt.sum(0, B[x] + 1) * ZY[B[x]];
            ans += a_tot.sum(B[x] + 1, MX);

            b_cnt.add(B[x], 1);
            b_tot.add(B[x], ZY[B[x]]);
        }
        cout << ans << endl;
    }

    return 0;
}