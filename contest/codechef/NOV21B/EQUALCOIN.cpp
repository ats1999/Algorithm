//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/NOV21B/problems/EQUALCOIN
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

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        if ((y == 0 && x % 2 == 0) || (x == 0 && y % 2 == 0)) {
            cout << "YES\n";
            continue;
        }
        if ((y == 0 && x % 2 != 0) || (x == 0 && y % 2 != 0)) {
            cout << "NO\n";
            continue;
        }
        if (x % 2 == 0 && (x + (2 * y)) % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}