#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(q);
    rep(i, q) {
        cin >> a.at(i);
        a.at(i)--;
    } 
    vector<int> point(n, k - q);
    rep(i, q) {
        point.at(a.at(i))++;
    }
    rep(i, n) {
        if(point.at(i) > 0) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}