#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

typedef tuple<int, int, double> attack;

bool compare(const attack &lhs, const attack &rhs)
{
    if (get<2>(lhs) != get<2>(rhs))
        return get<2>(lhs) > get<2>(rhs);
    if (get<1>(lhs) != get<1>(rhs))
        return get<1>(lhs) > get<1>(rhs);
    return get<1>(lhs) > get<1>(rhs);
}

void PrintAttack(vector<attack> attack)
{
    cout << "========== Print Attack ==========" << endl;
    for (auto x : attack)
    {
        cout << setprecision(5) << get<0>(x) << ' ' << get<1>(x) << ' ' << get<2>(x) << endl;
    }
}

int main()
{
    int H, N;
    cin >> H >> N;
    vector<attack> vt;
    rep(i, N)
    {
        double a, b, c;
        cin >> a >> b;
        c = a / b;
        vt.emplace_back(a, b, c);
    }
    sort(vt.begin(), vt.end(), compare);

    PrintAttack(vt);

    int sum = 0;
    int consume = get<1>(vt.at(0));
    rep(i, N)
    {
        if (consume >= get<1>(vt.at(i)))
        {
            consume = get<1>(vt.at(i));
            int attack = get<0>(vt.at(i));
            int count = H / attack;
            cout <<"attack " << attack << " count " << count << " consume " << consume << endl;
            sum += consume * count;
            H = H % attack;
            cout << "H " << H << endl;
            if (H == 0)
                break;
        }
        if (i == N-1)
            sum += consume;
    }
    cout << sum << endl;
    return 0;
}