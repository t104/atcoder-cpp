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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int section = 0;
    char prev = 'x';
    rep(i,n) {
        if (s.at(i) != prev) section++;
        prev = s.at(i);
    }
    section = max(1, section - 2*k);
    int ans = n-section;
    cout << ans << endl;
    return 0;
}