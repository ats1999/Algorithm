//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================

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

int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
    int waterA = capacityA, waterB = capacityB;

    int posA = 0, posB = plants.size() - 1;

    int count = 0;
    while (posA <= posB) {
        if (posA == posB) {
            if (plants[posA] > waterA && plants[posB] > waterB) count++;
            break;
        }

        if (plants[posA] > waterA) {
            waterA = capacityA;
            count++;
        }

        if (plants[posB] > waterB) {
            waterB = capacityB;
            count++;
        }

        waterA -= plants[posA];
        waterB -= plants[posB];

        posA++;
        posB--;
    }
    return count;
}
int main() {
    IOS;
    file_io();
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << minimumRefill(v, a, b);
    return 0;
}