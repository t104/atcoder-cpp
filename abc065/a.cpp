#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int n;

int main() {
    cin >> n;
    vector<int> a(n);
    vector<bool> pushed(n, false);
    rep(i, n) {
        cin >> a.at(i);
        a.at(i)--;
    }
    int p = 0, count = 0;
    while(!pushed.at(p)) {
        if(p == 1) {
            cout << count << endl;
            return 0;
        }
        pushed.at(p) = true;
        p = a.at(p);
        count++;
    }
    cout << -1 << endl;
    return 0;
}