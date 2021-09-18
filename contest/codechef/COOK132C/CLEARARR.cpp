//============================================================================
// Name        :
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use, contribute and distribute it.
// Description :
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
        long long n, k, x, kUnUsed;
        cin >> n >> k >> x;
        kUnUsed = k;
        long long ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];

        long long totalSum = accumulate(ar, ar + n, 0);
        long long totalSumUsingX = 0;
        sort(ar, ar + n);

        for (int i = n - 1; i >= 1 && (ar[i] + ar[i - 1] > x) && kUnUsed--; i -= 2)
        {
            totalSumUsingX += x;
        }

        long long numbersUsed = (k - max(0ll,kUnUsed)) * 2;
        totalSumUsingX += ((n & 1) && (n - numbersUsed) == 1) ? ar[0] : 0;

        if (numbersUsed >= n - 1)
        {
            cout << min(totalSumUsingX, totalSum) << endl;
            continue;
        }

        for(int i=0; i<=(n-numbersUsed-1); i++)
            totalSumUsingX += ar[i];
        cout << min(totalSumUsingX, totalSum) << endl;
    }
    return 0;
}