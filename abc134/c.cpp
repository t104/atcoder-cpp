#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    vector<int> b = a;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int max1 = a.at(0);
    int max2 = a.at(1);
    rep(i, n) {
        if(b.at(i) == max1) {
            cout << max2 << endl;
        }
        else {
            cout << max1 << endl;
        }
    }

    return 0;
}