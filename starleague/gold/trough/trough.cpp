#include <bits/stdc++.h>

#define fori(i, a) for(int i = 0; i < a; i++)
#define trav(i, a) for(auto& i : a)

using namespace std;

#define rule pair<bool[20], int>

int N;
int M;
int troughs[20]; // 0 = not sure, 1 = filled, 2 = not filled
list<rule> rules;

int main() {
    cin >> N >> M;
	
    fori(i, M) {
        rule r;
        fori(j, N) {
            char c; cin >> c;
            r.first[j] = c == '1';
        }
        cin >> r.second;
        rules.push_back(r);
    }

    int left1, left2;
    while (left1 != left2) {
        left2 = left1;
        left1 = 0;
        trav(i, rules) {
            int total = 0;
            fori(j, N) {
                if (i.first[j]) {
                    if (troughs[j] == 1) {
                        i.second--;
                        i.first[j] = false;
                    } else if (troughs[j] == 2) {
                        i.first[j] = false;
                    } else {
                        total++;
                    }
                }
            }

            if (total < i.second) {
                cout << "IMPOSSIBLE";
                return 0;
            } else if (total == 0) {
                continue;
            }
            left1++;

            if (total == i.second) {
                fori(j, N) {
                    if (i.first[j]) {
                        if (troughs[j] == 2) {
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                        troughs[j] = 1;
                    }
                }
            } else if (i.second == 0) {
                fori(j, N) {
                    if (i.first[j]) {
                        if (troughs[j] == 1) {
                            cout << "IMPOSSIBLE";
                            return 0;
                        }
                        troughs[j] = 2;
                    }
                }
            }
        }
    }

    string out;
    fori(i, N) {
        if (troughs[i] == 0) {
            cout << "NOT UNIQUE";
            return 0;
        } else if (troughs[i] == 1) {
            out += '1';
        } else {
            out += '0';
        }
    }
    cout << out;

    return 0;
}
