#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for (int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

// Returns order of topological sort
vector<int> topSort(vector<vector<int>>& adjList) {
    int size = adjList.size();
    vector<int> inDegrees(size, 0);

    trav(i, adjList) {
        trav(j, i) inDegrees[j]++;
    }

    queue<int> q;
    fori(i, size) {
        if (inDegrees[i] == 0) q.push(i);
    }

    vector<int> sorted;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        sorted.push_back(top);

        trav(i, adjList[top]) {
            inDegrees[i]--;
            if (inDegrees[i] == 0) q.push(i);
        }
    }

    return sorted;
}
