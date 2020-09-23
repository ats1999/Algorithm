//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Compute hash value of the given string..
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

/**
 * @param -{s} input string
 * @return {int} hash value  of s
 */
long long int hashStr(string const& s){
	const int p = 31;
	const int m = 1e+9;
	long long hash_value = 0;
	long long p_pow = 1;
	
	for(char c:s){
		hash_value += ((c-'a')*p_pow)%m; 
		p_pow = (p*p_pow)%m;
	}
	return hash_value;
}
// driver code
int main(){
	// I/O
	IOS;
	#ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
    
	cout<<"Started\n";
	string str;
	int n;
	cin>>n;
	while(n--){
	cin>>str;
	cout<<str<<"->"<<hashStr(str)<<endl;
		
	}
	cout<<"\nDone:)\n";
	return 0;
}

