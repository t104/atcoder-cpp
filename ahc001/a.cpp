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

struct point {
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
};

struct request {
    int id, r;
    point p;
    request(int id = 0): id(id) {}
};

struct rectangle {
    int id, h, w;
    point upperLeft;

    rectangle(int id = 0): id(id) {
        upperLeft = point();
    }

    bool isInside(point p) {
        return in(p.x, upperLeft.x, upperLeft.x + w)
        && in(p.y, upperLeft.y, upperLeft.y + h);
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

    vector<point> vertices() {
        return {
            upperLeft,
            point(upperLeft.x + w, upperLeft.y),
            point(upperLeft.x, upperLeft.y + h),
            point(upperLeft.x + w, upperLeft.y + h)
        };
    }

    int square() {
        return h*w;
    }

    point lowerRight() {
        return point(upperLeft.x + w, upperLeft.y + w);
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
        if (r.upperLeft.x < 0 || r.upperLeft.y < 0) return false;
        point lr = r.lowerRight();
        if (MX <= lr.x || MX <= lr.y) return false;
        return true;
    }

    void add(request req) {
        int a = 1;
        
        while (a*a <= req.r) a++;

        a--;
        rectangle r = rectangle(req.id);
        r.upperLeft = req.p;
        r.h = a;
        r.w = a;

        while (0 < a) {
            r.h = a;
            r.w = a;

            while (0 <= r.upperLeft.x && 0 <= r.upperLeft.y && r.isInside(req.p)) {
                if (onBoard(r) && canAdd(r)) {
                    recs.push_back(r);
                    return;
                }
                r.upperLeft.x--, r.upperLeft.y--;
            }

            a /= 2;
        }

        addRondom(req.id);
    }

    void addRondom(int id) {
        rectangle r = rectangle(id);
        for (int i = 0; i < MX-1; i += 2) {
            for (int j = 0; j < MX-1; j += 2) {
                r.upperLeft = point(i,j);
                r.h = 2;
                r.w = 2;
                if (canAdd(r)) {
                    recs.push_back(r);
                    return;
                }
            }
        }
    }
};

struct answer {
    vector<rectangle> recs;

    answer(vector<rectangle> &recs): recs(recs) {}

    static answer fromInput(int n) {
        vector<rectangle> recs(n);

        rep(i,n) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            recs[i].upperLeft = point(a,b);
            recs[i].w = c - a;
            recs[i].h = d - b;
        }

        return answer(recs);
    }

    void print() {
        sort(recs.begin(), recs.end(), [&](auto x, auto y){
            return x.id < y.id;
        });

        for (auto &rec: recs) {
            point lr = rec.lowerRight();
            printf("%d %d %d %d\n",
            rec.upperLeft.x,
            rec.upperLeft.y,
            lr.x,
            lr.y
            );
        }
    }
};

struct solver {
    vector<request> reqs;

    solver(vector<request> &reqs): reqs(reqs) {}

    answer solve() {
        board board;

        sort(reqs.begin(), reqs.end(), [&](auto x, auto y) {
            return x.r < y.r;
        });
        
        for (auto &req: reqs) board.add(req);

        return answer(board.recs);
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
            if (!recs[i].isInside(reqs[i].p)) {
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
        request r = request(i);
        cin >> r.p.x >> r.p.y >> r.r;
        reqs[i] = r;
    }
    
    solver slv = solver(reqs);
    answer ans = slv.solve();

    ans.print();

    return 0;
}