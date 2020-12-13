#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

bool compare(string x, string y) {
    int nx = x.size(), ny = y.size();
    int lx = 0, ly = 0;
    while (lx < nx) {
        if (x.at(lx) != '0') break;
        ++lx;
    }
    while (ly < ny) {
        if (y.at(ly) != '0') break;
        ++ly;
    }
    if (nx - lx != ny - ly) return nx - lx < ny - ly;
    while (lx < nx && ly < ny) {
        if (x.at(lx) != y.at(ly)) {
            return x.at(lx) < y.at(ly);
        }
        ++lx, ++ly;
    }
    return y.size() < x.size();
}

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);
    
    // cerr << compare(s.at(0), s.at(1)) << endl;

    sort(s.begin(), s.end(), compare);
    rep(i,n) cout << s.at(i) << endl;
    return 0;
}