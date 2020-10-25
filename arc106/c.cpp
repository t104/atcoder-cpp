#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    if ((2 <= n && n-2 < abs(m)) || m < 0) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> l(n), r(n);
    int x = 0;
    rep(i,n) {
        x += 2;
        l.at(i) = x;
        x += 2;
        r.at(i) = x;
    }
    if (0 < m) {
        r.at(0) += 3;
        r.at(0) += 4 * m;
    }
    if (m < 0) {
        m *= -1;
        l.at(n-1) -= 3;
        l.at(n-1) -= 4*m;
    }
    rep(i,n) {
        printf("%d %d\n", l.at(i), r.at(i));
    }
    return 0;
}