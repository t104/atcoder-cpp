#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i, m) cin >> a.at(i);

    int tozero = 0, ton = 0;
    rep(i, m) {
        if(x < a.at(i)) ton++;
        if(a.at(i) < x) tozero++;
    }
    cout << min(tozero, ton) << endl;
    return 0;
}