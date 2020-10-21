#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    set<string> st;
    rep(l,n) {
        for (int len = 1; l + len <= n && len <= k; ++len) {
            string in = s.substr(l,len);
            st.insert(in);
        }
    }
    for (auto x : st) {
        k--;
        if (k==0) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}