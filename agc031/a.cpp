#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }
using ll = long long;
using P = pair<int,int>;
using mint = modint1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    map<char,int> mp;
    rep(i,n) mp[s.at(i)]++;
    mint ans = 1;
    for (auto p : mp) {
        ans *= (p.second + 1);
    }
    ans--;
    cout << ans.val() << endl;
    return 0;
}