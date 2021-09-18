//============================================================================
// Name        :
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use, contribute and distribute it.
// Description : https://www.codechef.com/LTIME98C/problems/REDALERT
// T.C         : O()
// A.S         : O()
//============================================================================

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

void file_io(){
#ifndef ONLINE_JUDGE
    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);
    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout);
#endif
}

int main(){
    IOS; file_io(); int t; cin>>t;
    while(t--){
        int n,d,h; cin>>n>>d>>h;
        int ar[n];

        for(int i=0; i<n; i++) cin>>ar[i];

        int total = 0;
        bool isRedAlter = false;
        for(int i=0; i<n; i++){
            if(ar[i] == 0){
                total = max(0, total-d);
                continue;
            }

            total += ar[i];

            if(total > h){
                isRedAlter = true;
            }
        }

        if(isRedAlter)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}