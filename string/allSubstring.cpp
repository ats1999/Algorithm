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
 * This function will print all substring of the given string
 * @param {string} str input string
 */
void printAllSubstring(string str){
    int lenStr = str.length();

    for(int i=0; i<lenStr; i++){
        // iterate over lenStrgth of substrings
        for(int lenSubStr=1; lenSubStr<=lenStr; lenSubStr++){
            for(int j=i; j<lenSubStr; j++){
                cout<<str[j];
            }
            if(i<lenSubStr)
                cout<<", ";
        }
        cout<<endl;
    }
}

// driver code
int main(){
	// I/O
	IOS;

    #ifndef ONLINE_JUDGE 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin);  
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
	// cout<<"Started\n";

    string str;
    cin>>str;

    // call the function
    printAllSubstring(str);
	// cout<<"\nDone:)\n";
	return 0;
}