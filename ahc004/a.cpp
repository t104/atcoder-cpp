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
using P = pair<string,int>;

const int SZ = 20;

int n, m;
vector<string> s;
vector<string> ans(SZ);

void print_ans() {
    for (auto &si : ans) cout << si << endl;
}

int main() {
    cin >> n >> m;
    s.resize(m);
    rep(i,m) cin >> s[i];

    vector<P> cand;

    for (auto &sub: s) {
        bool find = false;
        for (auto &[t, cnt] : cand) {
            if (t.find(sub) != string::npos) {
                cnt++;
                find = true;
                break;
            }
        }
        if (!find) {
            cand.emplace_back(sub, 1);
        }
    }

    sort(cand.begin(), cand.end(), [&](auto x, auto y){
        return y.second < x.second;
    });

    for (auto &[ci, cnt] : cand) {
        rep(i,SZ) {
            if (ans[i].size() + ci.size() <= SZ) {
                ans[i] += ci;
                break;
            }
        }
    }

    rep(i,SZ) {
        ans[i] += string(SZ-ans[i].size(), '.');
    }

    print_ans();
    return 0;
}