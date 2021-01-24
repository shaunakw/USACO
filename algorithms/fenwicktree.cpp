#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for (int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

int N = 8;
vector<int> tree(2*N, 0); // stored as layers (top down)

// Gets value at index i
int value(int i) {
    i += N;
    int sum = 0;
    for (; i > 0; i /= 2) {
        sum += tree[i];
    }
    return sum;
}

// Add the same value to a range
void add(int start, int end, int value) {
    start += N;
    end += N;
    while (start <= end) {
        if (start % 2 == 1) tree[start++] += value;
        if (end % 2 == 0) tree[end--] += value;
        start /= 2;
        end /= 2;
    }
}

void print(int layers) {
    int idx = 1;
    fori(i, layers) {
        fori(j, pow(2, layers-1-i)) {
            cout << ' ';
        }
        fori(j, pow(2, i)) {
            cout << tree[idx];
            idx++;
            fori(k, pow(2, layers-i)-1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;
}
