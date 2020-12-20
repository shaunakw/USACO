#include <bits/stdc++.h>

#define fori(i, n) for(int i = 0; i < n; i++)

using namespace std;

int N;
char beads[350];

int floodMod(int num, int den) {
    int mod = num % den;
    return mod < 0 ? den + mod : mod;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    cin >> N;
    fori(i, N) {
        cin >> beads[i];
        cout << beads[i] << endl;
    }

    int maxV = 0;
    fori(i, N) {
        int count = 0;
        char rColor = ' ';
        for (int j = i; j < i + N; j++) {
            char bead = beads[floodMod(j, N)];
            if (rColor == ' ' && bead != 'w') {
                rColor = bead;
            } else if (rColor != bead && bead != 'w') {
                break;
            }
            count++;
        }

        char lColor = ' ';
        for (int j = i - 1; j > i - 1 - N; j--) {
            char bead = beads[floodMod(j, N)];
            if (lColor == ' ' && bead != 'w') {
                lColor = bead;
            } else if (lColor != bead && bead != 'w') {
                break;
            }
            count++;
        }

        maxV = max(maxV, min(count, N));
    }

    cout << maxV;
    
    return 0;
}
