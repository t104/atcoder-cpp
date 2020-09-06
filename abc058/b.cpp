#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string o, e;
    cin >> o >> e;
    rep(i, o.size()) {
        cout << o.at(i);
        if(i < e.size()) cout << e.at(i);
    }
    cout << endl;

    return 0;
}