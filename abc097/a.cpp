#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int maxN = 1005;

int main() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << 1 << endl;
        return 0;
    }
    rep(i,n) {
        for (int j=2; j<32; ++j) {
            int ni = n-i;
            int c = 0;
            while (ni % j == 0) {
                ni /= j;
                c++;
            }
            if (ni == 1 && c >= 2) {
                cout << n-i << endl;
                return 0;
            }
        }
    }

    return 0;
}