#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a.at(i) >> b.at(i);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(n%2 == 1) {
        int r = b.at(n/2);
        int l = a.at(n/2);
        cout << r-l+1 << endl;
    }
    else {
        int r = b.at(n/2) + b.at(n/2 - 1);
        int l = a.at(n/2) + a.at(n/2 - 1);
        cout << r-l+1 << endl;
    }
    return 0;
}