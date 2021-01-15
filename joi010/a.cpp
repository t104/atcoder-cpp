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
using P = pair<int,int>;
const map<char,int> mp = {
    {'J', 0},
    {'O', 1},
    {'I', 2}
};

int sum[1005][1005][3];

int main() {
    int h, w;
    cin >> h >> w;
    int q;
    cin >> q;
    vector<string> input(h);
    rep(i,h) cin >> input[i];
    rep(i,h) {
        rep(j,w) {
            sum[i+1][j+1][mp.at(input.at(i).at(j))]++;
        }
    }

    rep(i,h+1) {
        rep(j,w) {
            rep(k,3) {
                sum[i][j+1][k] += sum[i][j][k];
            }
        }
    }
    rep(j,w+1) {
        rep(i,h) {
            rep(k,3) {
                sum[i+1][j][k] += sum[i][j][k];
            }
        }
    }

    rep(i,q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vector<int> cnt(3);
        rep(j,3) {
            cnt[j] = sum[c][d][j] - sum[c][b-1][j] - sum[a-1][d][j] + sum[a-1][b-1][j];
        }
        printf("%d %d %d\n", cnt[0], cnt[1], cnt[2]);
    }

    return 0;
}