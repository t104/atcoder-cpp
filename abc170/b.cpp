#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int x, y;
    cin >> x >> y;
    
    rep(i,x+1) {
        int leg = 4*i + 2*(x-i);
        if(leg == y) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}