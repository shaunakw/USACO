#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

int N;


int main() {
    cin >> N;

    vector<pi> portals[2*N+1];
    int c[N];
    fori(i, N) {
        cin >> c[i];
        fori(j, 4) {
            int p; cin >> p;
            portals[p].emplace_back(i, j);
        }
    }

    pi adj[N][4];
    for (int i = 1; i <= 2*N; ++i) {
        adj[portals[i][0].first][portals[i][0].second] = portals[i][1];
        adj[portals[i][1].first][portals[i][1].second] = portals[i][0];
    }

    int cost = 0;
    vector<vector<bool>> visited(N, vector<bool>(4, false));
    priority_queue<pair<int, pi>, vector<pair<int, pi>>, greater<pair<int, pi>>> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
        pair<int, pi> top = pq.top();
        pq.pop();
        if (visited[top.second.first][top.second.second]) continue;
        visited[top.second.first][top.second.second] = true;
        cost += top.first;

        int sw = 0;
        if (top.second.second == 0) sw = 1;
        else if (top.second.second == 2) sw = 3;
        else if (top.second.second == 3) sw = 2;
        vector<pair<int, pi>> curr = {{0, adj[top.second.first][top.second.second]}};
        fori(i, 4) {
            if (i == sw) curr.push_back({0, {top.second.first, i}});
            else if (i != top.second.second) curr.push_back({c[top.second.first], {top.second.first, i}});
        }
        trav(i, curr) {
            if (!visited[i.second.first][i.second.second]) pq.push(i);
        }
    }
    cout << cost;

    return 0;
}
