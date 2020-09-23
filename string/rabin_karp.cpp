//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Implemention of Rabin-Karp algorithm for pattern matching.
// T.C         : O(n-m+1) - n is size of text, m is size of patern.
// A.S         : O(1)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

int const P = 31;
int const M = 1e9+9;
int const MAX_STRING_LENGTH = 20;
int p_pow[MAX_STRING_LENGTH];
void print(string str, int l, int j){
	for(int i=l; i<=j; i++)
	cout<<str[i];
}
/**
 * @param -{s} input string
 * @return {int} hash value  of s
 */
long long hashStr(string  pattern){
	long long hash_value =0;
	for(int i=0; i<pattern.length(); i++){
		hash_value += (pattern[i] - 'a'+1) * p_pow[i] % M;
	}
	return hash_value;
}
/**
 * @param {text} - text which is to be matched against pattern
 * @param {pattern} - 
 * @return {bool} - true iff pattern is inside text, false otherwise
 */
bool matchPattern(string text, string pattern){
	// calculate lengths
	int t = text.length(),p=pattern.length();
	long long hash_pattern = hashStr(pattern);
	long long hash_sub_str = 0;
	// process first p characters
	
	for(int i=0; i<p; i++){
		hash_sub_str += (text[i] - 'a'+1) * p_pow[i]%M;
	}
		
	if(hash_sub_str == hash_pattern)
		return true;
	 
	for(int i=1; i<t-p+1; i++){
		// subtract hash of the character which is not the part of current sub string
		hash_sub_str -= (text[i-1] - 'a'+1) * p_pow[0] % M;
		hash_sub_str /= P;
		// add hash of new character of substring
		hash_sub_str += (text[i+p-1] - 'a'+1) * p_pow[p-1] % M;
		
		if(hash_sub_str == hash_pattern)
		return true;
	}
	return false;
}

// helper function to calculate p^1, p^2, p^3...
void p_pow_compute(){
	p_pow[0] = 1;
	for(int i=1; i<=MAX_STRING_LENGTH; i++){
		p_pow[i] = (P*p_pow[i-1])%M;
	}
}
// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);
    #endif
	cout<<"Started\n";
	p_pow_compute();
	
	int T;
	cin>>T;
	string text,pattern;
	cin>>text;
	cout<<"Text is: "<<text<<endl;
	while(T--){
		cin>>pattern;
		if(matchPattern(text,pattern))
			cout<<"Matched : "<<pattern<<endl;
		else cout<<"No Match : "<<pattern<<endl;
	}
	cout<<"\nDone:)\n";
	return 0;
}

