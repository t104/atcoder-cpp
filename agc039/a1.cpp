#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int count(string s) {
    int n = s.size();
    int c = 1, dst = 0;
    for (int i = 1; i < n; ++i) {
        if (s.at(i-1) == s.at(i)) c++;
        if (s.at(i-1) != s.at(i) || i == n-1) {
            dst += c/2;
            c = 1;
        } 
    }
    return dst;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    ll ans = 0;
    if (k <= 4) {
        string t;
        rep(i, k) t += s;
        ans = count(t);
    }
    else {
        string t2 = s + s;
        string t3 = s + s + s;
        string t4 = s + s + s + s;
        int c2 = count(t2);
        int c3 = count(t3);
        int c4 = count(t4);
        ans = (ll) c2 + (ll) ((k-2)/2) * (c4-c3) + (ll) ((k-2)/2 + (k-2)%2) * (c3-c2);
    }
    cout << ans << endl;
    return 0;
}