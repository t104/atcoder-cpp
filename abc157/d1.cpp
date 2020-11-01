#include <iostream>
using namespace std;

#include <vector>
#include <cassert>

template <typename Ty>
class UnionFind {
private:
    std::vector<Ty> _Parent;
    std::vector<Ty> _Size;
    Ty _N;
    bool _GetSize_called = false;

    std::vector<Ty> __Size() {
        std::vector<Ty> ret(_N);
        for(Ty i = 0; i < _N; ++i) {
            ++ret[__Root(i)];
        }
        for(Ty i = 0; i < _N; ++i) {
            ret[i] = ret[__Root(i)];
        }

        return ret;
    }

    inline Ty __Root(Ty Node) {
        assert(0 <= Node && Node < _N);
        if (_Parent[Node] == Node) return Node;
        else return _Parent[Node] = __Root(_Parent[Node]);
    }

    inline bool __isRoot(Ty x) {
        assert(0 <= x && x < _N);
        return _Parent[x] == x;
    }

public:
    UnionFind(Ty Num) : _Parent(Num), _N(Num) {
        for (Ty i = 0; i < _N; ++i) {
            _Parent[i] = i;
        }
    }

    void Unite(Ty A, Ty B) {
        assert(0 <= A && A < _N);
        assert(0 <= B && B < _N);
        A = __Root(A); B = __Root(B);
        if (A != B) _Parent[B] = A;
    }

    bool Same(Ty A, Ty B) {
        assert(0 <= A && A < _N);
        assert(0 <= B && B < _N);
        return __Root(A) == __Root(B);
    }

    void GetSize() {
        _GetSize_called = true;
        _Size = __Size();
    }

    Ty CountTrees() {
        Ty ret = 0;
        for (Ty i = 0; i < _N; ++i) {
            if(__isRoot(i)) ++ret;
        }

        return ret;
    }

    Ty operator()(Ty x) const {
        assert(_GetSize_called);
        assert(0 <= x && x < _N);
        return _Size[x];
    }

    Ty operator[](Ty Node) {
        assert(0 <= Node && Node < _N);
        return __Root(Node);
    }

};

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    UnionFind<int> uf(n);

    vector<vector<int>> Friend(n), Block(n);

    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        uf.Unite(a, b);
        Friend[a].push_back(b);
        Friend[b].push_back(a);
    }

    for(int i = 0; i < k; ++i) {
        int c, d; cin >> c >> d;
        --c; --d;
        Block[c].push_back(d);
        Block[d].push_back(c);
    }

    vector<int> fri(n);
    vector<int> blo(n);

    for(int i = 0; i < n; ++i) {
        fri[i] = Friend[i].size();

        for(auto &e: Block[i]) {
            if(uf.Same(i, e)) {
                ++blo[i];
            }
        }
    }

    uf.GetSize();
    for(int i = 0; i < n; ++i) {
        cout << uf(i) - fri[i] - blo[i] - 1 << " ";
    }

    return 0;
}