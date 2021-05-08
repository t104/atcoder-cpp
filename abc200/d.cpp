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

int n;
vector<ll> a;

void print_vec(vector<int> vt) {
    int n = vt.size();
    cout << n << ' ';
    rep(i,n) {
        cout << vt[i]+1;
        if (i < n-1) cout << ' ';
    }
    cout << endl;
}

bool equals(vector<int> &vt1, vector<int> &vt2) {
    if (vt1.size() != vt2.size()) return false;
    int n = vt1.size();
    rep(i,n) {
        if (vt1[i] != vt2[i]) return false;
    }
    return true;
}

bool mod_equals(vector<int> &vt1, vector<int> &vt2) {
    int mod1 = 0, mod2 = 0;
    for (auto i: vt1) {
        mod1 += a[i];
        mod1 %= 200;
    }
    for (auto i: vt2) {
        mod2 += a[i];
        mod2 %= 200;
    }
    return mod1 == mod2;
}

bool mod_equals(vector<int> &vt, int r) {
    int mod = 0;
    for (auto i: vt) {
        mod += a[i];
        mod %= 200;
    }
    return r == mod;
}

void print_vecs(vector<int> vt1, vector<int> vt2) {
    sort(vt1.begin(), vt1.end());
    sort(vt2.begin(), vt2.end());
    // assert(mod_equals(vt1, vt2));
    assert(!equals(vt1, vt2));
    print_vec(vt1);
    print_vec(vt2);
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i,n) {
        cin >> a[i];
        a[i] %= 200;
    }
    vector<vector<int>> mod(200);
    rep(i,n) {
        vector<vector<int>> next = mod;
        rep(j,200) {
            if (mod[j].size()) {
                auto m = mod[j];
                m.push_back(i);
                int r = 0;
                for (auto mi: m) {
                    r += a[mi];
                    r %= 200;
                }
                if (mod[r].size()) {
                    cout << "Yes" << endl;
                    print_vecs(mod[r], m);
                    return 0;
                }
                next[r] = m;
            }
        }
        vector<int> m = {i};
        if (next[a[i]].size()) {
            cout << "Yes" << endl;
            print_vecs(next[a[i]], m);
            return 0;
        }
        next[a[i]] = m;
        assert(mod_equals(m, a[i]));
        swap(mod, next);
    }

    cout << "No" << endl;
    return 0;
}