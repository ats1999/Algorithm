//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.codechef.com/LRNDSA06/problems/BDGFT
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int t;

void solveInRootNxN(){
        string str; cin>>str; int len = str.length();
        long long count = 0; 
		for(int i=1; i*i+i<=len; i++){
			// check the first i-1 characters
			// in the next pahes calculate it's value
			int cnt1=0,cnt0=0, windowSize = i*i+i;
			for(int j=0; j<windowSize; j++){
				if(str[j] == '0')
					cnt0++;
				else 
					cnt1++;
			}

			// check if first substring of length i is beuitiful
			if(cnt0 == cnt1*cnt1)
				count++;
			
			for(int j=windowSize; j<len; j++){
				// remove the item which is out of windowSize right now
				if(str[j-windowSize] == '0')
					cnt0--;
				else 
					cnt1--;

				// include the new item into the windowSize
				if(str[j] == '0')
					cnt0++;
				else 
					cnt1++;

				if(cnt0 == cnt1*cnt1)
					count++;
			}
		}
		cout<<count<<endl;
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul\\Desktop\\Algorithm\\input.txt", "r", stdin);  
    #endif 
	cin>>t;
	while(t--){
		solveInRootNxN();
	}
	return 0;
}