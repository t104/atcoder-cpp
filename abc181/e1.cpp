#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL<<60;
int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> X(N), W(M);
    for (int i = 0; i < N; ++i) cin >> X[i];
    for (int i = 0; i < M; ++i) cin >> W[i];
    sort(X.begin(), X.end());

    vector<long long> left(N+1, 0), right(N+1, 0);
    for (int i = 2; i < N; i += 2) {
        left[i] = left[i-2] + X[i-1] - X[i-2];
        right[i] = right[i-2] + X[N-i+1] - X[N-i];
    }
    long long res = INF;
    for (auto w : W) {
        int i = lower_bound(X.begin(), X.end(), w) - X.begin();
        if (i % 2 == 0) chmin(res, left[i] + right[N-i-1] + X[i] - w);
        else chmin(res, left[i-1] + right[N-i] + w - X[i-1]);
    }
    cout << res << endl;
}