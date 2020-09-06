#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    int count = n/x;
    if (n%x != 0) count++;
    cout << t * count << endl;
    return 0;
}