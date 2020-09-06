#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    vector<int> b(n);
    rep(i,n){
        int k = i < n-1-i ? n-1-i : i;
        b.at(i) = k * a.at(i);
    }
    rep(i,n) cout << b.at(i) << endl;
    return 0;
}