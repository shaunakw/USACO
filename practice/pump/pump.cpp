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

double value(path& p) {
    return (double) p.flow / p.cost;
}

double value(pair<int, int>& p) {
    return (double) p.second / p.first;
}

bool compare(path x, path y) {
    return value(x) < value(y);
}

int N, M;

double dijkstra(vector<vector<path>>& adjList, int source) {
    vector<pair<int, int>> paths(N, {1, 0}); // cost, flow
    priority_queue<path, vector<path>, decltype(&compare)> pq(compare);
    pq.push({source, 0, INT_MAX});
    paths[source] = {0, INT_MAX};

    while (!pq.empty()) {
        path closest = pq.top();
        pq.pop();

        if (value(closest) < value(paths[closest.dest])) continue;

        for (auto& i : adjList[closest.dest]) {
            path newPath = {i.dest, paths[closest.dest].first + i.cost, min(paths[closest.dest].second, i.flow)};
            if (value(paths[i.dest]) < value(newPath)) {
                paths[i.dest] = {newPath.cost, newPath.flow};
                pq.push(newPath);
            }
        }
    }
    return value(paths[N - 1]);
}

int main() {
    setIO();
    cin >> N >> M;

    vector<vector<path>> adjList(N);
    fori(i, M) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        path pa{b - 1, c, f};
        path pb{a - 1, c, f};
        adjList[a - 1].push_back(pa);
        adjList[b - 1].push_back(pb);
    }

    cout << (int) (dijkstra(adjList, 0) * 1000000);

    return 0;
}

