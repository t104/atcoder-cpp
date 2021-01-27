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
using P = pair<int,int>;

const ll MX = 1000000000000001;

int main() {
    ll n;
    cin >> n;
    vector<char> ans;
    while (0 < n) {
        if (n%26 == 0) {
            ans.push_back('z');
            n--;
        }
        else ans.push_back('a' + n%26 - 1);
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c;
    cout << endl;
    return 0;
}