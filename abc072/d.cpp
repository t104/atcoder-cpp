#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    rep(i,n) {
        int p;
        cin >> p;
        if (i + 1 == p) {
            ans++;
            cin >> p;
            ++i;
        }
    }
    cout << ans << endl;
    return 0;
}