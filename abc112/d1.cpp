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
    int n, m;
    cin >> n >> m;
    vector<int> factors;
    for (int i = 1; i*i <= m; ++i) {
        if (m%i == 0) {
            factors.push_back(i);
            if (m/i != i) factors.push_back(m/i);
        }
    }
    sort(factors.rbegin(), factors.rend());
    for (int f: factors) {
        if (f <= m/n) {
            cout << f << endl;
            return 0;
        }
    }
    return 0;
}