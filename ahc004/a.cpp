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

const int SZ = 20;
clock_t start;
const clock_t LIMIT = 2.9 * CLOCKS_PER_SEC;

int n, m;
vector<string> s;

struct Torus {
    vector<string> val;
    vector<vector<int>> hword, vword;
    vector<int> missing;

    Torus(vector<string> val): val(val) {
        hword.resize(SZ), vword.resize(SZ);
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

    int hscore(int l, int r) {
        int res = 0;
        for (int h = l; h < r; ++h) {
            vector<int> ok, ng;
            for (auto id : hword[h]) {
                if (hfind(h, s[id])) {
                    ok.push_back(id);
                }
                else {
                    ng.push_back(id);
                }
            }
            for (auto id : missing) {
                if (hfind(h, s[id])) {
                    ok.push_back(id);
                }
                else {
                    ng.push_back(id);
                }
            }
            res += ok.size() - hword[h].size();
            swap(hword[h], ok);
            swap(missing, ng);
        }
        return res;
    }

    int vscore(int l, int r) {
        int res = 0;
        for (int w = l; w < r; ++w) {
            vector<int> ok, ng;
            for (auto id : vword[w]) {
                if (vfind(w, s[id])) {
                    ok.push_back(id);
                }
                else {
                    ng.push_back(id);
                }
            }
            for (auto id : missing) {
                if (vfind(w, s[id])) {
                    ok.push_back(id);
                }
                else {
                    ng.push_back(id);
                }
            }
            res += ok.size() - vword[w].size();
            swap(vword[w], ok);
            swap(missing, ng);
        }
        return res;
    }

    int score() {
        int res = 0;
        rep(i,m) {
            bool ok = false;
            rep(j,SZ) {
                if (hfind(j, s[i])) {
                    ok = true;
                    hword[j].push_back(i);
                    break;
                }
                if (vfind(j, s[i])) {
                    ok = true;
                    vword[j].push_back(i);
                    break;
                }
            }
            if (ok) {
                res++;
            }
            else {
                missing.push_back(i);
            }
        }
        return res;
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

    vector<pair<string,int>> cand;

    for (auto &sub : s) {
        bool find = false;
        for (auto &[t, cnt] : cand) {
            if (t.find(sub) != string::npos) {
                cnt++;
                find = true;
                break;
            }
        }
        if (find) continue;
        for (auto &[t, cnt] : cand) {
            if (sub.find(t) != string::npos) {
                cnt++;
                find = true;
                t = sub;
                break;
            }
        }
        if (!find) {
            cand.emplace_back(sub, 1);
        }
    }

    sort(cand.begin(), cand.end(), [&](auto x, auto y){
        return y.second < x.second;
    });

    vector<string> initial(SZ);
    for (auto &[t, cnt] : cand) {
        rep(i,SZ) {
            if (initial[i].size() + t.size() <= SZ) {
                initial[i] += t;
                break;
            }
        }
    }

    rep(i,SZ) {
        initial[i] += string(SZ - initial[i].size(), '.');
    }

    Torus torus(initial);
    random_device seed_gen;
    mt19937 engine(seed_gen());

    int score = torus.score();
    rep(h, SZ) {
        string original = torus.val[h];
        string best = original;
        string tmp = "";
        for (int dw = 1; dw < 20; ++dw) {
            string now = original.substr(dw, SZ - dw) + original.substr(0, dw);
            torus.hinsert(h, 0, now, tmp);
            int dif = torus.hscore(max(0, h-1), min(h+2, SZ)) + torus.vscore(0, SZ);
            if (0 < dif) {
                swap(best, now);
                score += dif;
            }
        }
        torus.hinsert(h, 0, best, tmp);
    }
    while (true) {
        rep(i,m) {
            if (LIMIT < clock() - start) {
                torus.print();
                return 0;
            }
            string original = "";
            string changed = "";
            int h = engine() % SZ;
            int w = engine() % SZ;
            torus.hinsert(h, w, s[i], original);
            if (chmax(score, torus.score())) {
                continue;
            }
            torus.hinsert(h, w, original, changed);
            torus.vinsert(h, w, s[i], original);
            if (chmax(score, torus.score())) {
                continue;
            }
            torus.vinsert(h, w, original, changed);
        }
    }

    return 0;
}