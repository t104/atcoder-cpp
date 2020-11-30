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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), p(n), q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    rep(i,n) p[i]--, q[i]--;
    rep(i,n) a[i] = i;
    int pi = 0, qi = 0, idx = 0;
    do {
        bool isP = true, isQ = true;
        rep(i,n) {
            if (p[i] != a[i]) isP = false;
            if (q[i] != a[i]) isQ = false;
        }
        if (isP) pi = idx;
        if (isQ) qi = idx;
        idx++;
    } while (next_permutation(a.begin(), a.end()));
    cout << abs(pi - qi) << endl;
    return 0;
}