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


int main(){
	// I/O
	IOS;
    int ar[] = {1,2,3,2,6,8,4,6};
    int len = 8;
    unordered_map<int,int>ump;
    
    for(int i=0; i<len; i++)
        ump[ar[i]]++;

    int idx = 0;
    for(auto var:ump){
        if(var.second >= 2)
            continue;
        ar[idx++] = var.first;
    }

    for(int i=0; i<idx; i++)
        cout<<ar[i]<<" ";
	return 0;
}
