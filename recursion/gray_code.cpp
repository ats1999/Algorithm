//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://en.wikipedia.org/wiki/Gray_code
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int t;

void grayCode(int n,vector<int>&res){
    if(n==1){
        res.push_back(0);
        res.push_back(1);
        return;
    }
    grayCode(n-1,res);
    int size = res.size();
    int pw = 1<<(n-1);
    for(int i=size-1; i>=0; i--){
        res.push_back(pw+res[i]);
    }
}
// driver code
int main(){
	// I/O
	IOS;

    int n; cin>>n;
    vector<int>res;
    grayCode(n,res);
    for(int a:res){
        cout<<a<<" ";
    }
	return 0;
}