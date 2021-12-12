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

void addHills(int n, string &ans) {
    ans += "0";
    n--;
    while (n) {
        ans += "010";
        n--;
    }
}

void addValleys(int n, string &ans) {
    ans += "1";
    n--;
    while (n) {
        ans += "101";
        n--;
    }
}
int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string ans = "";
        if (n > m) {
            // start with hills
            ans += "010";
            n--;
        } else {
            // start with valleys
            ans += "101";
            m--;
        }

        while (n && m) {
            if (ans[ans.length() - 1] == '0') {
                // add valley
                ans += "1";
                m--;
            } else {
                // add hill
                ans += "0";
                n--;
            }
        }

        if (n) addHills(n, ans);
        if (m) addValleys(m, ans);
        cout << ans.length() << endl;
        cout << ans << endl;
    }
    return 0;
}