//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/NOV21B/problems/MAKEPAL
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
        int n, temp;
        cin >> n;

        int numOds = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;

            if (temp % 2 != 0) numOds++;
        }

        // a palindrome can contain maximum of 1 odd length character sequence
        // so, if we more less than or equal to 1 character sequence then 0 will
        // be the answer

        // if we have more than 1 and odd number of odd character sequence then
        // answer will be (total-1)/2 if we have more than 1 and even number of
        // odd character sequence then ansswer will be total/2

        cout << (numOds / 2) << endl;
    }
    return 0;
}