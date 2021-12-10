//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description :
// https://leetcode.com/problems/final-ar-with-a-special-discount-in-a-shop
// T.C         : O(n)
// A.S         : O(n)
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

vector<int> nextSmaller(vector<int> ar) {
    stack<int> S;
    for (int i = ar.size() - 1; i >= 0; i--) {
        if (S.empty()) {
            S.push(ar[i]);
            continue;
        }

        while (!S.empty() && S.top() > ar[i]) S.pop();

        int cur = ar[i];
        if (!S.empty()) {
            ar[i] -= S.top();
        }
        S.push(cur);
    }
    return ar;
}
int main() {
    IOS;
    file_io();
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans = nextSmaller(v);

    for (int el : ans) cout << el << " ";
    return 0;
}