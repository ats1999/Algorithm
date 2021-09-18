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
        int n; cin>>n;
        unordered_map<int,int>map;
        for(int i=0; i<n; i++){
            int temp; cin>>temp;
            map[temp]++;
        }

        long long total = n*1ll*(n-1);
        for(auto pair:map){
            if(pair.second >= 2){
                total -= (pair.second* 1ll * (pair.second-1));
            }
        }

        cout<<total<<endl;
    }
    return 0;
}