#include <bits/stdc++.h>

using namespace std;

// Returns vector of shortest distance to each node
vector<int> dijkstra(vector<vector<pair<int, int>>>& adjList, int source) {
    vector<int> distances(adjList.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[source] = 0;
    pq.push({0, source}); // { distance, node }

    while (!pq.empty()) {
        pair<int, int> closest = pq.top();
        pq.pop();
        if (closest.first > distances[closest.second]) continue;

        for (auto& i : adjList[closest.first]) {
            if (distances[i.first] > distances[closest.first] + i.second) {
                distances[i.first] = distances[closest.first] + i.second;
                pq.push({distances[i.first], i.first});
            }
        }
    }
    return distances;
}
