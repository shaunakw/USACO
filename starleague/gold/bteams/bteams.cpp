#include <bits/stdc++.h>

#define fori(i, end) for (int i = 0; i < end; i++)

using namespace std;

int cows[12];
int skillDiff = INT_MAX;
int total = pow(4, 11);

int minV;
int maxV;

bool combination(int n) {
    int sum[] = {cows[0], 0, 0, 0};
    int count[] = {1, 0, 0, 0};
    for (int i = 1; i < 12; i++) {
        int m = n % 4;
        if (count[m] > 2) return false;
        sum[m] += cows[i];
        count[m]++;
        n /= 4;
    }
    minV = *min_element(sum, sum + 4);
    maxV = *max_element(sum, sum + 4);
    return true;
}

int main() {
    freopen("bteams.in", "r", stdin);
    freopen("bteams.out", "w", stdout);
    fori(i, 12) cin >> cows[i];

    fori(i, total) {
        if (combination(i)) {
            skillDiff = min(skillDiff, maxV - minV);
        }
    }

    cout << skillDiff;

    return 0;
}
