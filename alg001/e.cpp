#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
bool data[105][105];

void output(int n){
    // cout << "==========" << endl;
    rep(i,n){
        stringstream ss;
        rep(j,n){
            if(data[i][j]) ss << "Y";
            else ss << "N";
        }
        cout << ss.str() << endl;
    }
}

void action1(int a, int b){
    data[a-1][b-1] = true;
}

int main() {
    int n,q;
    cin >> n >> q;
    rep(i,n) rep(j,n) data[i][j] = false;
    vector<vector<int>> input(q);
    rep(i,q){
        int action, a, b;
        cin >> action;
        if(action == 1){
            cin >> a >> b;
        } else {
            cin >> a;
            b = -1;
        }
        input.at(i) = {action, a, b};
    }

    rep(i,q){
        int action = input.at(i).at(0);
        int a = input.at(i).at(1);
        int b = input.at(i).at(2);
        queue<int> follow;
        switch (action)
        {
        case 1:
            data[a-1][b-1] = true;
            break;
        case 2:
            rep(j,n){
                if(data[j][a-1]) data[a-1][j] = true;
            }
            break;
        case 3:
            rep(j,n) if(data[a-1][j]) follow.push(j);
            while(!follow.empty()){
                int k = follow.front();
                follow.pop();
                if(data[a-1][k]){
                    rep(l,n){
                        if(data[k][l] && l != a-1){
                            data[a-1][l] = true;
                        }
                    }
                }
            }
            break;
        default:
            return -1;
        }
    
    }
    output(n);
    return 0;
}