#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for(int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

typedef pair<int, int> pi;
typedef vector<int> vi;

const int MOD = 1000000007;
int N;
int x[40], y[40];

double slope(int i, int j) {
    if (x[i] == x[j]) return INT_MAX;
    return ((double) y[i] - y[j]) / (x[i] - x[j]);
}

bool below(int i, int j, int k) {
    double m = slope(i, j);
    return y[k] < m * (x[k] - x[i]) + y[i];
}

bool tricontains(int i, int j, int k, int a) {
    return below(i, j, a) == below(i, j, k) && below(j, k, a) == below(j, k, i) && below(k, i, a) == below(k, i, j);
}

//int dfs(int i, int j, int k) {
//    fori(a, N) {
//        if (a == i || a == j || a == k) continue;
//        if (!tricontains(i, j, k, a)) goto dfsmain;
//    }
//    return 1;
//
//    dfsmain:
//    int perm = 0;
//    fori(a, N) {
//        if (a == i || a == j || a == k) continue;
//
//        int next;
//        int start = 1;
//        int end = 0;
//        if (tricontains(i, j, a, k)) {
//            next = dfs(i, j, a);
//            fori(b, N) {
//                if (b == i || b == j || b == a) continue;
//                if (!tricontains(i, j, k, b)) end++;
//                if (!tricontains(i, j, a, b)) start++;
//            }
//        } else if (tricontains(j, k, a, i)) {
//            next = dfs(j, k, a);
//            fori(b, N) {
//                if (b == k || b == j || b == a) continue;
//                if (!tricontains(i, j, k, b)) end++;
//                if (!tricontains(j, k, a, b)) start++;
//            }
//        } else if (tricontains(k, i, a, j)) {
//            next = dfs(k, i, a);
//            fori(b, N) {
//                if (b == i || b == k || b == a) continue;
//                if (!tricontains(i, j, k, b)) end++;
//                if (!tricontains(k, i, a, b)) start++;
//            }
//        } else continue;
//
//        for (int n = start; n <= end; ++n) {
//            next *= n;
//            next %= MOD;
//        }
//        perm += next;
//        perm %= MOD;
//    }
//
//    return perm;
//}

int main() {
    cin >> N;

    fori(i, N) {
        cin >> x[i] >> y[i];
    }

    int factorial[N+1];
    fori(i, N+1) factorial[i] = i == 0 ? 1 : factorial[i-1]*i;

    int total = 0;
    fori(i, factorial[N]) {
        vi order;
        fori(j, N) {
            int bit = (i % factorial[j+1]) / factorial[j];
            order.insert(order.begin() + bit, j);
        }

        int a = order[0];
        int b = order[1];
        int c = order[2];
        for (int j = 3; j < N; ++j) {
            if (tricontains(a, b, c, order[j])) continue;
            else if (tricontains(a, b, order[j], c)) c = order[j];
            else if (tricontains(a, c, order[j], b)) b = order[j];
            else if (tricontains(b, c, order[j], a)) a = order[j];
            else goto end;
        }
        total++;
        end:;
    }

//    fori(i, N) {
//        fori(j, N) {
//            fori(k, N) {
//                if (i == j || j == k || i == k) continue;
//
//                int perm = dfs(i, j, k);
//                int start = N - 2;
//                fori(a, N) {
//                    if (a == i || a == j || a == k) continue;
//                    if (tricontains(i, j, k, a)) start--;
//                }
//                for (int n = start; n <= N - 3; ++n) {
//                    perm *= n;
//                    perm %= MOD;
//                }
//                total += perm;
//                total %= MOD;
//            }
//        }
//    }
    cout << total%MOD;

    return 0;
}
