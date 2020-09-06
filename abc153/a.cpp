#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int H, A;
    cin >> H >> A;
    int count = 0;
    count = H / A;
    if(H % A != 0) count++;
    cout << count << endl;
    return 0;
}