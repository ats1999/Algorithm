//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/DEC21B/problems/VANDH
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
        int n, m;
        cin >> n >> m;

        if (n == m && n == 1) {
            cout << "1010\n";
            continue;
        }

        if (n == m) {
            string init = "1010";
            while (--n > 0) {
                init += "10";
            }
            cout << init << endl;
            continue;
        }

        string result(m + n + 2, '0');
        if (n > m) {
            for (int i = 0; i < (m + n + 2); i += 2) result[i] = '0';
            for (int i = 1; i < (m + n + 2); i += 2) result[i] = '1';
        } else {
            for (int i = 0; i < (m + n + 2); i += 2) result[i] = '1';
            for (int i = 1; i < (m + n + 2); i += 2) result[i] = '0';
        }

        cout << result << endl;
    }
    return 0;
}