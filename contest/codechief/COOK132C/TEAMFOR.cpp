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
        int n;
        string S, T;
        cin >> n >> S >> T;

        int both = 0, eng = 0, prog = 0, rem = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '1' && T[i] == '1')
                both++;
            else if (S[i] == '1')
                eng++;
            else if (T[i] == '1')
                prog++;
            else
                rem++;
        }

        int ans = min(prog, eng);
        rem += abs(prog - eng);

        if (both > rem)
        {
            ans += (both + rem) / 2;
        }
        else
        {
            ans += both;
        }

        cout << ans << endl;
    }
    return 0;
}