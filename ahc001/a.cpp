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

struct request {
    int id, x, y, r;
    request(int id = 0, int x = 0, int y = 0, int r = 0):
        id(id), x(x), y(y), r(r) {}
};

struct rectangle {
    int id, x, y, h, w;
    rectangle() {
        id = 0;
        x = 0;
        y = 0;
        h = 0;
        w = 0;
    };

    bool isInside(int reqx, int reqy) {
        return in(reqx, x, x+w) && in(reqy, y, y+h);
    }

    bool isInside(P p) {
        return isInside(p.first, p.second);
    }

    bool overlaps(rectangle another) {
        for (auto p: another.vertices()) {
            if (isInside(p)) return true;
        }
        for (auto p: vertices()) {
            if (another.isInside(p)) return true;
        }
        return false;
    }

    vector<P> vertices() {
        return {{x,y}, {x+h,y}, {x,y+h}, {x+h,y+h}};
    }

    int square() {
        return h*w;
    }

    void print() {
        cout << x << ' ' << y << ' ' << x+w << ' ' << y+h << endl;
    }
};

struct board {
    const int MX = 10000;
    vector<rectangle> recs;
    int n;

    board(vector<rectangle> recs): recs(recs) {
        n = recs.size();
    }

    board() {
        n = 0;
    }

    bool canAdd(rectangle rec) {
        for (auto r: recs) {
            if (r.overlaps(rec)) return false;
        }
        return true;
    }

    bool onBoard(rectangle &r) {
        if (r.x < 0 || r.y < 0) return false;
        if (MX <= r.x + r.w || MX <= r.y + r.h) return false;
        return true;
    }

    void add(request req) {
        int a = 1;
        
        while (a*a <= req.r) a++;

        a--;
        rectangle r;
        r.id = req.id;
        r.x = min(0, req.x - a);
        r.y = min(0, req.y - a);
        r.h = a;
        r.w = a;
        while (r.x <= req.x && r.y <= req.y) {
            if (onBoard(r) && canAdd(r)) {
                recs.push_back(r);
                return;
            }
            r.x++, r.y++;
        }

        addRondom(req.id);
    }

    void addRondom(int id) {
        rectangle r;
        r.id = id;
        for (int i = 0; i < MX-1; i += 2) {
            for (int j = 0; j < MX-1; j += 2) {
                r.x = i;
                r.y = j;
                r.h = 2;
                r.w = 2;
                if (canAdd(r)) {
                    recs.push_back(r);
                    return;
                }
            }
        }
    }

    static board fromInput(int n) {
        vector<rectangle> recs(n);

        rep(i,n) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            recs[i].x = a;
            recs[i].y = b;
            recs[i].w = c - a;
            recs[i].h = d - b;
        }

        return board(recs);
    }

    void print() {
        sort(recs.begin(), recs.end(), [&](auto x, auto y){
            return x.id < y.id;
        });
        for (auto &rec: recs) {
            rec.print();
        }
    }
};

struct solver {
    vector<request> reqs;
    vector<rectangle> recs;
    int n;

    solver(vector<request> &reqs): reqs(reqs) {
        n = reqs.size();
    }

    board solve() {
        board board;
        
        for (auto &req: reqs) board.add(req);

        return board;
    }

};

struct scorer {
    vector<request> reqs;
    int n;

    scorer(vector<request> &reqs): reqs(reqs) {
        n = reqs.size();
    }
    
    ll score(board &ans) {
        vector<double> scores(n);
        vector<rectangle> &recs = ans.recs;

        rep(i,n) {
            if (!recs[i].isInside(reqs[i].x, reqs[i].y)) {
                scores[i] = 0.0;
                continue;
            }

            int s = recs[i].square();
            double mi = min(reqs[i].r, s);
            double mx = max(reqs[i].r, s);
            scores[i] = 1.0 - pow(1.0 - mi/mx, 2.0);
        }
        double res = 0;
        rep(i,n) {
            res += scores[i]/n;
        }
        return floor(res*10e9);
    }
};

int main() {
    int n;
    cin >> n;

    vector<request> reqs(n);
    rep(i,n) {
        request r;
        r.id = i;
        cin >> r.x >> r.y >> r.r;
        reqs[i] = r;
    }
    
    solver slv = solver(reqs);
    board ans = slv.solve();

    ans.print();

    return 0;
}