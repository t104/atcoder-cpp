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

vector<vector<int>> a;

void rotate(int i) {
    rep(j,3) {
        a[i][j] = (a[i][j] + 1) % 3;
    }
    if (0 < i && a[i][0] == 0) {
        rotate(i-1);
    }
}

int main() {
    int n, l;
    cin >> n >> l;
    a.resize(l, {0, 1, 2});
    a[0] = {2, 1, 0};
    vector<string> ans;
    while (ans.size() < 3 * n) {
        rep(i, 3) {
            string ai;
            rep(j, l) {
                char c = '0' + a[j][i];
                ai.push_back(c);
            }
            ans.push_back(ai);
        }
        rotate(l-1);
    }
    sort(ans.begin(), ans.end());
    for (auto ai: ans) cout << ai << endl;
    return 0;
}