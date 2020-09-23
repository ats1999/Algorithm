//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : You are given  a text  T(abcdefghi....) and a pattern p (def..)
//				- you have to find wheather pattern p is inside text  t or not.
// T.C         : O(T*P) - T is size of Text and P is size of pattern
// A.S         : O(1)
//============================================================================

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * @param {text} - text which is to be matched against pattern
 * @param {pattern} - 
 * @return {bool} - true iff pattern is inside text, false otherwise
 */
bool matchPattern(string text, string pattern){
	// calculate lengths
	int t = text.length(),p = pattern.length();
	
	// for each substring of text of length p
	// try to match pattern
	for(int i=0; i<t-p+1; i++){
		bool patternMatched = true;
		
		for(int  j=0; j<p; j++){
			
			// if pattern is not equal to current substring then go with next substring
			if(text[j+i] != pattern[j]){
				patternMatched = false;
				break;
			}
		}
		
		// if pattern matched then return true...
		if(patternMatched) return true;
	}
	return false;
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

