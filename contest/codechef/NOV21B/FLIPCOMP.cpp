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

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        int to1 = 0, to0 = 0, preCount = 0;
        char prev = 'X';

        for (char c : S) {
            if (c == prev) {
                preCount++;
                continue;
            }
            if (prev == '0') {
                to1 += preCount <= 1 ? preCount : 2;
            }

            if (prev == '1') to0 += preCount <= 1 ? preCount : 2;
            prev = c;
            preCount = 1;
        }

        if (prev == '0') {
            to1 += preCount <= 1 ? preCount : 2;
        }

        if (prev == '1') to0 += preCount <= 1 ? preCount : 2;

        cout << min(to1, to0) << endl;
    }
    return 0;
}