#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    const int count = 6;
    vector<int> a(count);
    rep(i, count) cin >> a.at(i);
    sort(a.begin(), a.end());
    cout << a.at(3) << endl;
    return 0;
}