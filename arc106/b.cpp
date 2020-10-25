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
    vector<int> a(n), b(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) cin >> b.at(i);
    dsu uf(n);
    rep(i,m) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        uf.merge(c,d);
    }
    for (auto g : uf.groups()) {
        ll suma = 0, sumb = 0;
        for (int i : g) {
            suma += a.at(i);
            sumb += b.at(i);
        }
        if (suma != sumb) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}