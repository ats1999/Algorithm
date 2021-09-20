//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/START11C/problems/BIGARRAY
// T.C         : O()
// A.S         : O()
//============================================================================

#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

void file_io()
{
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

int main()
{
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;

        long long sum = (n * 1ll * (n + 1)) / 2;
        long long val = sum - s;
        if (val > 0 && val <= n)
            cout << val << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}