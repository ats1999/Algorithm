//============================================================================
// Name        : Subtract big integers
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

/**
 * Subtract two big integers a and b, then return the result
 * @param {string} a
 * @param {string} b
 * @return {string} and subtraction of a and b
 */
string subBigInts(string a, string b){
    // construct array of integers
    vector<int>a_int,b_int;
    for(char c:a)
        a_int.push_back(c-'0');
    for(char c:b)
        b_int.push_back(c-'0');
    
    // reverse the arrays
    reverse(a.begin(), b.end());
    reverse(b_int.begin(), b_int.end());

    
    return "";
}
int main(){
    IOS; file_io(); int t; cin>>t;

    // a and b are two input numbers
    string a, b;
    while(t--){
        cin>>a>>b;
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}