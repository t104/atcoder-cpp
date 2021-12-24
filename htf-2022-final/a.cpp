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
int H[N][N];
int V[N][N];

const P dir[] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0}
};

struct position {
    int h, w;
    
    position(int h = 0, int w = 0) : h(h), w(w) {}

    position move(int direction) {
        return position(h + dir[direction].first, w + dir[direction].second);
    }
};

struct simulater {
    vector<vector<int>> grid;
    position p;
    int direction;
    int point;
    string command;

    simulater(vector<vector<int>> grid, position p, int direction, int point) :
    grid(grid), p(p), direction(direction), point(point) {
        command = "";
    }

    simulater(position p, int direction) : p(p), direction(direction) {}

    void move_f() {
        p = p.move(direction);
        point += grid[p.h][p.w];
        grid[p.h][p.w] = 0;
        command.push_back('F');
    }

    void turn_r() {
        direction = (direction + 1) % 4;
        command.push_back('R');
    }

    void turn_l() {
        direction = (direction + 3) % 4;
        command.push_back('L');
    }

    void move(int direction) {
        if (direction == 1) {
            turn_r();
        } else if (direction == 2) {
            turn_r();
            turn_r();
        } else if (direction == 3) {
            turn_l();
        }
        move_f();
    }

    bool is_clear(int direction) {
        position new_p = p.move(direction);
        
        if (!in(new_p.h, 0, N) || !in(new_p.w, 0, N)) {
            return false;
        }

        if (direction % 2 == 1) {
            if (direction < 2) {
                return V[p.h-1][p.w] == 0;
            }
            return V[p.h][p.w] == 0;
        }
        if (direction < 2) {
            return H[p.h][p.w-1] == 0;
        }
        return H[p.h][p.w] == 0;
    }

    bool is_forward_clear() {
        return is_clear(direction);
    }

    bool is_right_clear() {
        return is_clear((direction + 1) % 4);
    }

    bool is_left_clear() {
        return is_clear((direction +  3) % 4);
    }

    bool is_visited(int direction) {
        position new_p = p.move(direction);

        if (!in(new_p.h, 0, N) || !in(new_p.w, 0, N)) {
            return true;
        }

        return grid[new_p.h][new_p.w] == 0;
    }

    bool is_forward_visited() {
        return is_visited(direction);
    }

    bool is_right_visited() {
        return is_visited((direction + 1) % 4);
    }

    bool is_left_visited() {
        return is_visited((direction + 3) % 4);
    }

    vector<int> next_direction() {
        vector<int> clear, not_visited;
        rep(i, 4) {
            position new_p = p.move(direction);
            if (!in(new_p.h, 0, N) || !in(new_p.w, 0, N)) {
                continue;
            }
            if (is_clear(i)) {
                clear.push_back(i);
                if (!is_visited(i)) {
                    not_visited.push_back(i);
                }
            }
        }
        if (not_visited.size() == 0) {
            assert(0 < clear.size());
            return clear;
        }
        return not_visited;
    }
};

struct solver {
    vector<vector<int>> grid;
    position start;
    int direction;

    solver(int sh, int sw) {
        grid = vector<vector<int>>(N, vector<int>(N, 1));
        start = position(sh, sw);
        direction = 1;
    }

    string solve() {
        simulater sim(grid, start, direction, 0);
        while (sim.command.size() < 5000) {
            auto dirs = sim.next_direction();
            int next = dirs[0];
            sim.move(next);
        }
        return sim.command;
    }

};

void test_is_forward_clear() {
    simulater sim0(position(0, 15), 0);
    assert(!sim0.is_forward_clear());
    simulater sim1(position(0, 15), 2);
    assert(sim1.is_forward_clear());
    simulater sim2(position(5, 0), 3);
    assert(!sim2.is_forward_clear());
}


int main() {
    int sh, sw;
    cin >> sh >> sw;
    rep(i, N) {
        string s;
        cin >> s;
        rep(j, N-1) {
            H[i][j] = s[j] - '0';
        }
    }
    rep(i,N-1) {
        string s;
        cin >> s;
        rep(j, N) {
            V[i][j] = s[j] - '0';
        }
    }

    solver slv(sh, sw);
    cout << slv.solve() << endl;
    return 0;
}