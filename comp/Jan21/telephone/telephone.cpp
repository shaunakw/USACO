#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef vector<int> vi;
typedef pair<int, int> pi;

int N, K;
int cows[50000];
int dp[50000][50];
bool comm[50][50];
vector<bool> visited;

int dfs(int i, int dist) {
    visited[i] = true;
    if (comm[cows[i]][cows[N - 1]]) return dist + (N - 1 - i);

    int ans = 1000000;
    trav(j, dp[i]) {
        if (j >= K || visited[j] || j == 1000000) continue;
//        cout << j;
        int k = dfs(j, dist + abs(i - j));
        if (k != -1) ans = min(ans, k);
    }
    return ans;
}

int main() {
    cin >> N >> K;
	vector<int> breeds[K];
	visited.resize(N, false);

	fori(i, N) {
	    int breed; cin >> breed;
	    cows[i] = breed - 1;
	    breeds[breed-1].push_back(i);
	}

	fori(i, K) {
	    string row; cin >> row;
	    fori(j, K){
	        comm[i][j] = row[j] == '1';
	    }
	}

	fori(i, N) {
	    fori(j, K) {
            dp[i][j] = 1000000;
	        if (comm[cows[i]][j]) {
	            trav(k, breeds[j]) {
	                if (abs(dp[i][j] - i) > abs(k - i)) dp[i][j] = k;
	            }
	        }
	    }
	}

	cout << dfs(0, 0);

    return 0;
}
