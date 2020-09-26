#include <bits/stdc++.h>

#define fori(i, a) for(int i = 0; i < a; ++i)
#define trav(i, a) for(auto& i : a)

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
}

struct path {
    int dest;
    int cost;
    int flow;
};

int N, M;
vector<path> graph[1000];
double res;

void dfs(int x, set<int> prev, int cost, int flow) {
    if (x == N - 1) {
        res = max(res, (double) flow / cost);
        return;
    }
    prev.insert(x);
    trav(i, graph[x]) {
        if (prev.find(i.dest) == prev.end()) {
            dfs(i.dest, prev, cost + i.cost, min(flow, i.flow));
        }
    }
}

// slow
int main() {
    setIO();
    cin >> N >> M;
	
    fori(i, M) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        path pa{b - 1, c, f};
        path pb{a - 1, c, f};
        graph[a - 1].push_back(pa);
        graph[b - 1].push_back(pb);
    }

    set<int> prev;
    dfs(0, prev, 0, INT_MAX);
    cout << (int) (res * 1000000);
    
    return 0;
}
