#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;

    int d = abs(a-b);

    int q = d/(v+w);
    int r = d % (v+w);
    if(v == w) {
        if(r == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return 0;
    }

    int i = 1;
    while (i * abs(v-w) < v+w) {
        int r1 = r + abs(v-w);
        if(r1 % (v+w) == 0) {   
            if(q+i <= t) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            return 0;
        }
        i++;
    }
    cout << "NO" << endl;
    return 0;
}