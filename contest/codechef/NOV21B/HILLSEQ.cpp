//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/NOV21B/problems/HILLSEQ
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

void printAr(int ar[], int n) {
    for (int i = 0; i < n; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ar[n], result[n];
        for (int i = 0; i < n; i++) {
            cin >> ar[i];
        }

        sort(ar, ar + n);

        // array of size 1
        if (n == 1) {
            cout << ar[0] << endl;
            continue;
        }

        // the maximum number should be unique
        if (ar[n - 1] == ar[n - 2]) {
            cout << (-1) << endl;
            continue;
        }

        int resIdx = 0;
        unordered_map<int, int> ump;
        bool dup3Times = false;

        for (int i = 1; i < n; i++) {
            ump[ar[i]]++;

            if (ump.find(ar[i]) != ump.end() && ump[ar[i]] == 3) {
                dup3Times = true;
                break;
            }

            if (ar[i] == ar[i - 1]) {
                result[resIdx] = ar[i];
                resIdx++;
                ar[i] = -1;
            }
        }

        // if there is more than 3 duplicates, then answer will be -1
        if (dup3Times) {
            cout << (-1) << endl;
            continue;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (ar[i] == -1) continue;

            result[resIdx] = ar[i];
            resIdx++;
        }

        printAr(result, n);
    }
    return 0;
}