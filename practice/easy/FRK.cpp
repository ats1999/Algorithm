//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/problems/FRK
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
    int ans = 0;

    vector<string> subStrOfChef({"ch", "he", "ef", "che", "hef", "chef"});

    while (t--) {
        string u;
        cin >> u;
        for (string subStr : subStrOfChef) {
            if (u.find(subStr) != string::npos) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}