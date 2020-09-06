#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int d = n % 10;
    if(d == 2 || d == 4 || d == 5 || d == 7 || d == 9) {
        cout << "hon" << endl;
    } else if(d == 0 || d == 1 || d == 6 || d == 8) {
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }
    return 0;
}