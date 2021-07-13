//============================================================================
// Name        : .cpp
// Author      : Rahul (ATS)
// Version     : 2.0
// cpp version : c++ 14
// Copyright   : Everyone can freely use and distribute it.
// Description : Count frequency of integers  from an given array. 
// T.C         : O(n)-when we use unordered_map<>,,O(nlog(n))- when we use map<>
// A.S         : O(n) - to store map
//============================================================================
#include<bits/stdc++.h>
using namespace std;
//define
// Fast I/O
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
/**
 * This function counts frequency of each element from the array.
 * @param ar input array
 * @param n size of ar[]
 */
void count(int ar[],int n){
    // map to store frequency
    // when we implement the algorithm using map<int,int> then output is always sorted according to key
    // when we implement the algorithm using unordered_map<int,int> then output unordered
    // using any of the above , order of input can not be maintained. 
    map<int,int>mp;

    // count frequency
    for(int i=0;i<n;i++)
        mp[ar[i]]++;

    // print result
    for(auto elem:mp){
        cout<<elem.first<<"->"<<elem.second<<endl;
    }
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
    int ar[10]={5,1,1,1,2,3,5,1,2,1};
    count(ar,10);
	return 0;
}