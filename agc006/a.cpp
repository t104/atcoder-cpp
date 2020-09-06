#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    rep(i,n) {
        string subs = s.substr(i, n-i);
        string subt = t.substr(0, n-i);
        if (subs == subt) {
            cout << n + i << endl;
            return 0;
        }
    }

    cout << 2*n << endl;
    return 0;
}