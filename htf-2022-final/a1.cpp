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

const int N = 20;
const int N2 = N*N;

struct Position {
    int h, w;
    Position(int h = 0, int w = 0) : h(h), w(w) {}
    int index() {
        return h * N + w;
    }
    static Position fromIndex(int i) {
        return Position(i / N, i % N);
    }
    Position add (Position p) {
        return Position(h + p.h, w + p.w);
    }
    P subtract (Position p) {
        return make_pair(h - p.h, w - p.w);
    }
    bool equals(Position other) {
        return h == other.h && w == other.w;
    }
};

const P step[4] {
    make_pair(-1, 0),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1)
};

P to_dif[4] = {
    make_pair(-1, 0),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1)
};

map<P, int> to_val = {
    {to_dif[0], 0},
    {to_dif[1], 1},
    {to_dif[2], 2},
    {to_dif[3], 3}
};

struct Direction {
    int val, dh, dw;

    Direction(int val) : val(val) {
        tie(dh, dw) = to_dif[val];
    }

    Direction(int dh, int dw) : dh(dh), dw(dw) {
        val = to_val.at(make_pair(dh, dw));
    }

    Direction(P d) {
        tie(dh, dw) = d;
        val = to_val.at(d);
    }

    Direction rotate() {
        return Direction((val + 1) % 4);
    }

    vector<char> calc_rotation(Direction heading) {
        int degree = 0;
        auto now = val;
        while (now != heading.val) {
            now = (now + 1) % 4;
            degree++;

        }
        if (degree == 0) {
            return {};
        } else if (degree == 1) {
            return {'L'};
        } else if (degree == 2) {
            return {'L', 'L'};
        } else if (degree == 3) {
            return {'R'};
        }
        assert(false);
    }

    bool equals(Direction other) {
        return val == other.val;
    }
};

struct Command {
    string val;
    Command(vector<Position> &route) {
        int n = route.size();
        Direction direction(0);
        rep(i,n-1) {
            P d = route[i+1].subtract(route[i]);
            auto heading = Direction(d);
            auto rotation = direction.calc_rotation(heading);
            for (auto &c : rotation) {
                val.push_back(c);
            }
            direction = heading;
            val.push_back('F');
        }
    }
};

struct Input {
    Position start;
    vector<string> h;
    vector<string> v;

    Input() {
        cin >> start.h >> start.w;
        h = vector<string>(N);
        rep(i,N) cin >> h[i];
        v = vector<string>(N-1);
        rep(i,N-1) cin >> v[i];
    }
} input;

struct RouteFinder {
    int dp[N2][N2];
    int prev[N2][N2];

    RouteFinder(vector<string> &h, vector<string> &v) {
        rep(i,N2) rep(j,N*N) {
            dp[i][j] = INF;
            prev[i][j] = -1;
        }
        rep(i, N2) dp[i][i] = 0;
        rep(i, N2) {
            Position now = Position::fromIndex(i);
            for (int dh : {-1, 1}) {
                Position next = Position(now.h + dh, now.w);
                if (in(next.h, 0, N) && v[now.h + min(0, dh)][now.w] == '0') {
                    dp[i][next.index()] = 1;
                    prev[i][next.index()] = i;
                }
            }
            for (int dw : {-1, 1}) {
                Position next = Position(now.h, now.w + dw);
                if (in(next.w, 0, N) && h[now.h][now.w + min(0, dw)] == '0') {
                    dp[i][next.index()] = 1;
                    prev[i][next.index()] = i;
                }
            }
        }
        rep(k, N2) rep(i, N2) rep(j, N2) {
            if (chmin(dp[i][j], dp[i][k] + dp[k][j])) {
                prev[i][j] = prev[k][j] == -1 ? k : prev[k][j];
            }
        }
    }

    vector<Position> route(Position from, Position to) {
        vector<Position> res;
        Position now = to;
        while (!now.equals(from)) {
            res.push_back(now);
            now = Position::fromIndex(prev[from.index()][now.index()]);
        }
        reverse(res.begin(), res.end());
        assert(!res[0].equals(from));
        assert(res.back().equals(to));
        int n = res.size();
        rep(i, n-1) {
            auto [dh, dw] = res[i].subtract(res[i+1]);
            assert(in(dh, -1, 2));
            assert(in(dw, -1, 2));
        }
        return res;
    }

    vector<Position> route(int from, int to) {
        return route(Position::fromIndex(from), Position::fromIndex(to));
    }

    int distance(Position from, Position to) {
        return dp[from.index()][to.index()];
    }

    int distance(int from, int to) {
        return dp[from][to];
    }
};

struct CleanerMap {
    int val[N];
    CleanerMap() {
        rep(i,N) val[i] = 0;
    }
    void clean(Position p) {
        val[p.h] |= 1 << p.w;
    }
    bool isClean(Position p) {
        return (val[p.h] >> p.w) & 1;
    }
    bool isAllClean() {
        const int flg = (1 << N) - 1;
        rep(i,N) {
            if (val[i] != flg) {
                return false;
            }
        }
        return true;
    }
};

struct NearestNeighbor {
    vector<Position> route;
    Position start;

    NearestNeighbor(Position start, RouteFinder &finder) : start(start) {
        CleanerMap cm;
        cm.clean(start);
        route.push_back(start);
        Position now = start;
        while (!cm.isAllClean()) {
            int distance = INF;
            Position nearest(-1, -1);
            rep(i, N2) {
                auto to = Position::fromIndex(i);
                if (cm.isClean(to)) continue;
                if (chmin(distance, finder.distance(now, to))) {
                    nearest = to;
                    if (distance == 1) {
                        break;
                    }
                }
            }
            auto toNearest = finder.route(now, nearest);
            for (auto &r : toNearest) {
                cm.clean(r);
                auto [dh, dw] = route.back().subtract(r);
                assert(in(dh, -1, 2));
                assert(in(dw, -1, 2));
                route.push_back(r);
            }
            now = nearest;
        }
    }

    void printPositions() {
        for (auto &r : route) {
            printf("%d %d\n", r.h, r.w);
        }
    }

    void printRoute() {
        int direction = 0;
    }

};

int main() {
    RouteFinder finder(input.h, input.v);
    NearestNeighbor nn(input.start, finder);
    Command command(nn.route);
    cout << command.val << endl;
    return 0;
}