#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

void file_io() {
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

// [4,5,8,6,9,10,5] - 10,9
int main() {
    IOS;
    file_io();
    vector<int> ar{4,5,8,6,9,10,5};
    int max1 = INT_MIN, max2 = INT_MIN;

    for (int i = 0; i < ar.size(); i++) {
        if (ar[i] > max1) {
            max2 = max1;
            max1 = ar[i];
        } else if (ar[i] > max2 && ar[i] != max1) {
            max2 = ar[i];
        }
    }

    cout << "Max1 " << max1 << endl;
    cout << "Max2 " << max2 << endl;
    return 0;
}