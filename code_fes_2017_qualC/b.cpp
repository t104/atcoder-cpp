#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    int all_ptn = 1;
    rep(i,n) all_ptn *= 3;
    int evens = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a%2 == 0) evens++;
    }
    int odd_ptn = 1;
    rep(i, evens) odd_ptn *= 2;
    cout << all_ptn - odd_ptn << endl;
    return 0;
}