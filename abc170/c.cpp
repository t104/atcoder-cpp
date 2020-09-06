#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int x, n;
    cin >> x >> n;
    vector<bool> list(105, false);
    rep(i,n) {
        int p;
        cin >> p;
        list.at(p) = true;
    }
    if(!list.at(x)) {
        cout << x << endl;
        return 0;
    }
    int upper = x, lower = x;
    while(upper < 101) {
        if(!list.at(upper)) break;
        upper++;
    }
    while(0 <= lower) {
        if(!list.at(lower)) break;
        lower--;
    }
    if(abs(x-lower) <= abs(x-upper)) {
        cout << lower << endl;
    }
    else {
        cout << upper << endl;
    }

    return 0;
}