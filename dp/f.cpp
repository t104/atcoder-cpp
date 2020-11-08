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
    string s, t;
    cin >> s >> t;
    int len_s = s.size(), len_t = t.size();
    vector<vector<int>> dp(len_s + 1, vector<int>(len_t + 1));
    for (int i = 1; i <= len_s; ++i) {
        for (int j = 1; j <= len_t; ++j) {
            if (s.at(i) == t.at(i))
                dp.at(i).at(j) = dp.at(i-1).at(j-1) + 1;
            else dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i).at(j-1));
        }
    }
    return 0;
}