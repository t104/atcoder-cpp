#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> d1(n), d2(n);
    rep(i, n) cin >> d1.at(i) >> d2.at(i);
    int zoro = 0;
    rep(i, n) {
        if (d1.at(i) == d2.at(i)) zoro++;
        else zoro = 0;
        if (3 == zoro) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}