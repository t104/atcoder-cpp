#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> vt(N);
    rep(i, N) cin >> vt.at(i);
    sort(vt.begin(), vt.end());
    reverse(vt.begin(), vt.end());
    if(N <= K) {
        cout << 0 << endl;
        return 0;
    }
    ll count = 0;
    for(int i = K; i < N; ++i) {
        count += vt.at(i);
    }
    cout << count << endl;
    return 0;
}