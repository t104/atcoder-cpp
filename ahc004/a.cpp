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
using P = pair<string,int>;

const int SZ = 20;
clock_t start;
const clock_t LIMIT = 2.9 * CLOCKS_PER_SEC;

int n, m;
vector<string> s;

struct Torus {
    vector<string> val;
    int c;
    bitset<1000> found;

    Torus() {
        val.assign(SZ, string(SZ, '.'));
        c = 0;
    }

    void hinsert(int h, int w, string &s, string &original) {
        original.clear();
        rep(i, s.size()) {
            original.push_back(val[h][(w+i)%SZ]);
            val[h][(w+i)%SZ] = s[i];
        }
    }

    void vinsert(int h, int w, string &s, string &original) {
        original.clear();
        rep(i, s.size()) {
            original.push_back(val[(h+i)%SZ][w]);
            val[(h+i)%SZ][w] = s[i];
        }
    }

    bool hfind(int h, string &sub) {
        rep(w, SZ) {
            bool res = true;
            rep(i, sub.size()) {
                if (val[h][(w+i)%SZ] != sub[i]) {
                    res = false;
                    break;
                }
            }
            if (res) return true;
        }
        return false;
    }

    bool vfind(int w, string &sub) {
        rep(h, SZ) {
            bool res = true;
            rep(i, sub.size()) {
                if (val[(h+i)%SZ][w] != sub[i]) {
                    res = false;
                    break;
                }
            }
            if (res) return true;
        }
        return false;
    }

    int score() {
        int res = 0;
        rep(i,m) {
            bool ok = false;
            rep(j,SZ) {
                if (hfind(j, s[i]) || vfind(j, s[i])) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                found.set(i, 1);
                res++;
            }
            else {
                found.set(i, 0);
            }
        }
        return res;
    }

    bool exists(int idx) {
        return found.test(idx);
    }

    void print() {
        for (auto &v : val) cout << v << endl;
    }
};

int main() {
    start = clock();

    cin >> n >> m;
    s.resize(m);
    rep(i,m) cin >> s[i];

    Torus torus;
    random_device seed_gen;
    mt19937 engine(seed_gen());

    int score = 0;
    while (true) {
        rep(i,m) {
        if (LIMIT < clock() - start) {
            torus.print();
            return 0;
        }
            if (torus.exists(i)) continue;
            string original = "";
            string changed = "";
            int h = engine() % SZ;
            int w = engine() % SZ;
            torus.hinsert(h, w, s[i], original);
            if (chmax(score, torus.score())) continue;
            torus.hinsert(h, w, original, changed);
            torus.vinsert(h, w, s[i], original);
            if (chmax(score, torus.score())) continue;
            torus.vinsert(h, w, original, changed);
        }
    }

    return 0;
}