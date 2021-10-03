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

using mint = modint998244353;

const int MX = 300010;

int op (int x, int y) {
    return min(x, y);
}

int e () {
    return INF;
}

int main() {
    int n;
    cin >> n;
    vector<P> a(n);
    vector<int> compressed(n);
    rep(i,n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int rank = 0, prev = a[0].first;
    rep(i,n) {
        if (a[i].first != prev) rank++;
        compressed[a[i].second] = rank;
        prev = a[i].first;
    }
    vector<int> first(MX, -1);
    mint ans = 0;
    rep(i,n) {
        rep(j, compressed[i] + 1) {
            if (0first[j]) {
                ans += i - first[j];
            }
        }
        first[compressed[i]] = i;
    }
    cout << ans.val() << endl;
    return 0;
}

