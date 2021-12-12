//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/DEC21B/problems/ROPASCI
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

char W(int winner, string s) {
    for (int i = winner + 1; i < s.length(); i++) {
        if (s[i] == s[winner]) {
            continue;
        }

        if ((s[winner] == 'S' && s[i] == 'R') ||
            (s[winner] == 'R' && s[i] == 'P') ||
            (s[winner] == 'P' && s[i] == 'S')) {
            winner = i;
        }
    }

    return s[winner];
}

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += W(i, s);
        }

        cout << ans << endl;
    }
    return 0;
}