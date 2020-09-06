#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;

    int count = 0;
    int tap = 1;
    while (tap < b) {
        tap +=  a - 1;
        count++;
    }
    cout << count << endl;
    return 0;
}