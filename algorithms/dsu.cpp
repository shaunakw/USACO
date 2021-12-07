#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for (int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;

int N = 8;
vi parent;
vi sizes;

// Initialize vector
void init() {
    parent.resize(N);
    fori(i, N) parent[i] = i;
    sizes.resize(N, 1);
}

// Get subset of node i
int find(int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

// Connect two nodes
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (sizes[b] > sizes[a]) swap(a, b);

    parent[b] = a;
    sizes[a] += sizes[b];
}
