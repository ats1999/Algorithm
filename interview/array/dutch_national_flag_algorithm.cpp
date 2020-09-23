//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://leetcode.com/problems/sort-colors/
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// https://en.wikipedia.org/wiki/Dutch_national_flag_problem
void dutch_algo(vector<int>&nums){
	for(int i:nums){
		cout<<i<<" ";
	}cout<<endl;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>nums;
		while(n--){
			int  t;
			cin>>t;
			nums.push_back(t);
		}
		dutch_algo(nums);
	}
	cout<<"\nDone:)\n";
	return 0;
}

