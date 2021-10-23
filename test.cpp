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

int maxSubArray1(const vector<int> &A) {
    // initially initialize maximum as minimum
    int maxSum = INT_MIN;

    for(int i=0; i<A.size(); i++){
        for(int j=i; j<A.size(); j++){
            // for every sub array calculate the sub array sum
            // them compare it with maxSum and update maxSum as maximum of maxSum and curSum
            int curSum = 0;

            for(int k=i; k<= j; k++){
                curSum += A[k];
            }
            
            // update maxSum
            maxSum=max(maxSum,curSum);
        }
    }
    return maxSum;
}

int maxSubArray2(const vector<int> &A) {
    // initially initialize maximum as minimum
    int maxSum = INT_MIN;

    for(int i=0; i<A.size(); i++){
        int subArraySum = 0;
        for(int j=i; j<A.size(); j++){
            subArraySum += A[j];
            maxSum = max(maxSum,subArraySum);
        }
    }
    return maxSum;
}

int maxSubArray(const vector<int> &A) {
    int curSum = 0, bestSum = A[0];
    for(int num:A){
        curSum = max(0, curSum+num);
        bestSum = max(bestSum,curSum);
    }
    return bestSum;
}

int main() {
    IOS;
    file_io();
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int>ar(n);
        
        for(int i=0; i<n; i++)
            cin>>ar[i];

        cout<<maxSubArray(ar);
    }
    return 0;
}