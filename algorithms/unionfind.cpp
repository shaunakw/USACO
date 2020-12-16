#include <bits/stdc++.h>

using namespace std;

template<int size>
class unionfind {
private:
    int ids[size]{};

public:
    unionfind() {
        for (int i = 0; i < size; i++) {
            ids[i] = i;
        }
    }

    int root(int i) {
        while (ids[i] != i) {
            ids[i] = ids[ids[i]];
            i = ids[i];
        }
        return i;
    }

    bool connected(int a, int b) {
        return root(a) == root(b);
    }

    void connect(int a, int b) {
        if (connected(a, b)) return;
        ids[root(a)] = root(b);
    }
};
