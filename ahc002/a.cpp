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

const int L = 50;
vector tile(L, vector<int>(L));
vector point(L, vector<int>(L));
int sh, sw;
const vector<P> d = {
    {1,0}, {0,1}, {-1,0}, {0,-1}
};
const vector<vector<int>> priority = {
    {2, 3, 1, 0},
    {2, 1, 3, 0},
    {0, 3, 1, 2},
    {0, 1, 3, 2}
};
const vector<char> charD = {'D', 'R', 'U', 'L'};
clock_t start;
const clock_t limit = 1.95 * CLOCKS_PER_SEC;

int getArea(int h, int w) {
    if (h < 25) {
        if (w < 25) return 0;
        else return 1;
    }
    else if (w < 25) return 2;
    else return 3;
}

bool isInside(int h, int w) {
    return in(h, 0, L) && in(w, 0, L);
}

struct tileState {
    bitset<2500> state;

    void crash(int h, int w) {
        state.set(L*h+w);
    }

    void crashTile(int h, int w) {
        int id = tile[h][w];
        crash(h,w);
        for (auto [dh, dw]: d) {
            int nh = dh+h;
            int nw = dw+w;
            if (isInside(nh,nw)
            && id == tile[nh][nw]) {
                crash(nh,nw);
            }
        }
    }

    bool isCrashed(int h, int w) {
        return state[L*h+w];
    }

    void repair(int h, int w) {
        state.reset(L*h+w);
    }

    void repairTile(int h, int w) {
        repair(h,w);
        int id = tile[h][w];
        for (auto [dh, dw]: d) {
            int nh = dh+h;
            int nw = dw+w;
        }
    }
};

struct answer {
    int p;
    vector<int> route;
    
    answer(int p): p(p) {
    }
    
    void print() {
        string res;
        for (auto r: route) {
            res.push_back(charD[r]);
        }
        cout << res << endl;
    }

    void test() {
        int h = sh, w = sw;
        tileState ts;
        ts.crashTile(h,w);
        for (auto r: route) {
            h += d[r].first;
            w += d[r].second;
            assert(ts.isCrashed(h,w) == 0);
            ts.crashTile(h,w);
        }
    }
};

answer ANS(0);

void dfs(int h, int w, answer &ans, tileState ts) {
    if (limit < clock() - start) return;
    ts.crashTile(h,w);
    int dir = -1, np = 0;
    bool end = true;
    for (auto &di: priority[getArea(h,w)]) {
        int nh = d[di].first+h, nw = d[di].second+w;
        if (isInside(nh, nw) && ts.isCrashed(nh, nw) == 0) {
            ans.route.push_back(di);
            ans.p += point[nh][nw];
            dfs(nh,nw,ans,ts);
            ans.route.pop_back();
            ans.p -= point[nh][nw];
            end = false;
        }
    }
    if (end && ANS.p < ans.p) {
        ANS = ans;
    }
}



int main() {
    start = clock();
    
    cin >> sh >> sw;
    
    rep(i,L) rep(j,L) cin >> tile[i][j];
    rep(i,L) rep(j,L) cin >> point[i][j];
    answer ans(point[sw][sw]);
    tileState ts;
    dfs(sh,sw,ans,ts);
    ANS.print();

    return 0;
}