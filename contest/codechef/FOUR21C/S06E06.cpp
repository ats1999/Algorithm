//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description :
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

vector<int> makeDigits(int n) {
    vector<int> digits;

    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    return digits;
}

bool isPossible(vector<int>& digits) {
    for (int d : digits)
        if (d < 9) return true;

    return false;
}

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> digits = makeDigits(n);

        while (k && isPossible(digits)) {
            int minIdx =
                min_element(digits.begin(), digits.end()) - digits.begin();

            digits[minIdx]++;
            k--;
        }
        long long P = 1;
        for (int d : digits) P *= (1ll * d);

        cout<<P<<endl;
    }
    return 0;
}