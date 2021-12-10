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
    int temp;
    while (t--) {
        int n, maxFreq = INT_MIN;
        cin >> n;
        unordered_map<int, int> ump;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            ump[temp]++;
            maxFreq = max(maxFreq, ump[temp]);
        }

        if (n == 1 || maxFreq == n) {
            cout << "0" << endl;
            continue;
        }
        
        if (maxFreq < 2) {
            cout << "-1" << endl;
            continue;
        }


        cout << (n - maxFreq + 1) << endl;
    }
    return 0;
}