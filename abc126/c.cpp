#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int head(int base, int k) {
    int dst = 0;
    while(base < k) {
        base *= 2;
        dst++;
    }
    return dst;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> heads(n);
    ll sum = 0;
    int p = head(1,k);
    rep(i,n) sum += 1<<(p-head(i+1,k));
    ll d = (1<<p) * n;

    cout << std::fixed << std::setprecision(15);
    cout << (double) sum/d << endl;
    return 0;
}