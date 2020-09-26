#include <bits/stdc++.h>

#define fori(i, end) for(int i = 0; i < end; i++)

using namespace std;

int M;
int N;
bool walls[50][50][4];
int roots[2500];
int area[2500];

int root(int i) {
    while (roots[i] != i) {
        i = roots[i];
    }
    return i;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    cin >> M >> N;
    fori(i, N) {
        fori(j, M) {
            int module; cin >> module;
            fori(k, 4) {
                walls[i][j][k] = (module & 1 << k) == 1 << k;
            }
            roots[i * M + j] = i * M + j;
        }
    }

    fori(i, N) {
        fori(j, M) {
            if (j < M - 1 && !walls[i][j][2]) {
                roots[root(i * M + j + 1)] = root(i * M + j);
            }
            if (i < N - 1 && !walls[i][j][3]) {
                roots[root((i + 1) * M + j)] = root(i * M + j);
            }
        }
    }

    fori(i, N * M) area[root(i)]++;

    int count = 0;
    int maxV = 0;
    fori(i, N * M) {
        if (area[i] > 0) {
            count++;
            maxV = max(maxV, area[i]);
        }
    }
    cout << count << endl << maxV << endl;

    fori(i, N) {
        fori(j, M) {
            if (j < M - 1 && walls[i][j][2] && root(i * M + j) != root(i * M + j + 1)) {
                maxV = max(maxV, area[root(i * M + j)] + area[root(i * M + j + 1)]);
            }
            if (i < N - 1 && walls[i][j][3] && root(i * M + j) != root((i + 1) * M + j)) {
                maxV = max(maxV, area[root(i * M + j)] + area[root((i + 1) * M + j)]);
            }
        }
    }
    cout << maxV;
    
    return 0;
}
