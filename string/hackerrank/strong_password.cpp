//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : https://www.hackerrank.com/challenges/strong-password/problem
// T.C         : O()
// A.S         : O()
// Note        : must Visit editorial for more info   https://www.hackerrank.com/challenges/strong-password/editorial
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

// cheeck if string is valid
bool isValidString(vector<bool>&valid){
    for(bool b:valid){
        if(!b)
            return false;
    }
    return true;
}
/**
 * The answer is always max(6-n,4-d)  where n is string length and  
 * d is the number of different type of characters that are already present in the input password.
 */
// driver code
int main(){
	cout<<"Started\n";
	// I/O
	IOS;
    #ifndef ONLINE_JUDGE 
	    // For getting input from input.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\input.txt", "r", stdin); 
	    // Printing the Output to output.txt file 
	    freopen("C:\\Users\\Rahul kumar\\desktop\\Algorithm\\output.txt", "w", stdout); 
    #endif 
    int n;
    string str;
    cin>>n>>str;
    // create a boolean array to keep track of type of characters 
    vector<bool>isValid(4,false);

    for(char c:str){
        if(isValidString(isValid))
            break;
        if(isdigit(c))
            isValid[0]=true;
        else if(islower(c))
            isValid[1]=true;
        else if(isupper(c))
            isValid[2]=true;
        else isValid[3]=true;
    }

    int count=0;
    for(bool b:isValid)
        if(b)
            count++;
    if(count==4){
        if(n<6)
            cout<<6-n;
        else cout<<0;
    }else {
        if(n<6)
            cout<<max(4-count,6-n);
        else cout<<4-count;
    }
	return 0;
}