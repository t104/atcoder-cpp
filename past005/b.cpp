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
    string t;
    rep(i,n) {
        int tn = t.size();
        string u = "";
        rep(j,tn) {
            if (t.at(j) == s.at(i)) continue;
            u.push_back(t.at(j));
        }
        t = u;
        t.push_back(s.at(i));
    }
    cout << t << endl;
    return 0;
}