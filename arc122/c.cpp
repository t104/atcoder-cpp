#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;

ll n;
vector<ll> fib(100);
vector<int> add;
int m;

ll calc(vector<int> ans) {
    ll x = 0, y = 0;
    for (auto ai: ans) {
        if (ai == 1) x++;
        else if (ai == 2) y++;
        else if (ai == 3) x += y;
        else y += x;
    }
    return x;
}

void init() {
    fib[0] = 1;
    fib[1] = 1;
    rep(i, 100) {
        fib[i+2] = fib[i+1] + fib[i];
        if (1e18 < fib[i+2]) {
            m = i+1;
            break;
        }
    }
}

int main() {
    cin >> n;
    init();

    ll rem = n;
    for (int i = m-1; 0 <= i; --i) {
        if (fib[i] <= rem) {
            rem -= fib[i];
            add.push_back(i);
        }
    }

    vector<int> ans;
    int j = 0;
    rep(i, add[0]) {
        if (i == add[0] - add[j]) {
            if (i%2 == add[0]%2) {
                ans.push_back(1);
            }
            else {
                ans.push_back(2);
            }
            j++;
        }
        if (i%2 == add[0]%2) ans.push_back(4);
        else ans.push_back(3);
    }

    assert(n == calc(ans));
    cout << ans.size() << endl;
    for (auto ai: ans) cout << ai << endl;
    return 0;
}