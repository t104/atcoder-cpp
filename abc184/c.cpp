#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

bool reach(ll x1, ll y1, ll x2, ll y2) {
    if (x1+y1 == x2+y2) return true;
    if (x1 - y1 == x2 - y2) return true;
    if (abs(x1 - x2) + abs(y1 - y2) <= 3) return true;
    return false;
}

int main() {
    ll sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;

    if (sx == gx && sy == gy) {
        cout << 0 << endl;
        return 0;
    }

    if (reach(sx, sy, gx, gy)) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = -2; i <= 2; ++i) {
        for (int j = -2; j <= 2; ++j) {
            if (reach(sx+i, sy+j, gx, gy)) {
                cout << 2 << endl;
                return 0;
            }
        }
    }

    vector<P> d = {
        {3,0}, {0, 3}, {-3, 0}, {0, -3}
    };

    for (auto di : d) {
        if (reach(sx+di.first, sy+di.second, gx, gy)) {
            cout << 2 << endl;
            return 0;
        }
    }

    if (((sx+sy) % 2) == ((gx+gy) % 2)) {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;
    return 0;
}