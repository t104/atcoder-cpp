#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string t;
    cin >> t;

    for(int i = 0; i < t.size(); i++) {
        if(t.at(i) == '?') {
            t.replace(i, 1, "D");
        }
    }
    cout << t << endl;
    return 0;
}