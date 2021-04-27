//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description :
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// driver code
int main(){
	// I/O
	IOS;
    vector<int>v{1,2,2};
    do{
        for(int i:v)
            cout<<i<<" ";
            cout<<endl;
    }while(next_permutation(v.begin(),v.end()));

	return 0;
}