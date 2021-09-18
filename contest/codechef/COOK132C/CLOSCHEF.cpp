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
        int n, temp;
        cin >> n;

        int negativeOnes = 0, greaterOnes = 0, zeros = 0, ones = 0;
        int greaterOne;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;

            if (abs(temp) > 1)
            {
                greaterOnes++;
                greaterOne = temp;
            }

            if (temp == -1)
                negativeOnes++;

            if (temp == 0)
                zeros++;

            if (temp == 1)
                ones++;
        }

        if (greaterOnes > 1 || (negativeOnes && greaterOnes) || (negativeOnes > 1 && !ones))
        {
            cout << 0 << endl;
            continue;
        }

        cout << 1 << endl;
    }
    return 0;
}