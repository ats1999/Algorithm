//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/problems/PRB01
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

bool isPrime(int n) {
    if (n <= 1) return false;

    if (n == 2) return true;

    int sq = sqrt(n);

    for (int i = 2; i <= sq; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        cout<<(isPrime(n)?"yes":"no")<<endl;
    }
    return 0;
}