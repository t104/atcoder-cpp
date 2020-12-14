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

vector<vector<ll>> comb(int n, int r) {
    vector<vector<ll>> v(n+1, vector<ll>(n+1, 0));
    rep(i, v.size()) {
        v.at(i).at(0) = 1;
        v.at(i).at(i) = 1;
    }
    for (int j = 1; j < v.size(); ++j) {
        for (int k = 1; k < j; ++k) {
            v.at(j).at(k) = v.at(j-1).at(k-1) + v.at(j-1).at(k);
        }
    }
    return v;
}


int main() {
    int l;
    cin >> l;
    auto c = comb(l-1, 11);
    cout << c.at(l-1).at(11) << endl;
    return 0;
}