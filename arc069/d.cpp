#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL << 60)
#define rep(i, n) for(int i = 0; i < (n); ++i)
template <typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    return a > b && (a = b, true);
}
template <typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2, typename T3>
inline bool in(T1 val, T2 l, T3 r) {
    return l <= val && val < r;
}
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int n;
string s;
void write(vector<int> &zoo) {
    rep(i, n) {
        if(zoo[i] == 0)
            cout << 'S';
        else
            cout << 'W';
    }
    cout << endl;
    exit(0);
}

bool same(int i, char c) {
    return (i == 0 && c == 'o') || (i == 1 && c == 'x');
}

bool test(vector<int> &zoo) {
    for (int i = 1; i < n; ++i) {
        int next;
        if (same(zoo[i], s[i])) {
            next = zoo[i-1];
        }
        else {
            next = (zoo[i-1]+1)%2;
        }
        int j = (i+1)%n;
        if (zoo[j] == -1) zoo[j] = next;
        else if (zoo[j] != next) return false;
    }
    return true;
}

int main() {
    cin >> n >> s;

    rep(z0, 2) {
        rep(i,2) {
            vector<int> zoo(n,-1);
            zoo[0] = z0;
            if (same(z0, s[0])) {
                zoo[1] = i;
                zoo[n-1] = i;
            }
            else {
                zoo[1] = i;
                zoo[n-1] = (i+1)%2;
            }

            if (test(zoo)) {
                write(zoo);
            }
        }
    }

    cout << -1 << endl;
    return 0;
}