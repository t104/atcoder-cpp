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

int h, w;

bool overlay(vector<string> &s, vector<string> &t) {
    int th = t.size(), tw = t.at(0).size();
    rep(i, h-th+1) rep(j, w-tw+1) {
        bool ok = true;
        rep(ti, th) {
            rep(tj, tw) {
                if (t.at(ti).at(tj) == '#' && s.at(i+ti).at(j+tj) == '#')
                    ok = false;
            }
        }
        if (ok) return true;
    }
    return false;
}

vector<string> rotate(vector<string> &stamp) {
    int sh = stamp.at(0).size();
    int sw = stamp.size();
    vector<string> res(sh, string(sw, '.'));
    rep(i,sh) {
        rep(j, sw) {
            res.at(i).at(j) = stamp.at(sw-j-1).at(i);
        }
    }
    return res;
}

void print(vector<string> &vs) {
    rep(i,vs.size()) {
        cerr << vs.at(i) << endl;
    }
}

int main() {
    cin >> h >> w;
    vector<string> s(h), t(h);
    rep(i,h) cin >> s.at(i);
    rep(i,h) cin >> t.at(i);

    int hmin = INF, wmin = INF;
    int hmax = 0, wmax = 0;
    rep(i,h) rep(j,w) {
        if (t.at(i).at(j) == '.') continue;
        chmin(hmin, i);
        chmax(hmax, i);
        chmin(wmin, j);
        chmax(wmax, j);
    }
    vector<string> tsub(hmax-hmin+1);
    rep(i,hmax-hmin+1) rep(j,wmax-wmin+1) {
        tsub.at(i).push_back(t.at(hmin + i).at(wmin + j));
    }
    
    rep(i,4) {
        if (overlay(s, tsub)) {
            cout << "Yes" << endl;
            return 0;
        }
        tsub = rotate(tsub);
    }

    cout << "No" << endl;
    return 0;
}