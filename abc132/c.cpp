#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d.at(i);

    if(n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(d.begin(), d.end());
    int dif = d.at(n/2) - d.at(n/2 - 1);
    cout << dif << endl;
    return 0;
}