#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    int l = 1;
    rep(i,n) {
        if(l == a.at(i)) l++;
    }
    if(l == 1) cout << -1 << endl;
    else cout << n-l+1 << endl;
    return 0;
}