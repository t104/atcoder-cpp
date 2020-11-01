#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    mint ans = 1;
    vector<int> p;
    rep(i,n) {
        if (i < n-1 && s1.at(i) == s1.at(i+1)) {
            p.push_back(1);
            ++i;
        }
        else p.push_back(0);
    }
    if (p.at(0) == 0) ans *= 3;
    if (p.at(0) == 1) ans *= 6;
    int len_p = p.size();
    for (int i = 1; i < len_p; ++i) {
        if (p.at(i-1) == 0) {
            if (p.at(i) == 0) ans *= 2;
            if (p.at(i) == 1) ans *= 2;
        }
        if (p.at(i-1) == 1) {
            if (p.at(i) == 0) ans *= 1;
            if (p.at(i) == 1) ans *= 3;
        }
    }
    cout << ans.val() << endl;
    return 0;
}