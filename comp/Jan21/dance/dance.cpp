#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

int N, K;
long long M;

vi parent;

int find(int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[b] = a;
}

int main() {
    cin >> N >> K >> M;
    int line[N];
    vector<int> path[N];

    fori(i, N) line[i] = i;
    fori(i, K) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        path[line[a]].push_back(b);
        path[line[b]].push_back(a);
        swap(line[a], line[b]);
    }

    int nLoops = 0;
    vector<bool> root(N, false);
    vi loops[N];
    parent.resize(N);
    fori(i, N) parent[i] = i;
    fori(i, N) {
        unite(i, line[i]);
    }
    fori(i, N) {
        int f = find(i);
        if (!root[f]) {
            root[f] = true;
            nLoops++;
        }
        loops[f].push_back(i);
    }

    long long cycles = M / K;
    vi unique(N, 0);
    fori(i, N) {
        if (root[i]) {
            if (cycles >= loops[i].size()) {
                vector<bool> visited(N, false);
                int total = 0;
                trav(j, loops[i]) {
                    trav(k, path[j]) {
                        if (!visited[k]) {
                            visited[k] = true;
                            total++;
                        }
                    }
                }
                trav(j, loops[i]) unique[j] = total;
            } else {
                trav(j, loops[i]) {

                }
            }
        }
    }

    cout << nLoops;

    return 0;
}
