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

    rectangle(int id, point ul, int h, int w):
        id(id), upperLeft(ul), h(h), w(w) {}

    rectangle(int a, int b, int c, int d) {
        upperLeft = point(a, b);
        h = c-a;
        w = d-b;
    }

    bool isInside(point p) {
        return upperLeft.x <= p.x && p.x <= upperLeft.x + w
        && upperLeft.y <= p.y && p.y <= upperLeft.y + h;
    }

    static bool overlaps(rectangle x, rectangle y) {
        for (auto p: x.vertices()) {
            if (y.isInside(p)) return true;
        }
        for (auto p: y.vertices()) {
            if (x.isInside(p)) return true;
        }
        return false;
    }

    rectangle extend(int d, int direction) {
        if (direction == 0) return extendLeft(d);
        if (direction == 1) return extendRight(d);
        if (direction == 2) return extendCeil(d);
        if (direction == 3) return extendBottom(d);
        throw;
    }

    rectangle extendLeft(int d) {
        return rectangle(id, point(upperLeft.x-d, upperLeft.y), h, w+d);
    }

    rectangle extendRight(int d) {
        return rectangle(id, upperLeft, h, w+d);
    }

    rectangle extendCeil(int d) {
        return rectangle(id, point(upperLeft.x, upperLeft.y - d), h+d, w);
    }

    rectangle extendBottom(int d) {
        return rectangle(id, upperLeft, h+d, w);
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
        return point(upperLeft.x + w, upperLeft.y + h);
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
            if (rectangle::overlaps(r, rec)) return false;
        }
        return true;
    }

    bool onBoard(rectangle &r) {
        if (r.upperLeft.x < 0 || r.upperLeft.y < 0) return false;
        point lr = r.lowerRight();
        if (MX <= lr.x || MX <= lr.y) return false;
        return true;
    }

    void add(rectangle r) {
        recs.push_back(r);
    }

    void addRondom(request req) {
        rectangle r = rectangle(req.id);
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

    void print(bool s = true) {
        if (s) {
            sort(recs.begin(), recs.end(), [&](auto x, auto y){
            return x.id < y.id;
            });
        }

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
        const int step = 1;

        sort(reqs.begin(), reqs.end(), [&](auto x, auto y) {
            return x.r < y.r;
        });
        
        for (auto &req: reqs) {
            rectangle r = rectangle(req.id, req.p, 0, 0);
            int flag = 0;

            while (flag < (1<<4) - 1) {
                if (req.r <= r.square()) break;

                rep(dir, 4) {
                    if ((~flag>>dir)&1) {
                        rectangle tmp = r.extend(step, dir);
                        if (board.onBoard(tmp) && board.canAdd(tmp)) {
                            for (auto q: reqs) {
                                if (req.id == q.id) continue;
                                if (tmp.isInside(q.p)) {
                                    flag |= 1<<dir;
                                    break;
                                }
                            }
                            if ((~flag>>dir)&1) r = tmp;
                        }
                        else flag |= 1<<dir;
                    }

                    if (req.r <= r.square()) {
                        flag |= 1<<dir;
                        break;
                    }
                }
            }

            if (0 < r.square() && board.canAdd(r)) {
                board.add(r);
                continue;
            }

            board.addRondom(req);
        }

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
    ans.print(true);


    return 0;
}