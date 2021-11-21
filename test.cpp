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

bool isPerfect(int n) {
    int sumDiv = 0, sq = ceil(sqrt(n));
    for (int i = 1; i <= sq; i++) {
        if (n % i != 0) continue;

        sumDiv += i;
    }
    return sumDiv == n;
}

int main() {
    for(int i=1; i<=100; i++){
        if(isPerfect(i))
            cout<<i<<" ";
    }
    return 0;
}
