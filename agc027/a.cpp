#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    sort(a.begin(), a.end());
    int count = 0;
    rep(i, n-1) {
        if(x >= a.at(i)) {
            x -= a.at(i);
            count++;
        } else break;
    }
    if(x == a.at(n-1)) count++;
    cout << count << endl;
    return 0;
}