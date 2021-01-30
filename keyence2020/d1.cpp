#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using pint = pair<int,int>;
const int INF = 1<<29;

int N;
vector<int> A, B;

int solve() {
    vector<vector<int>> dp((1<<N)+1, vector<int>(55, INF));
    dp[0][0] = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        int con = 0;
        // con = いくつの bit が立っているか
        for (int i = 0; i < N; ++i) if (bit & (1<<i)) ++con;
        
        // bit に含まれない残りの要素が何番目に対応するか
        vector<pint> ords;
        int iter = con;
        for (int i = 0; i < N; ++i)
            if (!(bit & (1<<i)))
                ords.emplace_back(i, iter++);

        for (int s = 0; s <= 50; ++s) {
            if (dp[bit][s] >= INF) continue;
            for (auto p : ords) {
                // p.first: もともとの a の index
                // p.second: dp[bit][s] の状態での index
                int ns = -1;
                if (abs(p.first - con) % 2 == 0) ns = A[p.first];
                else ns = B[p.first];

                if (ns >= s) {
                    chmin(dp[bit|(1<<p.first)][ns], dp[bit][s] + abs(p.second - con));
                }
            }
        }
    }
    int res = INF;
    for (int s = 0; s <= 50; ++s) chmin(res, dp[(1<<N)-1][s]);
    if (res < INF) return res;
    else return -1;
}

int main() {
    cin >> N;
    A.resize(N), B.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    cout << solve() << endl;
}