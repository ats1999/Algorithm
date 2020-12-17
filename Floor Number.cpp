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

	int T,n,x;
	cin>>T;
	while(T--){
		cin>>n>>x;
		if(n<=2){
			cout<<1<<endl; continue;
		}
		
		cout<<(ceil(float(n-2)/x)+1)<<endl;
	}
	return 0;
}

