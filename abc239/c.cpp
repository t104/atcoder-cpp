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
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<P> d;
    for (auto i: {-1, 1}) {
        for (auto j: {-1, 1}) {
            d.emplace_back(i, 2*j);
            d.emplace_back(2*i, j);
        }
    }
    for (auto [i1, j1]: d) {
        for (auto [i2, j2]: d) {
            int X1 = x1 + i1;
            int Y1 = y1 + j1;
            int X2 = x2 + i2;
            int Y2 = y2 + j2;
            if (X1 == X2 && Y1 == Y2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

