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
using P = pair<ll,ll>;

using Mat = vector<vector<ll>>;

Mat operator*(Mat a, Mat b) {
    int n = a.size();
    int l = b.size();
    int m = b[0].size();
    Mat ans(n, vector<ll>(m, 0));
    rep(i,n) {
        rep(j,l) {
            rep(k,m) {
                ans[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return ans;
}

int main() {
    int n, x, y, m, q;
    vector<Mat> points, mats;
    cin >> n;
    rep(i,n) {
        cin >> x >> y;
        points.push_back({{x}, {y}, {1}});
    }
    
    cin >> m;

    mats.push_back({{1,0,0}, {0,1,0}, {0,0,1}});
    rep(i,m) {
        int op;
        cin >> op;
        if (op == 1) {
            mats.push_back(Mat {{0,1,0}, {-1,0,0}, {0,0,1}} * mats.back());
        }
        if (op == 2) {
            mats.push_back(Mat{{0,-1,0}, {1,0,0}, {0,0,1}} * mats.back());
        }
        if (op == 3) {
            int p;
            cin >> p;
            mats.push_back(Mat{{-1, 0, 2*p}, {0,1,0}, {0,0,1}} * mats.back());
        }
        if (op == 4) {
            int p;
            cin >> p;
            mats.push_back(Mat{{1,0,0}, {0,-1,2*p}, {0,0,1}} * mats.back());
        }
    }

    cin >> q;
    rep(i,q) {
        int a, b;
        cin >> a >> b;
        --b;
        auto ans = mats[a]*points[b];
        cout << ans[0][0] << ' ' << ans[1][0] << endl;
    }
    return 0;
}