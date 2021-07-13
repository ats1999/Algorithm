//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count the frequency of string.
// T.C         : O()
// A.S         : O()
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * Count the frequency of each name appears the array.
 * Print the frequencies of names in order they appear. 
 * @param str array of names. 
 * @param n size of array.
 */
void count(string names[],int n){
    // crete an hashmap for storing frequencies. 
    unordered_map<string,int>nameFrequency;

    // convert all name into lower case
    // in the example given, Alok and alok is same name. 
    // By default A and a is the two different characters.
    // If we do not convert Alok to alok, it will not match to alok. 
    for(int i=0;i<n;i++)
        transform(names[i].begin(),names[i].end(),names[i].begin(),::tolower);

    int j=0;
    for(int i=0;i<n;i++){
        // check if current name is not in the map
        // if it is in the hashmap then do not incremet j
        // if it is not in the hashmap then replace the jtn name with ith name 
        if(nameFrequency.find(names[i])==nameFrequency.end()){
            names[j]=names[i];
            j++;
        }

        // count current name
        nameFrequency[names[i]]++;
    }
    for(int i=0;i<j;i++)
        cout<<names[i]<<"->"<<nameFrequency[names[i]]<<endl;
}
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
    // read input
    cin>>n; 
    string str[20];

    for(int i=0;i<n;i++){
        cin>>str[i];
    }

    // call function
    count(str,n);
	return 0;
}