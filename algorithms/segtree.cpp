#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for (int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

int N = 8;
vector<int> tree(2*N, 0); // stored as layers (top down)

// Returns sum of a range of values
int range(int start, int end) {
    start += N;
    end += N;
    int sum = 0;
    while (start <= end) {
        if (start % 2 == 1) sum += tree[start++];
        if (end % 2 == 0) sum += tree[end--];
        start /= 2;
        end /= 2;
    }
    return sum;
}

// Adds an amount to index i
void add(int i, int value) {
    i += N;
    for (; i > 0; i /= 2) {
        tree[i] += value;
    }
}
