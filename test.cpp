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
#include <sys/types.h>
#include <unistd.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

<<<<<<< HEAD
int t;
=======
int getCount(vector<int>&pr, int size, int B){
    int start = size, end = pr.size()-1;

    while(start <= end){
        int mid = (start+end)/2;
        
    }
    return 9;
}

int solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    vector<int>pre(A.begin(), A.end());
    for(int i=1; i<A.size(); i++){
        pre[i] = pre[i]+pre[i-1];
    }
    
    cout<<"Prefix: ";
    for(int i:pre){
        cout<<i<<" ";
    }cout<<endl;

    // for(int size=1; size<=A.size(); size++){
        getCount(pre,2,B);
    // }
    return 0;
}
>>>>>>> parent of 6894721... less
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("/home/rahul/Desktop/Algorithm/input.txt", "r", stdin);  
	    freopen("/home/rahul/Desktop/Algorithm/output.txt", "w", stdout); 
    #endif 
	fork(); fork(); cout<<"Yes\n";
	return 0;
}
