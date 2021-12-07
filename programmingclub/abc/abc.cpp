#include <bits/stdc++.h>
using namespace std;

int nums[7];

int main() {
    for (int& num : nums) {
        cin >> num;
    }

    sort(nums, nums + 7);

    int a = nums[0];
    int b = nums[1];
    int c = nums[6] - a - b;

    cout << a << " " << b << " " << c << endl;

    return 0;
}

