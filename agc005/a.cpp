#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    string x;
    cin >> x;
    int ns = 0, ans = x.size();
    for (char c : x) {
        if (c == 'S') ns++;
        if (c == 'T' && 0 < ns) {
            ans -= 2;
            ns--;
        }
    }
    cout << ans << endl;
    return 0;
}