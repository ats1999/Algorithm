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

void uniqueSubset(vector<int>&ar,map<vector<int>,int>&res, int n){
    for(int i=0; i<(1<<n); i++){
        vector<int>cur;
        for(int j=0; j<32; j++){
            if(i&(1<<j))
                cur.push_back(ar[j]);
        }
        res[cur]++;
    }
}
// driver code
int main(){
    vector<int>v{ 6, 6, 3, 3, 6, 5 };
    sort(v.begin(),v.end());
    map<vector<int>,int>res;
    uniqueSubset(v,res,6);
    vector<vector<int>>result;
    for(auto v:res){
        //vector<int>temp(v.first.begin(),v.first.end());
        //sort(temp.begin(),temp.end());
        //result.push_back(temp);

        result.push_back(v.first);
    }

    sort(result.begin(), result.end());

    for(auto v:result){
        for(int i:v)
            cout<<i<<" ";
        cout<<endl;
    }
	return 0;
}