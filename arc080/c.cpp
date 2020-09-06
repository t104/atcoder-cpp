#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    int by4 = 0, by2 = 0, odd = 0;
    rep(i,n) {
        int a;
        cin >> a;
        if (a%4 == 0) by4++;
        else if (a%2 == 0) by2++;
        else odd++;
    }
    // cout << by4 << ' ' << by2 << ' ' << odd << endl;
    if (by2 >= 1) odd++;
    if (by4 + 1 < odd) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}