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

/**
 * 山登り法
 * 平行移動
 * **/

const int W = 10000;
const int H = 10000;
const ll LIMIT = 4990000000LL;
int N;
P dif[4] {
    {-1, 0},
    {0, -1},
    {1, 0},
    {0, 1}
};

struct point {
    int x, y;

    point() {
        x = 0;
        y = 0;
    }

    point(int x, int y) : x(x), y(y) {}
};

struct rectangle {
    point top_left;
    int width;
    int height;

    rectangle(point top_left = point(0, 0)) : top_left(top_left) {
        width = 1;
        height = 1;
    }

    rectangle(point top_left, int width, int height)
        : top_left(top_left), width(width), height(height) {}

    rectangle extend(int direction, int length) {
        if(direction == 0) {
            point tl = point(top_left.x - length, top_left.y);
            return rectangle(tl, width + length, height);
        } else if(direction == 1) {
            point tl = point(top_left.x, top_left.y - length);
            return rectangle(tl, width, height + length);
        } else if(direction == 2) {
            return rectangle(top_left, width + length, height);
        }
        return rectangle(top_left, width, height + length);
    }

    rectangle move(int direction, int length) {
        point tl = point(
            top_left.x + dif[direction].first * length,
            top_left.y + dif[direction].second * length
        );
        return rectangle(tl, width, height);
    }

    bool is_inside(point p) {
        return in(p.x, top_left.x, top_left.x + width) &&
               in(p.y, top_left.y, top_left.y + height);
    }

    vector<point> vertices() {
        return {top_left, point(top_left.x + width, top_left.y),
                point(top_left.x + width, top_left.y + height),
                point(top_left.x, top_left.y + height)};
    }

    bool overlaps(rectangle other) {
        for(auto v : vertices()) {
            if(other.is_inside(v)) {
                return true;
            }
        }
        for(auto v : other.vertices()) {
            if(is_inside(v)) {
                return true;
            }
        }
        return false;
    }

    int area() { return width * height; }
};

struct board {
    vector<rectangle> ads;
    vector<point> points;
    vector<int> reqs;
    vector<double> scores;

    board(vector<rectangle> ads,vector<point> points, vector<int> reqs) :
    ads(ads), points(points), reqs(reqs) {
        score_all();
    }

    void score_all() {
        scores.resize(N);
        rep(i, N) { scores[i] = score(i, ads[i]); }
    }

    bool on_board(rectangle rec) {
        return 0 <= rec.top_left.x && 0 <= rec.top_left.y &&
               rec.top_left.x + rec.width < W &&
               rec.top_left.y + rec.height < H;
    }

    bool overlaps(int x, rectangle rect) {
        rep(i, N) {
            if(i == x)
                continue;
            if(rect.overlaps(ads[i])) {
                return true;
            }
        }
        return false;
    }

    double score(int x, rectangle rect) {
        int area = rect.area();
        double ratio = (double)min(area, reqs[x]) / max(area, reqs[x]);
        return 1. - pow(1. - ratio, 2);
    }

    void update(int x, int direction, int length) {
        rectangle new_rect = ads[x].extend(direction, length);
        ads[x] = new_rect;
        scores[x] = score(x, new_rect);
    }

    void extend_if_better(int x, int direction, int length) {
        rectangle new_rect = ads[x].extend(direction, length);

        if(!on_board(new_rect)) {
            return;
        }

        if(overlaps(x, new_rect)) {
            return;
        }

        double new_score = score(x, new_rect);

        if(scores[x] < new_score) {
            ads[x] = new_rect;
            scores[x] = new_score;
        }
    }

    void move_if_better(int x, int direction, int length) {
        rectangle new_rect = ads[x].move(direction, length);
        
        if (!on_board(new_rect)) {
            return;
        }

        if (!new_rect.is_inside(points[x])) {
            return;
        }

        if (overlaps(x, new_rect)) {
            return;
        }

        ads[x] = new_rect;
    }
};

struct solver {
    board bd;
    mt19937 mt;

    solver(board bd) : bd(bd) {}

    void solve() {
        uniform_int_distribution<int> next_dir(0, 3);
        uniform_int_distribution<int> next_rect(0, N - 1);
        uniform_int_distribution<int> next_command(0, 10);
        auto start = chrono::system_clock::now();

        while((chrono::system_clock::now() - start).count() < LIMIT) {
            int direction = next_dir(mt);
            int rect = next_rect(mt);
            int command = next_command(mt);
            bd.extend_if_better(rect, direction, 1);
            
            if (command == 0) {
                bd.move_if_better(rect, direction, 1);
            }
        }
    }

    void print() {
        for(auto &ad : bd.ads) {
            printf(
                "%d %d %d %d\n",
                ad.top_left.x,
                ad.top_left.y,
                ad.top_left.x + ad.width,
                ad.top_left.y + ad.height
            );
        }
    }
};

int main() {
    cin >> N;
    vector<int> reqs(N);
    vector<point> points(N);
    vector<rectangle> ads(N);
    rep(i, N) {
        cin >> points[i].x >> points[i].y >> reqs[i];
        ads[i] = rectangle(points[i]);
    }
    board bd = board(ads, points, reqs);
    solver slv = solver(bd);
    slv.solve();
    slv.print();
    return 0;
}