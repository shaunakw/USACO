#include <bits/stdc++.h>
using namespace std;

#define fori(i, a) for (int i = 0; i < (a); ++i)
#define trav(i, a) for(auto& i : (a))

// Returns length of longest increasing subsequence
int lis(vector<int>& seq) {
    vector<int> sub;
    sub.push_back(seq[0]);

    trav(i, seq) {
        auto it = lower_bound(sub.begin(), sub.end(), i);
        if (it == sub.end()) sub.push_back(i);
        else *it = i;
    }
    return sub.size();
}
