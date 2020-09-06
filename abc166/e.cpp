#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int count = 0;
    rep(i, n) cin >> a.at(i);
    rep(i, n-1) {
        for(int j = i + a.at(i); j < n; j++) {
            if(n <= j) break;
            ll dif = (ll) abs(i - j);
            ll h = (ll) a.at(i) + a.at(j);
            if(dif == h) count++;
        }
    }
    cout << count << endl;
    return 0;
}