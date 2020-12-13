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
    cin >> n;
    string ans;
    vector<int> r(3);
    rep(i,3) {
        r.at(i) = n % 36;
        n /= 36;
    }
    for (int i = 2; 0 <= i; --i) {
        if (ans.size() == 0 && 0 < i && r.at(i) == 0) continue;
        if (r.at(i) <= 9) ans.push_back('0' + r.at(i));
        else ans.push_back('A' + r.at(i) - 10);
    }
    cout << ans << endl;
    return 0;
}