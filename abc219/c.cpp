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

int main() {
    vector<int> order(26);
    string s;
    cin >> s;
    rep(i,26) {
        order[s[i] - 'a'] = i;
    }
    int n;
    cin >> n;
    vector<string> names(n);
    rep(i,n) cin >> names[i];
    sort(names.begin(), names.end(), [&](string x, string y) {
        int sz = min((int) x.size(), (int) y.size());
        rep(i,sz) {
            if (x[i] != y[i]) {
                return order[x[i] - 'a'] < order[y[i] - 'a'];
            }
        }
        return x.size() < y.size();
    });
    rep(i,n) cout << names[i] << endl;
    return 0;
}

