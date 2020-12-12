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
    string s;
    cin >> n >> s;
    vector<int> pos;
    int p = 0;
    while(true) {
        p = s.find('#', p);
        if (p == string::npos) break;
        pos.push_back(p);
        ++p;
    }
    // for(auto pi : pos) cerr << pi << endl;
    int ansx = pos.at(0);
    int ansy = n - 1 - pos.back();
    int ans = ansx + ansy;
    int pn = pos.size();
    rep(i, pn-1) {
        chmax(ans, pos.at(i+1) - pos.at(i) - 1);
    }
    cout << ans - ansy << ' ' << ansy << endl;
    return 0;
}