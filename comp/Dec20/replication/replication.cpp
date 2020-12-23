#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

int N, D;

vector<pi> start;
bool grid[1000][1000];

bool valid(pi p, int size) {
    if (size < 1) return true;
    for (int i = -size; i <= size; ++i) {
        if (!grid[p.first+i][p.second+abs(i)-size] || !grid[p.first+i][p.second+size-abs(i)]) return false;
    }
    return true;
}

vector<vector<bool>> bfs(pi curr) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<bool>> covered(N, vector<bool>(N, false));
    queue<pair<pi, int>> q; // point, time
    q.push({curr, 0});
    while (!q.empty()) {
        pair<pi, int> top = q.front();
        pi p = top.first;
        q.pop();
        if (visited[p.first][p.second]) continue;
        visited[p.first][p.second] = true;
        int size = max((top.second-1) / D, 0);
        if (!valid(p, size)) continue;
        for (int i = -size; i <= size; ++i) {
            if (grid[p.first+i][p.second+abs(i)-size]) covered[p.first+i][p.second+abs(i)-size] = true;
            if (grid[p.first+i][p.second-abs(i)+size]) covered[p.first+i][p.second+size-abs(i)] = true;
        }
        if (top.second % D == 0) {
            size = top.second == 0 ? 0 : size + 1;
            if (!valid(p, size)) continue;
            for (int i = -size; i <= size; ++i) {
                if (grid[p.first+i][p.second+abs(i)-size]) covered[p.first+i][p.second+abs(i)-size] = true;
                if (grid[p.first+i][p.second-abs(i)+size]) covered[p.first+i][p.second+size-abs(i)] = true;
            }
        }
        if (grid[p.first - 1][p.second]) q.push({{p.first - 1, p.second}, top.second + 1});
        if (grid[p.first + 1][p.second]) q.push({{p.first + 1, p.second}, top.second + 1});
        if (grid[p.first][p.second - 1]) q.push({{p.first, p.second - 1}, top.second + 1});
        if (grid[p.first][p.second + 1]) q.push({{p.first, p.second + 1}, top.second + 1});
    }
    return covered;
}

int main() {
    cin >> N >> D;
	fori(i, N) {
	    string row; cin >> row;
	    fori(j, N) {
            if (row[j] == '#') grid[i][j] = false;
            else {
                grid[i][j] = true;
                if (row[j] == 'S') start.emplace_back(i, j);
            }
	    }
	}

    vector<vector<bool>> covered(N, vector<bool>(N, false));
	trav(i, start) {
	    auto c = bfs(i);
	    fori(j, N) fori(k, N) if (c[j][k]) covered[j][k] = true;
	}
	int total = 0;
	fori(i, N) {
	    fori(j, N) {
//	        cout << covered[i][j];
	        if (covered[i][j]) total++;
	    }
//	    cout << endl;
	}
	cout << total;
    
    return 0;
}
