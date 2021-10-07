//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 17
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/OCT21B/problems/ANDSUBAR
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

void preCompute(int ar[],int n) {

}

int main() {
    IOS;
    file_io();

    // pre compute
    int size=10,ar[10];
    memset(ar,0,sizeof ar);
    preCompute(ar,size);
    
    int t;
    cin >> t;
    while (t--) {
    }
    return 0;
}