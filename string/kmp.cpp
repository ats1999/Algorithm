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


/**
 * Print pi table for KMP algorithm using fast algorithm.
 * O(n)
 * @param {str} 
 */
vector<int> piTable(string str){
	int s = str.length();
	vector<int>pi(s);
	pi[0] = 0;
	
	for(int i=1; i<s; i++){
		int j = pi[i-1];
		
		while(j>0 &&  str[j] != str[i])
			j = pi[j-1];
			
		if(str[i] == str[j])
			j++;
		pi[i] = j;
	}
	for(int i:pi)
		cout<<i<<" "; cout<<endl;
	return pi;
}

/**
 * Print pi table for KMP algorithm using naive algorithm.
 * O(n^3)
 * @param {str} 
 */
void kmpPiNaive(string str){
	int s = str.length();
	vector<int>pi(s);
	
	for(int i=0; i<s; i++){
		for(int j=0; j<=i; j++){
			if(str.substr(0,j) == str.substr(i-j+1,j)) // this is O(n) operation
				pi[i] = j;
		}
	}
	
	for(int i:pi)
		cout<<i<<" ";
}

/**
 * @param {text} - 
 * @param {pattern} - 
 * @return {bool} - true if string matches, false otherwise
 */
vector<int> KMP(string  text, string pattern){
	vector<int>pi = piTable(pattern);
	int  t = text.length(), p = pattern.length();
	vector<int>matched_index;
	int i = 0,j=0;
	while(i<t){
		// if current character matched then advance both pointer
		if(pattern[j] == text[i]){
			i++; j++;
		}else if(j!=0) j = pi[j-1];
		
		// if j == p then pattern have been found in the text, store it's indecies
		if(j==p){
			matched_index.push_back(j);
			j = pi[j-1];
		}		
	}
	return matched_index;
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
	string text;	cin>>text;
	while(T--){
		cout<<"_-------------_------------_--------_--------_\n";
		string pattern;
		cin>>pattern;
		
		cout<<"Text: "<<text<<endl; 
		cout<<"Pattern: "<<pattern<<endl;
				
		vector<int>matched_index = KMP(text,pattern);
		if(matched_index.size() == 0)
			cout<<"Pattern not found\n";
		for(int i:matched_index)
			cout<<i<<"\n";
	}
	cout<<"\nDone:)\n";
	return 0;
}

