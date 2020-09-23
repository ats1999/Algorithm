//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : given a list  of strings si compute hash for each string...
// T.C         : O()
// A.S         : O()
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

const int M = 10; // given in the problem
const int p = 31;
const int m = 1e+9;
long long int p_pow[M];

/**
 *  This function does precomputation for p%m, p^2%m, p^3%m, ...
 */
void compute_p_pow(){
	p_pow[0] = 1;
	for(int i = 1; i <= M; i++){
		p_pow[i] = (p_pow[i-1]*p)%m;
	}
}
/**
 * @param -{s} input string
 * @return {int} hash value  of s
 */
long  long int hashStr(string s){
	int len = s.length();
	long long hash_value = 0;
	for(int i=0;i<len; i++){
		hash_value += ((s[i] - 'a')*p_pow[i])%m;
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
	compute_p_pow();
	int n;
	vector<string>str_ar;
	long long int hash_ar[n];
	cin>>n;
	for(int i=0;i<n;i++){
		string input_str;
		cin>>input_str;
		str_ar.push_back(input_str);
		cout<<str_ar[i]<<endl;
		hash_ar[i] = hashStr(str_ar[i]);
	}
	
	for(int i=0;i<n;i++){
		cout<<str_ar[i]<<"->";
		cout<<hash_ar[i]<<endl;
	}
	cout<<"\nDone:)\n";
	return 0;
}

