//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://leetcode.com/problems/find-the-duplicate-number/
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// find duplicates in the array
int duplicateNum(vector<int>& nums){
	
	return 5282;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	int T,n;
	cin>>T;
	
	while(T--){
		cin>>n;
		
		vector<int>nums(n);
		
		for(int i=0; i<n; i++) {
			int num; cin>>num;
			nums[i] = num;
		}
		cout<<duplicateNum(nums)<<endl;
	}
	cout<<"\nDone:)\n";
	return 0;
}

