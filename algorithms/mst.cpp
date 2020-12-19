#include <bits/stdc++.h>

using namespace std;

// Returns cost of weighted MST
int mst(vector<vector<pair<int, int>>>& adjList) {
    vector<bool> visited(adjList.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // { distance, node }

    int cost = 0;
    while (!pq.empty()) {
        pair<int, int> closest = pq.top();
        pq.pop();
        if (visited[closest.second]) continue;

        visited[closest.second] = true;
        cost += closest.first;
        for (auto& i : adjList[closest.second]) {
            if (!visited[i.first]) pq.push({i.second, i.first});
        }
    }
    return cost;
}