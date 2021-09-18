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

const int n = 4;
vector<P> d = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};

bool ok2(int flg) {
    rep(sh, n) rep(sw, n) {
        int idx = sh * n + sw;
        if ((flg>>idx)&1) {
            queue<P> que;
            que.emplace(sh, sw);
            int visited = 1<<idx;
            while (que.size()) {
                auto [hi, wi] = que.front(); que.pop();
                for (auto[dh, dw]: d) {
                    int nh = hi + dh;
                    int nw = wi + dw;
                    int jdx = nh*n + nw;
                    if (in(nh, 0, n) && in(nw, 0, n) && ((flg>>jdx&1)) && ((~visited>>jdx)&1)) {
                        visited |= 1<<jdx;
                        que.emplace(nh, nw);
                    }
                }
            }
            return visited == flg;
        }
    }
    return false;
}

// bool ok1(int flg) {
//     rep(i,n) rep(j,n) {
//         int idx = i*n + j;
//         if ((~flg>>idx)&1) {
//             int c = 0;
//             for (auto [dh, dw]: d) {
//                 int nh = i + dh;
//                 int nw = j + dw;
//                 if (in(nh, 0, n) && in(nw, 0, n)) {
//                     c += (flg>>(nh*n + nw)&1);
//                 }
//                 if (c == 4) return false;
//             }
//         }
//     }
//     return true;
// }

bool ok1(int flg) {
    int visited = 0;
    for (int i: {0, n-1}) {
        rep(j,n) {
            int idx = i*n + j;
            if ((~flg>>idx)&1) {
                visited |= 1<<idx;
                queue<P> que;
                que.emplace(i,j);
                while (que.size()) {
                    auto [hi, wi] = que.front(); que.pop();
                    for (auto[dh, dw]: d) {
                        int nh = hi + dh;
                        int nw = wi + dw;
                        int jdx = nh*n + nw;
                        if (in(nh, 0, n) && in(nw, 0, n) && ((~flg>>jdx&1)) && ((~visited>>jdx)&1)) {
                            visited |= 1<<jdx;
                            que.emplace(nh, nw);
                        }
                    }
                }
            }
        }
    }
    for (int j: {0,n-1}) {
        for (int i : {1,2}) {
            int idx = i*n + j;
            if ((~flg>>idx)&1) {
                visited |= 1<<idx;
                queue<P> que;
                que.emplace(i,j);
                while (que.size()) {
                    auto [hi, wi] = que.front(); que.pop();
                    for (auto[dh, dw]: d) {
                        int nh = hi + dh;
                        int nw = wi + dw;
                        int jdx = nh*n + nw;
                        if (in(nh, 0, n) && in(nw, 0, n) && ((~flg>>jdx&1)) && ((~visited>>jdx)&1)) {
                            visited |= 1<<jdx;
                            que.emplace(nh, nw);
                        }
                    }
                }
            }
        }
    }
    rep(i,16) {
        if (((~flg>>i)&1) != ((visited>>i)&1)) return false;
    }
    return true;
}

void print(int flg) {
    rep(i,n) {
        rep(j,n) {
            cout << ((flg>>(i*n+j))&1) << ' ';
        }
        cout << endl;
    }
    cout << "========================" << endl;
}

int main() {
    int flg = 0;
    rep(i, n*n) {
        int x;
        cin >> x;
        if (x) flg |= 1<<i;
    }
    int ans = 0;
    rep(i, 1<<16) {
        if ((flg&i) < flg) continue;
        if (ok1(i) && ok2(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

