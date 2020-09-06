#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int M = 1000005;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> c(M);
    for(int x : a) {
        if(c.at(x) != 0) {
            c.at(x) = 2;
            continue;
        }
        for(int i = x; i < M; i += x) c.at(i)++;
    }
    int ans = 0;
    for(int x : a) {
        if(c.at(x) == 1) ans++;
    }
    cout << ans << endl;

    return 0;
}