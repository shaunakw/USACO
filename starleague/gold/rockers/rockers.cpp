#include <bits/stdc++.h>

#define fori(i, a) for(int i = 0; i < a; ++i)
#define trav(i, a) for(auto& i : a)

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
}

int N, T, M, songs[20];

bool checkbit(int n, int bit) {
    return n & (1 << bit);
}

int main() {
    setIO();
    cin >> N >> T >> M;
	
    fori(i, N) cin >> songs[i];

    int max = pow(2, N);
    int res;
    fori(i, max) {
        int disk = 1;
        int space = T;
        int fit = 0;
        fori(j, N) {
            if (checkbit(i, j) || songs[j] > T) continue;
            if (songs[j] <= space) {
                space -= songs[j];
            } else if (disk == M) {
                break;
            } else {
                disk++;
                space = T - songs[j];
            }
            fit++;
        }
        res = std::max(res, fit);
    }
    cout << res;
    
    return 0;
}
