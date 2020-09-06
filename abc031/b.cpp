#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

bool island(vector<string>& board, vector<vector<bool>>& checked) {
    rep(i, 10) {
        rep(j, 10) {
            if(!checked.at(i).at(j) && board.at(i).at(j) == 'o') return false;
        }
    }
    return true;
}

void check(int x, int y, vector<string>& board, vector<vector<bool>>& checked) {
    if(checked.at(x).at(y) || board.at(x).at(y) == 'x') return;
    checked.at(x).at(y) = true;
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    rep(i, 4) {
        int nx = x + dx.at(i);
        int ny = y + dy.at(i);
        if(0 <= nx && nx < 10 && 0 <= ny && ny < 10)
            check(nx, ny, board, checked);
    }
}

int main() {
    int x, y;
    vector<string> board(10);

    rep(i, 10) cin >> board.at(i);
    rep(i, 10) {
        rep(j, 10) {
            if(board.at(i).at(j) == 'o') {
                x = i;
                y = j;
                break;
            }
        }
    }
    int ans = false;
    rep(i, 10) {
        rep(j, 10) {
            if(board.at(i).at(j) == 'x') {
                vector<string> bd = board;
                vector<vector<bool>> checked(10, vector<bool>(10, false));
                bd.at(i).replace(j, 1, "o");
                check(x, y, bd, checked);
                if(island(bd, checked)) {
                    ans = true;
                    break;
                }
            }
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}