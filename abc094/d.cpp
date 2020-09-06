#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(), a.end());
    int a_max = a.at(n-1);
    int b = -1, d = 1e9;
    rep(i,n-1) {
        int half = a_max%2 == 0 ? a_max/2 : a_max/2 + 1;
        int di = abs(half - a.at(i));
        if (di < d) {
            d = di;
            b = a.at(i);
        }
    }
    cout << a_max << ' ' << b << endl;
    return 0;
}
