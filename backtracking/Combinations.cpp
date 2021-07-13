//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Given two integers A and B, return all possible combinations of B numbers out of 1 2 3 ... A .
// input/output
/*
 A = 3
 B = 2

 [
  [1, 2],
  [1, 3],
  [2, 3]
 ] 
*/

// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

void combinations(int a, int b,int i, vector<int>&cur,vector<vector<int>>&res){
    if(cur.size() == b){
        vector<int>vect(cur.begin(),cur.end());
        sort(vect.begin(),vect.end());
        res.push_back(vect);
        return;
    }

    for(int j=i;j<=a; j++){
        cur.push_back(j);
        combinations(a,b,j+1,cur,res);
        cur.pop_back();
    }
}
int t;
// driver code
int main(){
	// I/O
	IOS;
    vector<int>cur;
    vector<vector<int>>res;
    combinations(4,2,1,cur,res);
    sort(res.begin(),res.end());

    for(auto vect:res){
        for(int a:vect)
            cout<<a<<" ";
        cout<<endl;
    }
	return 0;
}