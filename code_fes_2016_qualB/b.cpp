#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    int pass = 0;
    int rankb = 0;
    rep(i, n) {
        if(s.at(i) == 'a') {
            if(pass < a + b) {
                pass++;
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        }
        if(s.at(i) == 'b') {
            if(pass < a + b && rankb < b) {
                pass++;
                cout << "Yes" << endl;
            } else cout << "No" << endl;
            rankb++;
        }
        if(s.at(i) == 'c') {
            cout << "No" << endl;
        }
    }
    return 0;
}