#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using cake = tuple<int, int, int>;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f)
{
    if (rest == 0)
    {
        f(indexes);
    }
    else
    {
        if (s < 0)
            return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f)
{
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<cake> vt(n);
    rep(i,n) {
        int x,y,z;
        cin >> x >> y >> z;
        vt.at(i) = make_tuple(x,y,z);
    }
    vector<int> scores;
    foreach_comb(n, m, [](int *indexes) {
        int sumx, sumy, sumz = 0;
        for(int i = 0; i < m; i++) {
            cake c = vt.at(indexes[i]);
            sumx += get<0>(c);
            sumy += get<1>(c);
            sumz += get<2>(c);
        }
        scores.push_back(sumx + sumy + sumz);
    });
    int max = max_element(scores.begin(), scores.end());
    cout << max << endl;
    return 0;
}