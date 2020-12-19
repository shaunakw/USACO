#include <bits/stdc++.h>

using namespace std;

// Returns order of topological sort
vector<int> topSort(vector<vector<int>>& adjList) {
    int size = adjList.size();
    vector<int> inDegrees(size, 0);

    for (auto& i : adjList) {
        for (auto& j : i) inDegrees[j]++;
    }

    queue<int> q;

    for (int i = 0; i < size; i++) {
        if (inDegrees[i] == 0) q.push(i);
    }

    vector<int> sorted;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        sorted.push_back(top);

        for (int& i : adjList[top]) {
            inDegrees[i]--;
            if (inDegrees[i] == 0) q.push(i);
        }
    }

    return sorted;
}
